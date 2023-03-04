<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link href="https://fonts.googleapis.com/css?family=Montserrat" rel="stylesheet">
	<title></title>
	<script type="text/javascript">
		function getRandomInt() {
			return Math.floor(Math.random() * 255);
		}

		function copyColorOnClipboard() {
			let color = document.getElementById('hex').innerHTML
			navigator.clipboard.writeText(color)
			//document.getElementById('palette').value = "DONE !"
		}
		function writeHexColor(){
			let red_hex = Number(document.getElementById('slider_red').value).toString(16);
			let green_hex = Number(document.getElementById('slider_green').value).toString(16);
			let blue_hex = Number(document.getElementById('slider_blue').value).toString(16);
			let hex_color = "#" + red_hex + green_hex + blue_hex;
			document.getElementById('hex').innerHTML = hex_color;
		}
 
 		
 		function updatePalette() {
			let red = document.getElementById('slider_red').value;
			let green = document.getElementById('slider_green').value;
			let blue = document.getElementById('slider_blue').value; 
			let color = "rgb(" + red + "," + green + "," + blue + ")";

			let palette = document.getElementById("palette")
			console.log(color);	
			palette.style.backgroundColor = color
		}


		function setValueOnTextBox(value){
			if (value == 'red'){
				document.getElementById('red_value_text').value = document.getElementById('slider_red').value;
			} 
			else if (value == 'green'){
				document.getElementById('green_value_text').value = document.getElementById('slider_green').value;
			} else {
				document.getElementById('blue_value_text').value = document.getElementById('slider_blue').value;	
			}
			writeHexColor();
			updatePalette();
		}


		function setValueOnSlider(color){
			if (color == 'red'){
				let value = document.getElementById('red_value_text').value;
				if (value > 255){
					document.getElementById('red_value_text').value = 255;
					document.getElementById('slider_red').value = 255;
				} else {
					document.getElementById('slider_red').value = value;
				}
			} 
			else if (color == 'green'){
				let value = document.getElementById('green_value_text').value;
				if (value > 255){
					document.getElementById('green_value_text').value = 255;
					document.getElementById('slider_green').value = 255;
				} else {
					document.getElementById('slider_green').value = value;
				}
			} else {
				let value = document.getElementById('blue_value_text').value;
				if (value > 255){
					document.getElementById('blue_value_text').value = 255;
					document.getElementById('slider_blue').value = 255;
				} else {
					document.getElementById('slider_blue').value = value;
				}
			}
			
			writeHexColor();
			updatePalette();
		}


		function setInitialValues(){
			document.getElementById('slider_red').value = getRandomInt();
			document.getElementById('slider_green').value = getRandomInt();
			document.getElementById('slider_blue').value = getRandomInt();
			console.log(document.getElementById('slider_red').value, document.getElementById('slider_green').value, document.getElementById('slider_blue').value)
		}
	</script>
	<style type="text/css">
		body{
			justify-content: center;
			background-color: #101010;
			color: #987A48;
			font-size: 30px;
		}
		.slider{
			width : 400px;
			accent-color: #987A48;
			position: initial;
			left: 10px;
		}
		.textbox{
			width : 70px;
			--border: 2px solid #987A48;
			border: 2px solid #101010;
			border-radius: 10px;
			outline: 0;
			height: 30px;
			color: #987A48;
			font-size: 26px;
			text-align: center;
			background-color: transparent;
			margin: 10px;
		}
		.palette{
			width : 400px;
			border: 2px solid #101010;
			border-radius: 10px;
			outline: 0;
			height: 30px;
			color: #987A48;
			font-size: 26px;
			text-align: center;
			background-color: transparent;
			cursor: pointer;		
		}
		.canvas{
			width : 400px;
			height: 50px;
		}

		span {
			display: inline-block;
			width: 150px;
		}
		#red_span{
			color: #ad1f1f;
		}
		#green_span{
			color: #1fad47;
		}
		#blue_span{
			color: #0077FF;
		}
		
	</style>
</head>
<body style="font-family:'Montserrat', sans-serif;">	
	<div class="block-1">
		<span id="red_span">красный</span>
  		<input type="range" min="0" max="255" class="slider" id="slider_red" oninput="setValueOnTextBox('red')">
  		<input type="text"  id="red_value_text" class="textbox" onchange="setValueOnSlider('red')">
	</div>	
	<div class="block-2">
		<span id="green_span">зеленый</span>
  		<input type="range" min="0" max="255" class="slider" id="slider_green" oninput="setValueOnTextBox('green')">
  		<input type="text"  id="green_value_text" class="textbox" onchange="setValueOnSlider('green')">
	</div>	
	<div class="block-3">
		<span id="blue_span">синий</span>
  		<input type="range" min="0" max="255" class="slider" id="slider_blue" oninput="setValueOnTextBox('blue')">
  		<input type="text"  id="blue_value_text" class="textbox" onchange="setValueOnSlider('blue')">
	</div>	
	<div>
		<span id="hex"></span>
		<input type="text" class='palette' id='palette' onclick="copyColorOnClipboard()" readonly >	
	</div>
	<script type="text/javascript">
		setInitialValues();
		setValueOnTextBox('red');
		setValueOnTextBox('green');
		setValueOnTextBox('blue');
	</script>
</body>
</html>