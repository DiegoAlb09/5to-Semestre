#lang racket

(define (fibonaci x)
  (cond
    [(= x 0) 0]
    [(= x 1) 1]
    [else (+ (fibonaci (- x 1)) (fibonaci (- x 2)))]))

  