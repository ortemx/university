<?php
	//var_dump($_POST) ;
	$filename = 'Saransk2018.jpg';
	$img = imagecreatefromjpeg($filename); 
	header('Content-type: image/jpeg');
	imagefilter($img, IMG_FILTER_CONTRAST, $_GET['param']);
	imagejpeg($img, null);
	imagedestroy($img);
?>