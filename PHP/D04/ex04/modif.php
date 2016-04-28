<?PHP
session_start();

if ($_POST['submit'] == 'OK' && $_POST['login'] != NULL && $_POST['oldpw'] != NULL && $_POST['newpw'] != NULL)
{
	$_SESSION['login'] = $_POST['login'];
	$_SESSION['oldpw'] = hash("whirlpool", $_POST['oldpw']);
	$_SESSION['newpw'] = hash("whirlpool", $_POST['newpw']);
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
	if ($elem['login'] == $_SESSION['login'])
	{
		if ($elem['passwd'] == $_SESSION['oldpw'])
		{
			$tab['passwd'] = $_SESSION['newpw'];
			$tab['login'] = $_SESSION['login'];
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
?>
