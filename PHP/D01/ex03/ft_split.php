<?PHP
function ft_spaceless($tab)
{
	if ($tab !== NULL)
		return true;
	return false;
}

function ft_split($p1)
{
	$p1 = trim($p1);
	$tab = explode(" ", $p1);
	$tab = array_filter($tab, ft_spaceless);
	sort($tab);
	return $tab;
}
?>
