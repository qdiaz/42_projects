<?php
session_start();
if (!$_SESSION['loggued_on_user'])
{
	echo "ERROR 1\n";
	return ;
}
if ($_POST['submit'] == "SEND" && $_POST['text'] != "")
{
	date_default_timezone_set('Europe/Paris');
	$login = $_SESSION['loggued_on_user'];
	$time = time();
	$msg = $_POST['text'];
	$filename = '../private/chat';
	$array = array(
		"login" => "$login",
		"time" => "$time",
		"msg" => "$msg",
	);
	if (!file_exists($filename) || !file_exists("../private"))
	{
		if (!file_exists("../private"))
		mkdir("../private");
		$tab = array($array);
		$tab = serialize($tab);
		file_put_contents($filename, $tab);
	}
	else
	{
		$fp = fopen($filename,"r+");
		flock($fp, LOCK_SH | LOCK_EX);
		$tab = unserialize(file_get_contents($filename));
		$tab[] = $array;
		$tab = serialize($tab);
		file_put_contents($filename, $tab);
	}
	$fp = fopen($filename, "r+");
	flock($fp, LOCK_SH | LOCK_EX);
	fclose($fp);
}
?>
<head>
<style>
body {
	margin:0;
}
textarea {
	font-size:1.2vw;
	border:0;
	width:90%;
	height:100%;
	margin:left;
	resize:none;
	border: 2px solid #1cf000;
	background-color:black;
	color:#1cf000;
	font-family:monospace;
}
form {
	margin:0;
	width:100%;
	height:100%;
	background: #444;
}
input {
	float:right;
	width:5%;
	height:100%;
	position:absolute;
	z-index:2;
	cursor:pointer;
	font-family: monospace;
	font-size: 1.2vw;
	color:white;
	padding-top: 7px;
	text-align: center;
	color: #1cf000;
	background: black;
}
</style>
<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
</head>
<form method="POST" action="speak.php">
	<textarea name="text"placeholder="Entrez votre message ici..."></textarea>
	<input type="reset" value="RESET">
	<input name="submit" type="submit" value="SEND" style="position:relative">
</form>
