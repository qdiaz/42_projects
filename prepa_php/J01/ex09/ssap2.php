#!/usr/bin/php
<?php

function check_line($line)
{
	if (empty($line))
		return FALSE;
	return TRUE;
}

$res = [];
$cnt = 0;
if ($argc > 1)
{
	foreach ($argv as $line)
	{
		if ($cnt > 0)
		{
			$tab = array_filter(explode(" ", $line), check_line);
			$res = array_merge($res, $tab);
		}
		$cnt++;
	}
}
$cnt = 0;
natcasesort($res);

$alphtab = array();
$numtab = array();
$alttab = array();

foreach ($res as $var)
{
	if (ctype_alpha($var[0]))
		$alphtab[] = $var;
	else if (ctype_digit($var[0]))
		$numtab[] = $var;
	else
		$alttab[] = $var;
}
foreach($alphtab as $el1)
	echo $el1 ."\n";
foreach($numtab as $el2)
	echo $el2 ."\n";
foreach($alttab as $el3)
	echo $el3 ."\n";

?>
