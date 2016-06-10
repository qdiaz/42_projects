#!/usr/bin/php
<?php
date_default_timezone_set('Europe/Paris');
$str = file_get_contents("/var/run/utmpx");
$i = 0;
$str = substr($str, 1256);
while ($str)
{
	$tab[$i] = unpack("a256login/a4id/a32line/ipid/itype/i2time/a256host/I16pad", $str);
	$str = substr($str, 628);
	$i++;
}
sort($tab);
$i = 0;
while($tab[$i])
{
	if ($tab[$i]['type'] == 7)
		printf("%-7s  %-7s  %s\n", $tab[$i]['login'], $tab[$i]['line'], date('M j H:i', $tab[$i][time1]));
	$i++;
}
?>
