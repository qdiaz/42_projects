<?php
include('../config.php');
$mysqli = mysqli_connect($mysqli_host, $mysqli_user, $mysqli_pass, $mysqli_db, $mysqli_port);
$res = mysqli_query($mysqli, "SELECT * FROM `catalog`");
while (($row = mysqli_fetch_assoc($res)) !== NULL)
{
	$img = $row['img'];
	$name = $row['name'];
	$price = $row['price'];
	echo "<img src=\"$img\">$name : $price";
}
mysqli_close($mysqli);
?>
