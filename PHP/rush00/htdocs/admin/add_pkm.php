<?php
Include("../bdd/bdd.php");
include("auth.php");
if ($_POST['submit'] == "Validate")
{
	$pid = $_POST['pkm_id'];
	$pname = $_POST['pkm_name'];
	$pt1 = $_POST['pkm_type1'];
	$pt2 = $_POST['pkm_type2'];
	$price = $_POST['price'];
	$simg = $_POST['simg'];
	$limg = $_POST['limg'];
	$vlimg = $_POST['vlimg'];

	echo "$pid ";
	echo "$pname ";
	echo "$pt1 ";
	echo "$pt2 ";
	echo "$price ";
	echo "$simg ";
	echo "$limg<br />";

	if ($bdd = connect_db())
	{
		$req = "SELECT * FROM pokedex WHERE id = '$pid'";
		$res = mysqli_query($bdd, $req);
		$data = mysqli_fetch_assoc($res);
		if ($data == NULL)
			$act = "add";
		else
			$act = "modif";
		disconnect_db($bdd);
	}
	else
		echo "ERROR: connect db";
	echo "$act<br />";

	if ($bdd = connect_db())
	{
		if ($act == "add")
			$req = "INSERT INTO pokedex (id, name, type1, type2, price, simg, limg, vlimg) 
			VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
		else
			$req = "UPDATE pokedex 
			SET id = ?, name = ?, type1 = ?, type2 = ?, price = ?, simg = ?, limg = ?, vlimg = ?
			WHERE id = '$pid'";
		$req_pre= mysqli_prepare($bdd, $req);
		mysqli_stmt_bind_param($req_pre, "isiiisss", $pid, $pname, $pt1, $pt2, $price, $simg, $limg, $vlimg);
		if (mysqli_stmt_execute($req_pre) == FALSE)
			echo "ERROR: insert";
		else
			echo "SUCCESS: insert";
		disconnect_db($bdd);
	}
	else
		echo "ERROR: connect db";
	header("Location: del_pkm.php");
}
?>
