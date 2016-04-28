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
if (file_exists("./../private/passwd") == true)
	$registre = unserialize(file_get_contents("./../private/passwd"));
$i = 0;
foreach ($registre as $elem)
{
	if ($elem['login'] == $login)
	{
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
$registre[$i] = $tab;
if (file_exists("./../private") == false)
	mkdir("./../private");
file_put_contents("./../private/passwd", serialize($registre));
echo"OK\n";
header("Location:index.html");
?>
