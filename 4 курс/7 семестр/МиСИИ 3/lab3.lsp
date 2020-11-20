(defun main ()
  (defvar *db* nil)
  
  (insert "Севастополь" "Москва" "1")
  (insert "Евпатория" "Санкт-Петербург" "2")
  (insert "Москва" "Симферополь" "3")
  
  (print "БД после вставки:")
  (select*)
  
  (print "Сохранение в файл...")
  (savef "database.txt")
  (terpri)
  
  (print "Изменим номер маршрута по начальному пункту из Москвы и сохраним в файл:")
  (update (where :start "Москва") :number "99")
  (selectByNumber "99")
  (savef "database.txt")
  
  (terpri)
  (print "Попробуем найти несуществующий маршрут с номер 666:")
  (selectByNumber "666")
  
  (terpri)
  (print "Выгрузка из файла:")
  (loadf "database.txt")
  (select*)
  )

(defun insert (start end number)
  (push (list :start start :end end :number number) *db*)
 )

(defun savef (filename)
  (with-open-file (out filename :direction :output :if-exists :supersede)
    (with-standard-io-syntax
      (print *db* out)
     )
   )
 )

(defun loadf (filename)
  (with-open-file (in filename)
    (with-standard-io-syntax
      (setf *db* (read in))
     )
   )
 )

(defun select* ()
  (format t "~%~{~{~a:~a~%~}~%~}" *db*)
 )

(defun where(&key start end number)
  #'(lambda (row)
       (and 
         (if start (equal (getf row :start) start) t)
         (if end (equal (getf row :end) end) t)
         (if number (equal (getf row :number) number) t)
        )
     )
 )

(defun update (where-func &key start end number)
  (setf *db*
    (mapcar
     #'(lambda (row)
         (when (funcall where-func row)
           (if start (setf (getf row :start) start))
           (if end (setf (getf row :end) end))
           (if number (setf (getf row :number) number))
          )
         row
          )
      *db*
     )
   )
 )

(defun selectByNumber (_number)
  (if (eq nil (setf rows (remove-if-not #'(lambda (row) (equal (getf row :number) _number)) *db*)))
      (print "Такого маршрута нет!")
      (print rows)
   )
  )