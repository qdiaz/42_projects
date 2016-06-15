<?php
if ($_GET["action"] != NULL)
	$action = $_GET["action"];
if ($_GET["name"] != NULL)
	$name = $_GET["name"];
if ($_GET["value"] != NULL)
	$value = $_GET["value"];
if ($name == NULL)
	echo "Il faut entrer un nom de cookie";
if ($action == "set")
	setcookie($name, $value, time() + 3600);
if ($action == "get")
	echo $_COOKIE[$name];
if ($action == "del")
	setcookie($name, NULL, -1);
?>
