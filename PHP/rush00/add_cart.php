<?php
session_start();
include("bdd/bdd.php");
if (isset($_SESSION['login']))
{
	$uid = $_SESSION['id'];
	$tab = "cart";
}
else
{
	if (!isset($_SESSION['tmp']))
		$_SESSION['tmp'] = time();
	$uid = $_SESSION['tmp'];
	$tab = "cart_tmp";
}

if (isset($_POST['submit']))
{
	if ($_POST['submit'] == "Add to cart")
	{
		if (isset($_POST['pkid']))
		{
			$pkid = $_POST['pkid'];
			if (isset($_POST['quantity']))
			{
				$qty = $_POST['quantity'];
				if ($bdd = connect_db())
				{
					$req = "SELECT * FROM $tab WHERE log_id = $uid AND pkm_id = $pkid";
					if (!$res = mysqli_query($bdd, $req))
						echo mysqli_error($bdd);
					$data = mysqli_fetch_assoc($res);
					if ($data == NULL)
						$act = "add";
					else
					{
						$qty += $data['qty'];
						$up = $data['id'];
						$act = "update";
					}
					disconnect_db($bdd);
				}
				if ($act == "add")
				{
					if ($bdd = connect_db())
					{
						$req = "INSERT INTO $tab (log_id, pkm_id, qty) VALUES (?, ?, ?)";
						$req_pre = mysqli_prepare($bdd, $req);
						mysqli_stmt_bind_param($req_pre, "iii", $uid, $pkid, $qty);
						if (mysqli_stmt_execute($req_pre) == FALSE)
							echo "ERROR: insert";
						disconnect_db($bdd);
					}
					else
						echo "ERROR: connect db";
				}
				else if ($act == "update")
				{
					if ($bdd = connect_db())
					{
						$req = "UPDATE $tab SET qty = ? WHERE id = '$up'";
						$req_pre = mysqli_prepare($bdd, $req);
						mysqli_stmt_bind_param($req_pre, "i", $qty);
						if (!mysqli_stmt_execute($req_pre))
							echo "ERROR: update";
						disconnect_db($bdd);
					}
					else
						echo "ERROR: connect db";
				}
			}
		}
	}
	header("Location: index.php");
}
?>
