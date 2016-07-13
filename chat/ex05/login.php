<?php
session_start();
include("auth.php");
if (auth($_POST['login'], $_POST['passwd']) === TRUE)
{
	$_SESSION['loggued_on_user'] = $_POST['login'];
	echo "<iframe src=chat.php height='550px' width='100%' name='chat' style='border:0;'></iframe>";
	echo "\n";
	echo "<iframe src=speak.php height='50px' width='100%' name='speak' style='border:0;'></iframe>";
	echo "\n";
}
else
{
	$_SESSION['loggued_on_user'] = "";
	echo "ERROR\n";
}
?>
