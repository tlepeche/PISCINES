<?PHP
session_start();
if ($_GET['submit'] == 'OK')
{
	$_SESSION['login'] = $_GET['login'];
	$_SESSION['passwd'] = $_GET['passwd'];
}
$login = $_SESSION['login'];
$pwd = $_SESSION['passwd'];
?>

<html><body>
<form action="index.php" method="get">
Identifiant: <input type="text" name="login" value="<?PHP echo$login;?>"/>
<br />
Mot de passe: <input type="password" name="passwd" value="<?PHP echo$pwd;?>"/>
<input type="submit" name="submit" value="OK">
</form>
</body></html>
