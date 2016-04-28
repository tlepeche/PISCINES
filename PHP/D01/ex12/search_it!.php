#!/usr/bin/php
<?PHP
$count = count($argv);

if ($count > 2)
{
	$i = $count - 1;
	$j = 0;
	while($count > 2)
	{
		$tab = explode(":", $argv[$i]);
		if ($tab[0] == $argv[1])
		{
			if ($tab[1] !== NULL)
				echo"$tab[1]\n";
			break;
		}
		$j++;
		$i--;
		$count--;
	}
}
?>
