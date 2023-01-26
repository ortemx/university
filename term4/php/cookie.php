<script language="JavaScript" type="text/javascript">
	if(!navigator.cookieEnabled)
	{
		alert("Включите cookie");
	}
</script>

<?php
	setlocale(LC_ALL, 'ru_RU');

	if (isset($_COOKIE['name'])) {
		if(isset($_POST['changedName']) && 
		   strlen($_POST['changedName']) != 0)
		{
			if(!isCorrectName($_POST['changedName'])){
				die("Неверный формат имени!");
			}

			$_COOKIE['name'] = $_POST['changedName'];
			setcookie("name", $_COOKIE['name']);
		}		
		else {
			$_COOKIE['visitCount'] += 1;
			$_COOKIE['lastVisit'] = GetCurrentTime();

			setcookie("visitCount", $_COOKIE['visitCount']);
			setcookie("lastVisit", $_COOKIE['lastVisit']);
		}

		ShowInfo($_COOKIE);
		ShowForm("Изменить имя на: ", "changedName");
	}
	else {
		if(isset($_POST['username']) && 
		   strlen($_POST['username']) != 0)
		{
			if(!isCorrectName($_POST['username'])){
				die("Неверный формат имени!");
			}

			$name = $_POST['username'];
			setcookie("name", $name);
			setcookie("visitCount", 0);
			setcookie("lastVisit", GetCurrentTime());
			header("Refresh:0");
		}
		else
		{
			echo "Добро пожаловать!";
			ShowForm("Введите имя: ", "username");
		}
	}

	function GetCurrentTime()
	{
		$months = [
		  'января',
		  'февраля',
		  'марта',
		  'апреля',
		  'мая',
		  'июня',
		  'июля',
		  'августа',
		  'сентября',
		  'октября',
		  'ноября',
		  'декабря'
		];
		$month = date('n') - 1;
		$timeZone = 'Europe/Moscow';
		$timestamp = time();
		$dt = new DateTime("now", new DateTimeZone($timeZone));
		$dt->setTimestamp($timestamp);
		$result = $dt->format("d " . $months[$month] . " Y года в H:i:s");
		return $result;
	}

	function isCorrectName($name)
	{
		$regex = "/^([A-Za-z \-]*|[А-Яа-я \-]*)$/u";
		return preg_match($regex, $name);
	}

	function ShowInfo($cookie)
	{
		echo "Добро пожаловать, " . $cookie['name'] . "!" .
		"<br>Количество посещений: ". $cookie['visitCount'] .
		"<br>Последнее посещение: " . $cookie['lastVisit'];
	}

	function ShowForm($str, $name)
	{
		echo <<< END
		<form action="$_SERVER[PHP_SELF]" method="post">
		$str 
		<input type="text" name=$name>
		<input type="submit" value="Отправить">
		</form><br>
END;
	}
?>