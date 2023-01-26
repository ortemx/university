<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Lab-2</title>
</head>
<body>
	<?php
		function print_array($array, $n){
			for ($i = 0; $i < $n; $i++)
				echo $array[$i] . " ";
		}

		function print_answer_1($n, $A){
			echo "<h2 align='center'>Задание 1</h2>";
			$sum = 0;
			$count = 0;
			$number = 0;
			$flag = 0;
			$array = array();
			for ($i = 0; $i < $n; $i++)
				array_push($array, rand(-10, 20));
			print_array($array, $n);
			for ($i = 0; $i < $n; $i++) { 
				if ($i % 2 == 1)
					$sum += $array[$i];
				if ($array[$i] > $A && $array[$i] % 5 == 0){
					$count++;
					echo "<br>". $array[$i];
				}
				if ($array[$i] % 5 == -2 && $array[$i] < $array[$number]){
					$number = $i;
					$flag = 1;
				}
			}	
			if ($flag == 0)
				$number = "Элементов, удовлетворяющих условиям, не найдено";
			echo "<br>1. " . $sum . "<br>2. " . $count . "<br>3. " . $number;
		}

		function print_task_1(){
			echo <<< END
			<form action="$_SERVER[PHP_SELF]" method="post">
			<h2 align="center">Задание 1</h2>
			<br>n
			<input type="text" name="n1">
			<br>A
			<input type="text" name="A">
			<br> <input type="submit" value="Подсчитать" name="sumbit_1"/>		
END;
		}

		if (isset($_POST['sumbit_1']) && isset($_POST['n1']) && isset($_POST['A']) && is_numeric($_POST['n1']) && is_numeric($_POST['A'])) {
			$n = (integer)$_POST['n1'];
			$A = (integer)$_POST['A'];
			print_answer_1($n, $A);
		}
		else 
			print_task_1();

		function print_answer_2($n){
			echo "<h2 align='center'>Задание 2</h2>";
			$sum = 0;
			$array = array();
			for ($i = 0; $i < $n; $i++)
				array_push($array, rand(-100, 100));
			print_array($array, $n);
			$sum = array();
			for ($i = 0; $i < $n; $i++) { 
				if ($array[$i] > 0)
					$number = $i;
				if (!($i % 2))
					$A[$i] = pow($array[$i], 2);
				else
					$A[$i] = 2 * $array[$i];
			}	
			for ($i = 0; $i < $n; $i++) { 
				if ($array[0] != 0){
					if ($i % 2 == 0) 
						array_push($sum, round($array[$i]/$array[0], 3));
				}
				else {
					echo "<br>Первый элемент массива равен 0, подсчёт невозможен";
					break;
				}
			}
			$value = $array[1];
			$array[1] = $array[$number];
			$array[$number] = $value;
			echo "<br>1. ";
			print_array($array, $n);
			echo "<br>2. ";
			var_dump($sum);
			// print_array($sum, $n);	
			echo "<br>3. ";
			print_array($A, $n);

		}

		function print_task_2(){
			echo <<< END
			<form action="$_SERVER[PHP_SELF]" method="post">
			<h2 align="center">Задание 2</h2>
			<br>n
			<input type="text" name="n2">
			<br> <input type="submit" value="Подсчитать" name="sumbit_2"/>		
END;
		}

		if (isset($_POST['sumbit_2']) && isset($_POST['n2']) && is_numeric($_POST['n2'])) {
			$n = (integer)$_POST['n2'];
			print_answer_2($n);
		}
		else 
			print_task_2();

		function print_answer_3($n){
			echo "<h2 align='center'>Задание 3</h2>";
			$array = array();
			for ($i = 0; $i < $n; $i++)
				array_push($array, chr(rand(65, 75)));
			print_array($array, $n);
			for ($i = 0; $i < $n; $i++)
				for ($j = $i + 1; $j < $n; $j++)
					if ($array[$j] == $array[$i]){
						array_splice($array, $j, 1);
						$n--;
						$j--;
					}
			echo "<br>Ответ: ";
			print_array($array, $n);
		}

		function print_task_3(){
			echo <<< END
			<form action="$_SERVER[PHP_SELF]" method="post">
			<h2 align="center">Задание 3</h2>
			<br>k
			<input type="text" name="k">
			<br> <input type="submit" value="Подсчитать" name="sumbit_3"/>		
END;
		}

		if (isset($_POST['sumbit_3']) && isset($_POST['k']) && is_numeric($_POST['k'])) {
			$k = (integer)$_POST['k'];
			print_answer_3($k);
		}
		else 
			print_task_3();

		function print_answer_4($n){
			echo "<h2 align='center'>Задание 4</h2>";
			$chars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZEYUIOAZEYUIOAZEYUIOA';
			$array = array();
			for ($i = 0; $i < $n; $i++){
				$len = rand(1, 10);
				$temp = "";
				for ($j = 0; $j < $len; $j++)
					$temp .= $chars[rand(0, strlen($chars) - 1)];
				array_push($array, $temp);
			}
			$n = count($array);
			print_array($array, $n);
			$arr = array();
			$flag = 0;
			for($i = 0; $i < $n; $i++){
				$vowels = preg_replace("/[QWRTPSDFGHJKLZXCVBNM]/", "", $array[$i]);
				if (strlen($vowels) > strlen($array[$i]) - strlen($vowels)){
					array_push($arr, $array[$i]);
					$flag = 1;
				}
			}
			if ($flag){
				echo "<br>Ответ: ";
				print_array($arr, count($arr));
			}
			else
				echo "<br>Строки, удовлетворяющие данному условию, отсутствуют";	
		}

		function print_task_4(){
			echo <<< END
			<form action="$_SERVER[PHP_SELF]" method="post">
			<h2 align="center">Задание 4</h2>
			<br>n
			<input type="text" name="n4">
			<br> <input type="submit" value="Подсчитать" name="sumbit_4"/>		
END;
		}

		if (isset($_POST['sumbit_4']) && isset($_POST['n4']) && is_numeric($_POST['n4'])) {
			$n = (integer)$_POST['n4'];
			print_answer_4($n);
		}
		else 
			print_task_4();
	?>
</body>
</html>
