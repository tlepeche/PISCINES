<?php
Include("bdd/bdd.php");
session_start();
if (isset($_POST['submit']) == "Login")
{
	if (isset($_POST['login']))
	{
		$login = $_POST['login'];
		if (isset($_POST['passwd']))
		{
			$pwd = $_POST['passwd'];
			$pwd = hash('whirlpool', $pwd);
			if ($bdd = connect_db())
			{
				$req = "SELECT * FROM login WHERE login = '$login'";
				$res = mysqli_query($bdd, $req);
				$data = mysqli_fetch_assoc($res);
				if ($data == NULL)
					echo "ERROR: login not found";
				else
				{
					if ($data['password'] == $pwd)
					{
						$_SESSION['login'] = $login;
						$_SESSION['id'] = $data['id'];
						$_SESSION['lvl'] = $data['lvl'];
						header("Location: index.php");
						echo "OK";
					}
					else
					{
						unset($_SESSION['login']);
						echo "ERROR: wrong password";
					}
				}
			}
			else
			{
				echo "ERROR: connect db";
			}
			disconnect_db($bdd);
		}
		else
			echo "ERROR: password";
	}
	else
		echo "ERROR: login";
}
else
	echo "ERROR: form";
?>
