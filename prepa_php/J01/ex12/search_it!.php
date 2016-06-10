#!/usr/bin/php
<?php
if ($argc > 1)
{
	$len = strlen($argv[1]);
	$i = 2;
	while ($argv[$i] != null)
	{
		if (strncmp($argv[1], $argv[$i], $len) == 0)
		{
			$tab = explode(":", $argv[$i]);
		}
		$i++;
	}
	if ($tab[1] != null)
		echo "$tab[1]\n";
}
?>
