#!/usr/bin/php
<?PHP
$str = trim($argv[1]);
while (strpos($str, "  "))
	$str = str_replace("  ", " ", $str);
echo"$str\n";
?>
