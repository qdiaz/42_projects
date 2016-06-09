#!/usr/bin/php
<?php

$str = $argv[1];
$str = trim($str);
$str = eregi_replace("[ ]+", " ", $str);
echo "$str\n";

?>
