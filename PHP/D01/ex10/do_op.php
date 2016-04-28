#!/usr/bin/php
<?PHP
$count = count($argv);
if ($count == 4)
{
	$nb1 = trim($argv[1]);
	$op = trim($argv[2]);
	$nb2 = trim($argv[3]);
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
else
	echo"Incorrect Parameters\n";
?>
