<!DOCTYPE html>
<html>
<body>

<?php
$x=100;
$y="100";

var_dump($x == $y); // returns true because values are equal
echo "<br>";
var_dump($x === $y); // returns false because types are not equal
echo "<br>";
var_dump($x != $y); // returns false because values are equal
echo "<br>";
var_dump($x !== $y); // returns true because types are not equal
echo "<br>";

$a=50;
$b=90;

var_dump($a > $b);
echo "<br>";
var_dump($a <  $b);
?>  

</body>
</html>