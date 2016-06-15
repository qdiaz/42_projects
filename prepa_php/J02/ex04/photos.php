#!/usr/bin/php
<?php

preg_match("/www.[\dA-Za-z\_\-\]+.[A-Za-z]+/", $argv[1], $folderName);

if (count($folderName) == 0) {
	exit("Invalid url");
}

$curl = curl_init();

curl_setopt_array($curl, array(
	CURLOPT_RETURNTRANSFER => 1,
	CURLOPT_URL => $argv[1],
));

$resp = curl_exec($curl);

curl_close($curl);

if (!file_exists($folderName[0])) {
	mkdir($folderName[0]);
}
chdir($folderName[0]);

preg_match_all("/<img(.*?)>/s", $resp, $matches);

preg_replace_callback("/src=[\"\'](.*?)[\"\']/s", function ($url) use ($argv){
	preg_match("/[\dA-Za-z\_\-\.]+$/", $url[1], $filename);

	if (substr($url[1], 0, 4 ) != "http") {
		$url[1] = $argv[1].$url[1];
	}

	$fp = fopen($filename[0], "w");
	$curl = curl_init();
	curl_setopt_array($curl, array(
		CURLOPT_FILE => $fp,
		CURLOPT_URL => $url[1],
	));
	curl_exec($curl);
	curl_close($curl);
	fclose($fp);
}, $matches[0]);
?>
