(deftemplate problem
  (slot name)
)

(defrule sol1
    (problem (name "no TV signal"))
    => 
    (printout t "There is no contact between the TV plug and the antenna socket of the TV.Check the reliability of the connection." crlf)
)

(defrule sol2
    (problem (name "bad image"))
    => 
    (printout t "The TV plug is defective, incorrectly installed, or not fully inserted into the socket." crlf)
)