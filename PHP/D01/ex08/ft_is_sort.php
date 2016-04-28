<?PHP
function ft_is_sort($tab)
{
	$i = 0;
	while($tab[$i])
	{
		$tab_sort[$i] = $tab[$i];
		$i++;
	}
	sort($tab_sort);
	$i = 0;
	while($tab[$i])
	{
		if ($tab[$i] != $tab_sort[$i])
			return false;
		$i++;
	}
	return (true);
}
?>
