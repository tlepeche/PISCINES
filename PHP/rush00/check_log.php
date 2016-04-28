<?PHP
session_start();
if (!(isset($_SESSION['login'])))
	include("login.html");
else
{
	echo"<tr>";
	$log_lvl = $_SESSION['lvl'];
	if ($log_lvl >= 5)
	{
		echo"<td>";
		echo "<a class=admin href='http://rush00.local.42.fr:8080/admin/admin.php'>Administrer le site</a><br />";
		echo"</td></tr><tr><td>";
	}
	echo "<a class=manage href='http://rush00.local.42.fr:8080/account.php'>Gerer mon compte</a>";
	echo"</td></tr></table>";
	include("logout.php");
}
?>
