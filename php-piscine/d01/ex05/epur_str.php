#!/usr/bin/php
<?php
	if ($argc == 2) {
		$result = array_filter(explode(" ", $argv[1]));
		echo implode(" ",$result)."\n";
	}
?>