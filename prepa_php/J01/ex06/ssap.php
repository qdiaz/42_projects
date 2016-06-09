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
sort($res);
foreach ($res as $line)
{
	echo $line;
	echo "\n";
}
?>
