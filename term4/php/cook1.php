<html>
    <head>
        <title>Cookie 1</title>
        <meta http-equiv="Content-Type" content="text/html" charset="utf-8">
    </head>
    <body>
		<script language="JavaScript" type="text/javascript">
			if(!navigator.cookieEnabled)
			{
				alert("Включите cookie для комфортной работы с этим сайтом");
			}
		</script>

		<form action="cook1.php" method="POST">
        	Добро пожаловать! <br>
        	Введите свое имя :
			<input type = "text" name = "Name"> <br>
			<input type = "submit" name = "btn"/>
		</form>

<?php

	if ($_SERVER['REQUEST_METHOD'] == 'POST') {

	$reg = "/^([A-Za-z \-]*|[А-Яа-я \-]*)$/u";

		if (preg_match($reg, $_POST['Name'])) {
			$name = $_POST['Name'];
			setcookie('name', $name, time() + 3600);
		}
		else {
			echo ("Неверный формат имени!");
			exit;
		}

		$monthArray = array(1 => 'Января', 2 => 'Февраля', 3 => 'Марта', 4 => 'Апреля', 5 => 'Мая', 6 => 'Июня',
		7 => 'Июля', 8 => 'Августа', 9 => 'Сентября', 10 => 'Октября', 11 => 'Ноября', 12 => 'Декабря');

		if (!isset($_COOKIE['user'])) 
		{
			makeUser($name);
		} 
		else 
		{
		$array = unserialize($_COOKIE['user']);

		if ($array['name'] != $name) 
		{
			makeUser($name);
		} 
		else 
		{
			$array['count'] = $array['count'] + 1;
			$array['time'] = "" . date('d') . " " . $monthArray[date('n')] . " " . date('Y') . " года в " . date('G:i:s');
			
			$str = serialize($array);
			setcookie('user', $str, time() + 3600);
			
			Show($array);
		}		
	}	

}

	function Show($dataArray) {

		$name = $dataArray['name'];
		$count = $dataArray['count'];
		$time = $dataArray['time'];
		
		echo ("Добрый день, $name <br>
			Вы заходили на эту страницу : $count раз <br>
			Последнее посещение: $time");
	}

	function makeUser($name) {

		$monthArray = array(1 => 'Января', 2 => 'Февраля', 3 => 'Марта', 4 => 'Апреля', 5 => 'Мая', 6 => 'Июня',
		7 => 'Июля', 8 => 'Августа', 9 => 'Сентября', 10 => 'Октября', 11 => 'Ноября', 12 => 'Декабря');
		$count = 1;
		$time = "" . date('d') . " " . $monthArray[date('n')] . " " . date('Y') . " года в " . date('G:i:s');
		$array = array("name" => $name, "count" => $count++, "time" => $time);
		
		$str = serialize($array);
		setcookie('user', $str, time() + 3600);
		
		Show($array);
	}	

?>

    </body>
</html>