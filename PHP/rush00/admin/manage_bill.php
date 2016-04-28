<?php
include("../bdd/bdd.php");
include("auth.php");
if ($bdd = connect_db())
{
	$req = "SELECT * FROM bill ORDER BY log_id, cmd_id";
	$res = mysqli_query($bdd, $req);
	echo "<table>";
	while ($data = mysqli_fetch_assoc($res))
	{
		$uid = $data['log_id'];
		if ($bddu = connect_db())
		{
			$requ = "SELECT * FROM login WHERE id = '$uid'";
			$resu = mysqli_query($bddu, $requ);
			if (!$datau = mysqli_fetch_assoc($resu))
				echo "ERROR: select db";
			$logn = $datau['login'];
			disconnect_db($bddu);
		}
		else
			echo "ERROR: connect db";
		echo "<tr>";
		echo "<td>".$data['id']."</td>";
		echo "<td>$logn</td>";
		echo "<td>".$data['cmd_id']."</td>";
		echo "<td>".$data['date']."</td>";
		echo "<td>".$data['total']."</td>";
		echo "<tr>";
	}
	disconnect_db($bdd);
	echo "</table>";
}
else
	echo "ERROR: connect db";
echo "<a href='admin.php'>Back</a>"
?>
