<?php

namespace gamma;

require_once("Gamma.php");

$input_string = "Конышев_Артем_Евгеньевич_триста_вторая_группа_первая_подгруппа";
$gamma = new Gamma($input_string);
printf("gamma for \"%s\": %s\n", $input_string, $gamma);
