#!/usr/bin/php
<?PHP
$j = 1;
while($argv[$j] !== NULL)
{
	$str = trim($argv[$j]);
	while (strpos($str, "  "))
		$str = str_replace("  ", " ", $str);
	$tab_1 = explode(" ", $str);
	if (!$tab)
		$tab = $tab_1;
	else
		$tab = array_merge($tab, $tab_1);
	$j++;
}
sort($tab);
$i = 0;
while($tab[$i] !== NULL)
{
	echo"$tab[$i]\n";
	$i++;
}
?>
