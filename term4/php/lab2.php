<!DOCTYPE html>
<html>
<head>
    <title>Лабораторная 2</title> 
    <link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
</head>
<body style="font-family:'Montserrat', sans-serif; ">
    <?php
    srand(time());
    echo <<< border
    <h2 align='center'>Задание 1</h2>
    <form method="POST">
        n: <input type="text" name="n1"><br>
        <input type="submit" name="button1">
    </form>
    border;
        if (isset($_POST['n1'])){
            $n = $_POST['n1'];
            $array = array();
            $array_of_index = array();
            $sum_of_array = 0;
            $arithmetic_mean = 0;
            $count_of_greater_AM = 0;

            for ($i = 0; $i < $n; $i++){
                array_push($array, rand(-25, 35));
            }
        }
   
    if (isset($_POST['n1'])){
        echo "\u{25cf} исходный массив: ";
        $pos_count = 0;
        $neg_count = 0;
        $zero_count = 0;
        for ($i = 0; $i < $n; $i++) {
            if ($array[$i] == 0){
                $zero_count++;
            }
            else{
                ($array[$i] < 0) ? $neg_count++ : $pos_count++;

                // задание 2
                if ($array[$i] % 7 == 5){
                    array_push($array_of_index, $i);
                }
                // задание 3
                $sum_of_array += $array[$i];
            }
            echo $array[$i] . "  ";
        } 
        $zero_count *= 100/$n;
        $pos_count *= 100/$n;
        $neg_count *= 100/$n;
        echo "<br>процент положительных: $pos_count";
        echo "<br>процент отрицательных: $neg_count";
        echo "<br>процент нулевых: $zero_count";
        if ($pos_count > $neg_count) {
            if ($pos_count > $zero_count) {
                echo("<br>положительных больше");
            } else {
                echo("<br>нулевых больше");
            }
        } else {
            if ($neg_count > $zero_count){
                echo("<br>отрицательных больше");
            } else {
                echo("<br>нулевых больше");
            }
        }

        echo "<br>\u{25cf} ";
        for ($i = 0; $i < count($array_of_index); $i++) {
            echo $array_of_index[$i] . " ";
        }

        $arithmetic_mean = $sum_of_array / $n;
        for ($i = 0; $i < $n; $i++) {
            if ($array[$i] > $arithmetic_mean){
                $count_of_greater_AM++;
            }
        }   
        echo("<br>\u{25cf}среднее арифметическое равно  $arithmetic_mean");
        echo("<br>количество, больших среднего арифметического равно  $count_of_greater_AM"); 
    }

    echo <<< border
    <h2 align='center'>Задание 2</h2>
    <form method="POST">
        n: <input type="text" name="n2"><br>
        <input type="submit" name="button2">
    </form>
    border;

    if (isset($_POST['n2'])) {
        $array = array();
        $n = $_POST['n2'];
        srand(time());

        echo "<br>исходный массив: ";
        for ($i = 0; $i < $n; $i++){
            array_push($array, rand(-40, 40));
            echo $array[$i] . "  ";            
        }

        echo ("<br>\u{25cf} максимальный элемент = " . max($array));

        $index_of_last_odd = -1;

        for ($i = count($array) - 1; $i >=0; $i--){
            if (!$array[$i] % 2 == 0){
                $index_of_last_odd = $i;
                break;
            }
        }

        if ($index_of_last_odd != -1){
            echo ("<br>индекс последнего нечетного элемента = " . $index_of_last_odd);
        }

        $array[$index_of_last_odd] = max($array);

        echo "<br>измененный массив массив<br>";
        for ($i = 0; $i < $n; $i++){
            echo($array[$i] . ", ");            
        }

        for ($i = 1; $i < $n; $i += 2){
            $array[$i] /= $i;            
        }

        echo "<br>\u{2b24}измененный массив массив<br>";
        for ($i = 0; $i < $n; $i++){
            echo($array[$i] . ", ");            
        }
    }

    echo <<< border
    <h2 align='center'>Задание 3</h2>
    <form method="POST">
        array: <input type="text" name="array_1"><br>
        <input type="submit" name="button3">
    </form>
    border;
        if (isset($_POST['array_1'])) {
            $string = $_POST['array_1'];
            $array_symbols = array();

            for($i = 0; $i < Strlen($string); $i++){
                array_push($array_symbols, $string[$i]);
            }
            echo "\u{25cf} строка \"" . $string . "\"";
            echo "<br>массив уникальных: ";

            $array_symbols = array_unique($array_symbols);
            for($i = 0; $i < count($array_symbols); $i++){
                echo " " . $array_symbols[$i];
            }
            echo "<br>\u{25cf} количество уникальных = " . count($array_symbols);
        }

    echo <<< border
    <h2 align='center'>Задание 4</h2>
    <form method="POST">
        n: <input type="text" name="n3"><br>
        <input type="submit" name="button4">
    </form>
    border;
        if (isset($_POST['n3'])) {
            $n = $_POST['n3'];
            $array = array();
            $max_length = 0;
            $index_of_max_length = -1;

            echo "\u{25cf} исходный массив: ";
            for ($i = 0; $i < $n; $i++){
                $temp_length = rand(1, 20);
                if ($temp_length > $max_length){
                    $max_length = $temp_length;
                    $index_of_max_length = $i;
                }

                $temp_str = "";
                for ($j = 0; $j < $temp_length; $j++){
                    $temp_str .= chr(rand(33, 126));
                }

                array_push($array, $temp_str);
                echo "<br>" . ($i + 1) . ". " . $array[$i];
            }

            echo "<br>\u{25cf} самое длинное слово c индексом " .$index_of_max_length + 1 . " : " . $array[$index_of_max_length];

            for($i = 0; $i < Strlen($array[$index_of_max_length]); $i++){
                if (ord($array[$index_of_max_length][$i]) >= 48 &&
                    ord($array[$index_of_max_length][$i]) <= 57) {
                    $array[$index_of_max_length][$i] = "*";
                }
            }

            echo "<br>\u{25cf} измененный массив: ";
            for ($i = 0; $i < $n; $i++){                
                echo "<br>" . ($i + 1) . ". " . $array[$i];
            }            
        }
    ?>

</body>