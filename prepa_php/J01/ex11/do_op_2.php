#!/usr/bin/php
<?php

$i = 0;

if ($argc != 2)
	echo "Incorrect Parameters\n";
else
{
	while($argv[1][$i])
	{
		if ($argv[1][$i] == '+')
		{
			$nb_op++;
			$op = '+';
		}
		if ($argv[1][$i] == '-')
		{
			$nb_op++;
			$op = '-';
		}
		if ($argv[1][$i] == '*')
		{
			$nb_op++;
			$op = '*';
		}
		if ($argv[1][$i] == '/')
		{
			$nb_op++;
			$op = '/';
		}
		if ($argv[1][$i] == '%')
		{
			$nb_op++;
			$op = '%';
		}
		$i++;
	}
	if ($nb_op != 1)
		echo "Syntax Error\n";
	else
	{
		$tab = array();
		$tab = explode($op, $argv[1]);
		$tab[0] = trim($tab[0]);
		$tab[1] = trim($tab[1]);
		if (!is_numeric($tab[0]) || !is_numeric($tab[1]))
			echo "Syntax Error";
		else if ($op == '+')
			$res = $tab[0] + $tab[1];
		else if ($op == '-')
			$res = $tab[0] - $tab[1];
		else if ($op == '*')
			$res = $tab[0] * $tab[1];
		else if ($op == '/' && $tab[1] != 0)
			$res = $tab[0] / $tab[1];
		else if ($op == '%' && $tab[1] != 0)
			$res = $tab[0] % $tab[1];
		else
			echo "Incorrect Parameters\n";
		if ($res)
			echo "$res\n";
	}
}
?>
