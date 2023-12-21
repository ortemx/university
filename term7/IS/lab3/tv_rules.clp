(deftemplate problem
  (slot description)
)

(defrule solution1
    (problem (description "no TV signal"))
    => 
    (printout t "There is no contact between the TV plug and the antenna socket of the TV.Check the reliability of the connection." crlf)
)

(defrule solution2
    (problem (description "bad image"))
    => 
    (printout t "The TV plug is defective, incorrectly installed, or not fully inserted into the socket." crlf)
)