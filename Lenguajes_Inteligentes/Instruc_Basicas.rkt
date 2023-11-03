#lang racket

(let* ( (a 12) (b 2)) (+ a b))

(define (suma n)
  (if (< n 3) (+ n 10) (- n 10)))

(let* ( (s "Hola") (d "Mundo")) (string-append s d))

(let* ( (x 20) (y 2)) (* 10 (/ x y)))

(define (restar n)
  (if (equal? 20 n) (- n 2) (- 2 n)))

(or (> 14 13)(equal? 12 (+ 9 3)))

(let* ( (a "Hola Mundo Dr.Racket") (b 11)) (substring a b))

(let* ( (z "Adios Mundo Dr.Racket")) (string-length z))

(list 1 2 3)

(let* ( (x (list 1 2 3 4 5)) (y (list 6 7 8 9 10))) (cons x y))
