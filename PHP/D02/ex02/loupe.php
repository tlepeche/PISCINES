#!/usr/bin/php
<?PHP
if ($argc < 2)
	exit;

$all = file_get_contents($argv[1]);

if (!$all)
	exit;

function ft_niv2($matches)
{
	return str_replace($matches[1], strtoupper($matches[1]), $matches[0]);
}

function ft_niv1($matches)
{
	$str1 = preg_replace_callback("/>([^>]*)</i", "ft_niv2", $matches[0]);
	return preg_replace_callback("/title=\"([^>]*)\"/i", "ft_niv2", $str1);
}

$str = preg_replace_callback("/<a.*href=.*<\/a>/si", "ft_niv1", $all);
echo $str;
?>
