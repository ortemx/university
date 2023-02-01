<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
	<title></title>
	<script type="text/javascript">
		function setValueOnTextBox(value){
			if (value == red_value){
				document.getElementById('red_value_text').value = document.getElementById('red_value').value
			} 
			else if (value == green_value){
				document.getElementById('green_value_text').value = document.getElementById('green_value').value
			} else {
				document.getElementById('blue_value_text').value = document.getElementById('blue_value').value				
			}
			var red = document.getElementById('red_value').value;
			var green = document.getElementById('green_value').value;
			var blue = document.getElementById('blue_value').value;
			
			var color = "rgb(" + red + "," + green + "," + blue + ")";
			console.log(color);
			document.getElementById('palette').style.backgroundColor = color;
		}
	</script>
	<style type="text/css">
		.slider{
			width : 300px;
		}
		.textbox{
			width : 50px;
		}
		.canvas{
			width : 50px;
			height: 50px;
			background-color: red;
		}
	</style>
</head>
<body style="font-family:'Montserrat', sans-serif; ">	
	<div class="slidecontainer">
		красный
  		<input type="range" min="0" max="255" value="26" class="slider" id="red_value" oninput="setValueOnTextBox(red_value)">
  		<input type="text"  value=26 id="red_value_text" class="textbox">
	</div>	
	<div class="slidecontainer">
		зеленый
  		<input type="range" min="0" max="255" value="26" class="slider" id="green_value" oninput="setValueOnTextBox(green_value)">
  		<input type="text"  value=26 id="green_value_text" class="textbox">
	</div>	
	<div class="slidecontainer">
		синий
  		<input type="range" min="0" max="255" value="26" class="slider" id="blue_value" oninput="setValueOnTextBox(blue_value)">
  		<input type="text"  value=26 id="blue_value_text" class="textbox">
	</div>
	<div class="canvas" id="palette">
		
	</div>
</body>
</html>