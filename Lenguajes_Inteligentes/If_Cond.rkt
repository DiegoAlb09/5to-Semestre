#lang racket


(define (suma x)
  (if (< x 2)
    (+ x x) (suma (- x 2))))

(define (parImpar n)
  (cond 
    [(even? n) (display n) "Es par"]
    [else (suma n)]
    ))
          
