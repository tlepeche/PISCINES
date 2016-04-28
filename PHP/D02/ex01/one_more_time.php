#!/usr/bin/php
<?PHP

function ft_exit()
{
		echo "Wrong Format\n";
		exit;
}

if ($argv[1] !== NULL)
{
	$tab = explode(" ", $argv[1]);
	if (count($tab) != 5)
		ft_exit();
	$time = explode(":", $tab[4]);
	if ($time[0] > 23 || $time[0] < 0)
		ft_exit();
	if ($time[1] > 59 || $time[1] < 0 || $time[2] > 59 || $time[2] < 0)
		ft_exit();
	$jour = array("[Ll]undi", "[Mm]ardi", "[Mm]ercredi", "[Jj]eudi", "[Vv]endredi", "[Ss]amedi", "[Dd]imanche");

	$mois = array(
		0 => "[jJ]anvier",
		1 => "[fF]evrier",
		2 => "[mM]ars",
		3 => "[aA]vril",
		4 => "[mM]ai",
		5 => "[jJ]uin",
		6 => "[jJ]uillet",
		7 => "[aA]out",
		8 => "[sS]eptembre",
		9 => "[oO]ctobre",
		10 => "[nN]ovembre",
		11 => "[dD]ecembre",
	);
	$ok = 0;
	foreach ($jour as $elem)
	{
		if (preg_match("/^$elem$/", $tab[0]) === 1)
			$ok = 1;
	}
	if ($ok === 0)
		ft_exit();
	if ($tab[1] < 0 || $tab[1] > 31)
		ft_exit();
	$ok = 0;
	$month = 1;
	foreach ($mois as $elem)
	{
		if (preg_match("/^$elem$/", $tab[2]) === 1)
		{
			$ok = 1;
			break ;
		}
		$month++;
	}
	if ($ok === 0)
		ft_exit();
	if ((preg_match("/^[0-9]{4}$/", $tab[3])) === 0)
		ft_exit();
	if (checkdate($month, $tab[1], $tab[3]) === false)
		ft_exit();
	date_default_timezone_set("Europe/Paris");
	$time = mktime ($time[0], $time[1], $time[2], $month, $tab[1], $tab[3]);
		echo"$time\n";
}
?>
