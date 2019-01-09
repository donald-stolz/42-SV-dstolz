#!/usr/bin/php
<?php
	function ft_split($str)
	{
		$result = array_filter(explode(" ", $str));
		sort($result);
		return $result;
	}
	if ($argc > 1){
	$array = array();
	array_shift($argv);
	foreach ($argv as $v) {
		$tmp = ft_split($v);
        foreach ($tmp as $v2)
            $array[] = $v2;
	}
	sort($array);
	foreach($array as $v)
        echo $v."\n";}
?>