#!/usr/bin/php
<?PHP
function ft_isalpha($str)
{
	$str = strtolower($str);
	$i = 0;
	if (!$str[$i])
		return false;
	while($str[$i])
	{
		if ('a' > $str[$i] || $str[$i] > 'z')
			return false;
		$i++;
	}
	return true;
}

function ft_aff($tab)
{
	sort($tab, SORT_STRING | SORT_FLAG_CASE);
	$count = count($tab);
	$i = 0;
	while($i < $count)
	{
		echo"$tab[$i]\n";
		$i++;
	}
}

$j = 1;
$count = count($argv);
while($j < $count)
{
	$str = trim($argv[$j]);
	while (strpos($str, "  "))
		$str = str_replace("  ", " ", $str);
	$tab_a = explode(" ", $str);
	if ($tab_a[0] != "")
	{
		if (!$tab)
			$tab = $tab_a;
		else
			$tab = array_merge($tab, $tab_a);
	}
	$j++;
}
$i = 0;
$a = 0;
$b = 0;
$c = 0;
$count = count($tab);
while($i < $count)
{
	if (ft_isalpha($tab[$i]))
	{
		$tab_1[$a] = $tab[$i];
		$a++;
	}
	else if (is_numeric($tab[$i]))
	{
		$tab_2[$b] = $tab[$i];
		$b++;
	}
	else
	{
		$tab_3[$c] = $tab[$i];
		$c++;
	}
	$i++;
}
if ($tab_1)
	ft_aff($tab_1);
if ($tab_2)
	ft_aff($tab_2);
if ($tab_3)
	ft_aff($tab_3);
?>
