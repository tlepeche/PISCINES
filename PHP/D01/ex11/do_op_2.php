#!/usr/bin/php
<?PHP
function ft_pars($str)
{
	$err = 0;
	if(strpos($str, "*", 1))
	{
		$tab = explode("*", $str);
		$count = count($tab);
		$tab[2] = "*";
	}
	else if(strpos($str, "+", 1))
	{
		$tab = explode("+", $str);
		$count = count($tab);
		$tab[2] = "+";
	}	
	else if(strpos($str, "/", 1))
	{
		$tab = explode("/", $str);
		$count = count($tab);
		$tab[2] = "/";
	}	
	else if(strpos($str, "%", 1))
	{
		$tab = explode("%", $str);
		$count = count($tab);
		$tab[2] = "%";
	}
	else if(strpos($str, "-", 1))
	{
		$tab = explode("-", $str);
		$count = count($tab);
		$tab[2] = "-";
	}
	if ($count != 2)
		$err = 1;
	if ((is_numeric(trim($tab[0])) == false) || (is_numeric(trim($tab[1])) == false))
		$err = 1;
	if ($err == 1)
	{
		echo"Syntax Error\n";
		return false;
	}
	return $tab;
}

$count = count($argv);
if ($count != 1)
{
	$tab = ft_pars($argv[1]);
	if ($tab)
	{
		$nb1 = trim($tab[0]);
		$op = trim($tab[2]);
		$nb2 = trim($tab[1]);
		if ($op == "+")
		{
			$result = $nb1 + $nb2;
			echo"$result\n";
		}
		else if ($op == "-")
		{
			$result = $nb1 - $nb2;
			echo"$result\n";
		}
		else if ($op == "*")
		{
			$result = $nb1 * $nb2;
			echo"$result\n";
		}
		else if ($op == "/")
		{
			$result = $nb1 / $nb2;
			echo"$result\n";
		}
		else if ($op == "%")
		{
			$result = $nb1 % $nb2;
			echo"$result\n";
		}
	}
}
else
	echo"Incorrect Parameters\n";
?>
