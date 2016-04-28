<?php
include("auth.php");
include("../bdd/bdd.php");
if (isset($_POST['modif']))
{
	foreach ($_POST['modif'] as $key => $val)
		$uid = $key;
	if ($_POST['member'] == "on")
		$member = 1;
	else
		$member = 0;
	if ($_POST['admin'] == "on")
		$member = 5;
	else
		$member = $member;
	if ($bdd = connect_db())
	{
		$req = "UPDATE login SET lvl = ? WHERE id = '$uid'";
		$req_pre = mysqli_prepare($bdd, $req);
		mysqli_stmt_bind_param($req_pre, "i", $member);
		$req = mysqli_stmt_execute($req_pre);
		if ($uid == $_SESSION['id'])
		{
			$_SESSION['lvl'] = $member;
			header("Location: manage_usr.php");
		}
	}
	else
		echo "ERROR: connect db";
}
else if (isset($_POST['del']))
{
	foreach ($_POST['del'] as $key => $val)
		$uid = $key;
	if ($bdd = connect_db())
	{
		$req = "DELETE FROM login WHERE id = '$uid'";
		if (!mysqli_query($bdd, $req))
			echo "ERROR: delete user";
	}
	else
		echo "ERROR: connect db";
}

if ($bdd = connect_db())
{
	$req = "SELECT * FROM login";
	$res = mysqli_query($bdd, $req);
	echo "<form action='manage_usr.php' method='POST'>";
	echo "<table>";
	echo "<tr>";
	echo "<th>Id</th>";
	echo "<th>Date</th>";
	echo "<th>Level</th>";
	echo "<th>Login</th>";
	echo "<th>Member</th>";
	echo "<th>Admin</th>";
	echo "<th>Modif</th>";
	echo "<th>Delete</th>";
	echo "</tr>";
	while ($data = mysqli_fetch_assoc($res))
	{
		echo "<tr>";
		echo "<td>".$data['id']."</td>";
		echo "<td>".$data['date']."</td>";
		echo "<td>".$data['lvl']."</td>";
		echo "<td>".$data['login']."</td>";
		if ($data['lvl'] > 0)
			$check = "checked";
		else
			$check = "";
		if ($data['lvl'] > 4)
			$adm = "checked";
		else
			$adm = "";
		if ($data['lvl'] == 7)
			$enabled = "disabled";
		else
			$enabled = "";
		echo "<td><input type='checkbox' name='member' $check $enabled></td>";
		echo "<td><input type='checkbox' name='admin' $adm $enabled></td>";
		if ($data['lvl'] < 7)
		{
			echo "<td><input type='submit' name='modif[".$data['id']."]' value='modif'></td>";
			echo "<td><input type='submit' name='del[".$data['id']."]' value='X'></td>";
		}
		else
		{
			echo "<td></td>";
			echo "<td></td>";
			echo "<td></td>";
			echo "<td></td>";
		}
		echo "</tr>";
	}
	echo "</table>";
	echo "</form>";
	disconnect_db($bdd);
}
else
	echo "ERROR: connect db";
echo "<a href='admin.php'>Back</a>";
?>
