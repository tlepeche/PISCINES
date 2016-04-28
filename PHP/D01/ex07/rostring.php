#!/usr/bin/php
<?PHP
function ft_spaceless($tab)
{
	if ($tab !== NULL)
		return true;
	return false;
}

if ($argv[1] !== NULL)
{
	$tab = explode(" ", trim($argv[1]));
	$tab = array_filter($tab, ft_spaceless);
	$i = 1;
	while($tab[$i] !== NULL)
	{
		echo"$tab[$i] ";
		$i++;
	}
	if ($tab[0] !== NULL)
		echo"$tab[0]\n";
}
?>
