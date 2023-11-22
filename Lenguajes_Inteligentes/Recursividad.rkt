#lang racket

(define (factorial n)
  (cond 
    ((= n 0) 1)
    (else (* n (factorial (- n 1))))))

(define (suma-naturales x)
  (cond
    ((= x 0) 0)
    (else (+ x (suma-naturales (- x 1))))))
