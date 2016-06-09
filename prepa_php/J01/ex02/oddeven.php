#!/usr/bin/php
<?php
$un = 1;
while ($un)
{
	echo "Entrez un nombre : ";
	$cmd = fgets(STDIN);
	if($cmd == NULL)
	{
		$un = 0;
		echo "\n";
	}
	else
	{
		$cmd = trim($cmd);
		if(is_numeric($cmd))
		{
			if (($cmd % 2) == 0)
				echo "le chiffre $cmd est Pair\n";
			else
				echo "le chiffre $cmd est Impair\n";
		}
		else
			echo "'$cmd' n'est pas un chiffre\n";
	}
}	
?>
