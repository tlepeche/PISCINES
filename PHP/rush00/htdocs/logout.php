<?php
session_start();
if (isset($_POST['logout']) == "Logout")
{
	session_destroy();
	header("Location: index.php");
}
?>
</td><td>
<form action="logout.php" method="POST">
	<input class=logout type="image" src="http://brasseriestade.free.fr/themes/BlueWash/style/images/dock/logout.png" name="logout" value="Logout">
</form>
