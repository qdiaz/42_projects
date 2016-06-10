#!/usr/bin/php
<?php

if ($argc != 4)
	echo "Incorrect Parameters";
else
{
	if ($argv[2] == '+')
		$res = $argv[1] + $argv[3];
	else if ($argv[2] == '-')
		$res = $argv[1] - $argv[3];
	else if ($argv[2] == '*')
		$res = $argv[1] * $argv[3];
	else if ($argv[2] == '/' && $argv[3] != 0)
		$res = $argv[1] / $argv[3];
	else if ($argv[2] == '%' && $argv[3] != 0)
		$res = $argv[1] / $argv[3];
	else
		echo "Incorrect Parameters";
}
echo "$res\n";
?>
