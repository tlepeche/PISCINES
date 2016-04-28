<?php
include("bdd/bdd.php");
function get_link($msg)
{
	if ($msg == "SUCCESS")
	{
		$lnk['ref'] = "index.php";
		$lnk['label'] = "Home";
	}
	else
	{
		$lnk['ref'] = "register.html";
		$lnk['label'] = "Register";
	}
	echo "<a href='".$lnk['ref']."'>".$lnk['label']."</a>";
}

if ($bdd = connect_db())
{
	if ($_POST['register'] == "Register")
	{
		if ($_POST['login'] != NULL)
		{
			$login = $_POST['login'];
			if ($_POST['passwd'] != NULL)
			{
				$pwd = $_POST['passwd'];
				if ($pwd == $_POST['verif'])
				{
					$pwd = hash('whirlpool', $pwd);
					$req = "SELECT * FROM login WHERE login = '$login'";
					$res = mysqli_query($bdd, $req);
					$data = mysqli_fetch_assoc($res);
					if ($data == NULL)
					{
						$req = "INSERT INTO login (login, password) VALUES (?, ?)";
						$req_pre = mysqli_prepare($bdd, $req);
						mysqli_stmt_bind_param($req_pre, "ss", $login, $pwd);
						if (mysqli_stmt_execute($req_pre) == FALSE)
							$msg = "ERROR: db insert";
						else
							$msg = "SUCCESS";
					}
					else
						$msg = "ERROR: login already exist";

				}
				else
					$msg = "ERROR: incorrect password";
			}
			else
				$msg = "ERROR: password required";
		}
		else
			$msg = "ERROR: login required";
	}
	else
		$msg = "ERROR: form ".$_POST['submit'];
	mysqli_close($bdd);
}
else
	$msg = "ERROR: connect db";
if ($msg == "SUCCESS")
{
	$fname = $_POST['fname'];
	$lname = $_POST['lname'];
	$email = $_POST['email'];
	$addr = $_POST['addr'];
	$city = $_POST['city'];
	$state = $_POST['state'];
	$zip = $_POST['zip'];

	if ($bdd = connect_db())
	{
		$req_u = "SELECT id FROM login WHERE login = '".$_POST['login']."'";
		$res_u = mysqli_query($bdd, $req_u);
		$data_u = mysqli_fetch_assoc($res_u);
		$uid = $data_u['id'];

		$req = "INSERT INTO address (id, first_name, last_name, email, address, city, state, zip)
				VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
		$req_pre = mysqli_prepare($bdd, $req);
		mysqli_stmt_bind_param($req_pre, "issssssi", $uid, $fname, $lname, $email, $addr, $city, $state, $zip);
		if (mysqli_stmt_execute($req_pre) == FALSE)
		{
			echo mysqli_error($bdd);
			$msg = "ERROR: insert address";
		}
		disconnect_db($bdd);
	}
}
?>
<html>
	<body>
		<table>
			<tr>
				<td><?php echo $msg; ?></td>
				<td><?php get_link($msg)?></td>
			</tr>
		</table>
	</body>
</html>
