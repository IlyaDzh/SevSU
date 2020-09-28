(defun insertSymbolRec (myList x n) 
    (cond 
        ((zerop n) (cons x myList)) 
        (T (cons (car myList) (insertSymbolRec (cdr myList) x (1- n)))) 
    ) 
) 

(princ "Рекурсивная функция:")
(print (insertSymbolRec '(0 1 2 3 4 5 6 7 8 9) 9999 3))

(terpri)

(defun insertSymbolIter (myList x n) 
    (let ((tempList1) (tempList2 myList))
        (loop 
            (cond 
                ((zerop n) (return (append tempList1 (cons x tempList2))))
                (T 
                    (setf tempList1 (append tempList1 (list (car tempList2)))) 
                    (setf tempList2 (cdr tempList2)) (setf n (- n 1)) 
                )
            )
        )
    )
)

(princ "Итерационная функция:")
(print (insertSymbolIter '(0 1 2 3 4 5 6 7 8 9) 9999 3))