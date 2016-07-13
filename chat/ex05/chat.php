<style>
body {
	margin:0;
	background-color:black;
	color:#1cf000;
	border:2px solid #1cf000;
	font-family:monospace;
}
</style>
<?php
$filename = '../private/chat';
if (!file_exists($filename) || !($tab = unserialize(file_get_contents($filename))) || !file_exists('../private'))
	return ;
foreach ($tab as $elem)
{
	echo "[".date('H:i', $elem['time'])."]"."  <b>".$elem['login']."</b>:  ".$elem['msg']."<br />";
}
?>
