#!/usr/bin/php
<?php
function put_maj($array)
{
	return $array[1].strtoupper($array[2]);
}
function get_link($str)
{

	$str = implode( "", $str);
	$str = preg_replace_callback("%(>)([^<]+)%", put_maj, $str);
	return $str;
}
if ($argc != 2)
	exit(0);
if (!is_file($argv[1]))
{
	print($argv[1]."does not exist.\n");
	exit(0);
}

$str = file_get_contents($argv[1]);
$str = preg_replace_callback("%(title=)(\".*?\")%", put_maj, $str);
$str = preg_replace_callback("%<a.*</a>%", get_link, $str);
echo "$str";
?>
