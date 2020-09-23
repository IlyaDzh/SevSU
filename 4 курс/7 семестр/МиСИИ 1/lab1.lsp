(defun F (myList)
    (if myList
        (if (< (cadr myList) 0) (cdr myList) (reverse (cdr (reverse myList))))
    )
)

(princ "С отрицательным элементом: ")
(print (F `(1 -2 4 5 9 0 -3 -10 4)))
(terpri)
(princ "С положительным элементом: ")
(print (F `(1 2 4 5 9 0 -3 -10 4)))

(terpri)
(terpri)

(defun F1 (x y z)
    (setq myList (list x y z))
    (if myList
        (if (< (cadr myList) 0) (cdr myList) (reverse (cdr (reverse myList))))
    )
)

(princ "С отрицательным элементом: ")
(print (F1 1 -2 4))
(terpri)
(princ "С положительным элементом: ")
(print (F1 1 2 4))