<?php
if (!$_POST['login'] || !$_POST['oldpw'] || !$_POST['newpw'] || $_POST['submit'] !== "OK" || !file_get_contents("../private/passwd"))
{
	echo "ERROR\n";
	return ;
}
$tab = file_get_contents("../private/passwd");
$tab = unserialize($tab);
$oldpw = hash('whirlpool', $_POST['oldpw']);
foreach ($tab as &$elem)
{
	if ($elem['login'] === $_POST['login'] && $elem['passwd'] === $oldpw)
	{
		$elem['passwd'] = hash('whirlpool', $_POST['newpw']);
		$tab = serialize($tab);
		file_put_contents("../private/passwd", $tab);
		header('Location: ./index.html');
	}
}
echo "ERROR\n";
?>
