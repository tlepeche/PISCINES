<?PHP
session_start();
$var = $_SESSION['loggued_on_user'];
if ($var == "")
	echo"ERROR\n";
else
	echo"$var\n";
?>
