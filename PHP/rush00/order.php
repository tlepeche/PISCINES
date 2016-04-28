<?php
session_start();
include("bdd/bdd.php");
if ($_POST['order'] == "Order")
{
	if (isset($_SESSION['login']))
	{
		$uid = $_SESSION['id'];
		if ($bdd = connect_db())
		{
			$req = "SELECT * FROM bill WHERE log_id = '$uid'";
			$res = mysqli_query($bdd, $req);
			$i = 0;
			while ($data = mysqli_fetch_assoc($res))
				$i++;
			disconnect_db($bdd);
		}
		else
			echo "ERROR: connect db";
		if ($bdd = connect_db())
		{
			$req = "SELECT * FROM cart WHERE log_id = '$uid'";
			$res = mysqli_query($bdd, $req);
			while ($data = mysqli_fetch_assoc($res))
			{
				$pkid = $data['pkm_id'];
				$qty = $data['qty'];
				if ($bdd_o = connect_db())
				{
					$req_o = "INSERT INTO `order` (log_id, pkm_id, qty, cmd_id) VALUES (?, ?, ?, ?)";
					$req_pre = mysqli_prepare($bdd_o, $req_o);
					mysqli_stmt_bind_param($req_pre, "iiii", $uid, $pkid, $qty, $i);
					if (!mysqli_stmt_execute($req_pre))
						echo mysqli_error($bdd_o)."<br />";
					disconnect_db($bdd_o);
				}
				else
					echo "Error: connect db";
			}
		}
		disconnect_db($bdd);
	}
	else
		echo "ERROR: connect db";
	if ($bdd = connect_db())
	{
		$req = "SELECT * FROM `order` WHERE log_id = '$uid' AND cmd_id = '$i'";
		$res = mysqli_query($bdd, $req);
		while ($data = mysqli_fetch_assoc($res))
		{
			$pkid = $data['pkm_id'];
			if ($bddp = connect_db())
			{
				$reqp = "SELECT price FROM pokedex WHERE id = '$pkid'";
				$resp = mysqli_query($bddp, $reqp);
				if (!$datap = mysqli_fetch_assoc($resp))
					echo "ERROR: select db";
				$prc += $datap['price'] * $data['qty'];
				disconnect_db($bddp);
			}
			else
				echo "ERROR: connect_db";
		}
		disconnect_db($bdd);
	}
	else
		echo "ERROR: connect_db()";
	if ($bdd = connect_db())
	{
		$req = "INSERT INTO bill (log_id, total, cmd_id) VALUES (?, ?, ?)";
		$req_pre = mysqli_prepare($bdd, $req);
		mysqli_stmt_bind_param($req_pre, "iii", $uid, $prc, $i);
		if (!mysqli_stmt_execute($req_pre))
			echo "ERROR: insert db";
		disconnect_db();
	}
	else
		echo "ERROR: connect db";
	if ($bdd = connect_db())
	{
		$req = "DELETE FROM cart WHERE log_id = '$uid'";
		mysqli_query($bdd, $req);
		
		disconnect_db($bdd);
	}
	else
		echo "ERROR: connect_db";
}
header("Location: cart.php");
?>
