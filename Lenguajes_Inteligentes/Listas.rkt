#lang racket

(define (obtener-cabecera lista)
  (if (null? lista)
      '()
      (car lista)))

(define (obtener-resto lista)
  (if (null? lista)
      '()
      (cdr lista)))

(define (agregar-a-cabecera elemento lista)
  (cons elemento lista))