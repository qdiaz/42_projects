<style>
body {
	border-radius:0px 0px 5px 5px;
	margin:0;
}
textarea {
	border:0;
	width:90%;
	height:100%;
	margin:left;
	resize:none;
	border-radius:0px 0px 5px 5px;
	background-color:#26C4EC;
}
form {
	border-radius:0px 0px 10px 10px;
	margin:0;
	width:100%;
	height:100%;
	background: #444;
}
input {
	border-radius:0px 0px 5px 0px;
	float:right;
	width:5%;
	height:100%;
	position:absolute;
	z-index:2;
	cursor:pointer;
	font-family: monospace;
	font-size: 1vw;
	color:white;
	padding-top: 7px;
	text-align: center;
	color: #000;
	background: #444;
}
</style>
<?php
echo "\n".$_REQUEST['login'];
if (!$_SESSION['loggued_on_user'])
{
	echo "ERROR\n";
	return ;
}
if ($_POST['submit'] == "Envoyer" && $_POST['text'] != "")
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
	if (!file_exists($filename) || !file_exists("../private/"))
	{
		mkdir("../private/");
		$tab = array($array);
	}
	else
	{
		$fp = fopen($filename,"r+");
		flock($fp, LOCK_SH | LOCK_EX);
		$tab = unserialize(file_get_contents($filename));
		$tab[] = $array;
	}
	$tab = serialize($tab);
	$fp = fopen($filename, "r+");
	flock($fp, LOCK_SH | LOCK_EX);
	file_put_contents($filename, $tab);
	include 'chat.php';
}
?>
<form method="POST" action="speak.php">
	<textarea></textarea>
	<input type="submit" value="Envoyer" style="border-radius:0px 0px 0px 0px">
	<input type="reset" value="Effacer" style="position:relative;">
</form>
