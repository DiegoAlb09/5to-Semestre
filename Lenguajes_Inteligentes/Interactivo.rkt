#lang racket

(define (iniciar-conversacion)
  (display "Hola, ¿Como estas?")
  (define respuesta (read-line))
  (cond
    ((string=? respuesta "adios")
     (display "¡Hasta luego!"))
    (else
      (display "¿Como te llamas?")
      (display respuesta)
      (newline)
      (display "Gusto en conocerte")
      (iniciar-conversacion))))

(iniciar-conversacion)
