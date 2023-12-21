(deftemplate problem
  (slot description)
)

(defrule solution1
    (problem (description "Scratches and stains are visible on the scanned image"))
    => 
    (printout t 
"Cause : The scanned original is damaged. Scratches and stains are present on the outer or inner surface of the exposure glass. The monitor sensor is dirty
Solution : Clean the surface of the exposure glass. Clear the scanner sensor" crlf)
)

(defrule solution2
    (problem (description "Part of the image is blurred"))
    => 
    (printout t 
"Cause : The original was not pressed tightly against the surface of the scanner
Solution : Press it tightly" crlf)
)

(defrule solution3
    (problem (description "The edges of the original are missing from the scanned image"))
    => 
    (printout t 
"Cause : The original is incorrectly placed on the scanner exposure glass
Solution : Make sure that the original fully falls within the range of the CCD scanner range" crlf)
)

(defrule solution4
    (problem (description "The scanned image is devoid of content"))
    => 
    (printout t 
"Cause : Make sure that the original image was oriented with the correct side relative to the scanning device of the tablet device or correctly inserted into the receiving tray of the page scanner
Solution : Turn the sheet over with the other side" crlf)
)

(defrule solution5
    (problem (description "The image obtained as a result of the scan is blurry or distorted"))
    => 
    (printout t 
"Cause : The original document does not fit tightly to the working glass surface of the scanner
Solution : Check the tightness of the original document against the working glass surface of the scanner, make sure that the cover the scanner is closed" crlf)
)

(defrule solution6
    (problem (description "The quality of the scanned images is not satisfactory"))
    => 
    (printout t 
"Cause : The settings for the scanning image do not match
Solution : Check whether the settings for the image type correspond to the parameters of the scanning device and its software" crlf)
)

(defrule solution7
    (problem (description "The resulting image contains minor errors – it is slightly skewed, not centered, too dark or, conversely, too light"))
    => 
    (printout t 
"Cause : The sheet on the scanning device was installed crookedly
Solution :Use the scanner software or other graphic image editing program and eliminate these image errors" crlf)
)

(defrule solution8
    (problem (description "The resulting image has a greenish, reddish, yellowish or bluish tint"))
    => 
    (printout t 
"Cause : The intensity of the color balance is incorrectly adjusted
Solution : In the software, in the Color Balance dialog box , adjust the intensity of the balance of the desired color, then scan it again (if this is not possible, then use the correction program" crlf)
)