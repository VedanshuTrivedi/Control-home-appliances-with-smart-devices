<?php

@$State = $_GET['State'];
if($State == "on") {
  $file = fopen("nodeMCU.json", "w") or die("can't open file");
  fwrite($file, '{"State": "on"}');
  fclose($file);
} 
else if ($State == "off") {
  $file = fopen("nodeMCU.json", "w") or die("can't open file");
  fwrite($file, '{"State": "off"}');
  fclose($file);
}



?>

<html>
  <head>      
    
    <title>LED_CONTROL</title>
   
  </head>
  <body>
	<center>
		<br>
<h1> LED_CONTROL </h1>
        <a href="?State=on"><button>LED on</button></a>
        <br><br>
		<a href="?State=off"><button>LED off</button></a> &nbsp&nbsp&nbsp
		
	</center>
  </body>
</html>