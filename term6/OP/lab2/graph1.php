<!DOCTYPE html>
<html>
<head>
	<meta charset = "utf-8">
	<meta name = "viewport" content = "width  =  device-width, initial-scale  =  1">
	<link href = "https://fonts.googleapis.com/css?family  =  Montserrat" rel = "stylesheet">
	<title>graph1.php</title>
	<script type = "text/javascript">
		function contr_value_change() {
			elem  =  document.getElementById('cont_value');
			value  =  document.getElementById('range').value;
			elem.value  =  value;
		}
	</script>
	<style type = "text/css">
		:root{
			--main-bg-color: #36565D;
			--main-el-color: #D4D3BF;
		}
		body{
			background: var(--main-bg-color);
			color: var(--main-el-color);
			font-family:'Montserrat', sans-serif;
			font-size: 40px;
		}
		.slider{
			width : 400px;
			accent-color: var(--main-el-color);
			position: initial;
			left: 10px;
		}
		#range{
			width: 248px;
		}
		#cont_value{
			width : 70px;
			border: 2px solid var(--main-el-color);
			border-radius: 10px;
			outline: 0;
			height: 30px;
			color: var(--main-el-color);
			font-size: 26px;
			text-align: center;
			background-color: transparent;
			margin-left: 47px;
		}
		#button{
			border: 2px solid var(--main-el-color);
			border-radius: 10px;
			height: 38px;
			width : 150px;
			background-color: transparent;
			font-size: 26px;
			text-align: center;
			color: var(--main-el-color);
		}
		#pic {
			margin: 10px;
		}
		#input {
			padding: 40px;
		}
	</style>
</head>
<body>
	<div id = "title">Изменение контрастности изображения</div>
	<form action = "Graph1.php" method = "POST">
		<span id = "span_1">Контрастность рисунка</span>
		<input type = "range" name = "range" class = "slider" id = "range" min = "-100" max = "100" oninput = "contr_value_change()"><br>
		<span id = "span_2">Положение ползунка</span>
		<input type = "text" name = "text" id = "cont_value" value = "1" readonly>
		<input type = "submit" name = "button1" id = "button" value = "run">
	</form>
	<img 
		border = "2" 
		src = "Graph2.php?param=<?php echo $_POST['range']; ?>" 
		id = "pic" 
		width = "700" 
		height = "480">
</body>
</html>