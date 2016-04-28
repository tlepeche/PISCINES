<?PHP
if ($_POST['submit'] == 'OK' && $_POST['login'] != NULL && $_POST['oldpw'] != NULL && $_POST['newpw'] != NULL)
{
	$login = $_POST['login'];
	$oldpw = hash("whirlpool", $_POST['oldpw']);
	$newpw = hash("whirlpool", $_POST['newpw']);
}
else
{
	echo"ERROR\n";
	return ;
}
$registre = unserialize(file_get_contents("./../private/passwd"));
$i = 0;
$ok = 0;
foreach ($registre as $elem)
{
	if ($elem['login'] == $login)
	{
		$ok = 1;
		if ($elem['passwd'] == $oldpw)
		{
			$tab['login'] = $login;
			$tab['passwd'] = $newpw;
			break ;
		}
		else
		{
			echo"ERROR\n";
			return ;
		}
	}
	$i++;
}
if ($ok == 0)
{
	echo"ERROR\n";
	return ;
}
$registre[$i] = $tab;
file_put_contents("./../private/passwd", serialize($registre));
echo"OK\n";
?>
