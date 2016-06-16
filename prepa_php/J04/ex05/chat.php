<style>
body {
	margin:0;
	border-radius:10px 10px 0px 0px;
	background-image:linear-gradient(top left,#808080 80%, #B3B3B3 100%);
	background-image:linear-gradient(to bottom right,#808080 80%, #B3B3B3 100%);
}
</style>
<?php
$filename = '../private/chat';
if (!file_exists($filename) || !($tab = unserialize(file_get_contents($filename))) || !file_exists('../private'))
	return ;
$login = $tab['login'];
$msg = $tab['msg'];
$time = date($tab['time']);
echo $time."<b>".$login."</b>".$msg."\n";
?>
