<?PHP
if ($_POST['submit'] == 'OK' && $_POST['login'] != NULL && $_POST['passwd'] != NULL)
{
	$login = $_POST['login'];
	$passwd = $_POST['passwd'];
}
else
{
	echo"ERROR\n";
	return ;
}
if (file_exists("./../private/passwd") == true)
	$registre = unserialize(file_get_contents("./../private/passwd"));
foreach ($registre as $elem)
{
	foreach($elem as $key => $val)
	{
		if ($key == 'login' && $val == $_SESSION['login'])
		{
			echo"ERROR\n";
			return ;
		}
	}
}
$tab['login'] = $login;
$tab['passwd'] = hash("whirlpool", $passwd);
$registre[] = $tab;
if (file_exists("./../private") == false)
	mkdir("./../private");
file_put_contents("./../private/passwd", serialize($registre));
echo"OK\n";
?>
