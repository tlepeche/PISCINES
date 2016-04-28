<?php
include("../bdd/bdd.php");
include("auth.php");
if ($bdd = connect_db())
{
	$req = "SELECT * FROM pokedex ORDER BY id";
	$res = mysqli_query($bdd, $req);
	echo "<table>";
	echo "<form action='manage_pkm.php' method='POST'>";
	echo "<tr>";
	echo "<th>Id</th>";
	echo "<th>Image</th>";
	echo "<th>Name</th>";
	echo "<th>Type</th>";
	echo "<th>Price</th>";
	echo "<th>Modif.</th>";
	echo "<th>Delete</th>";
	echo "</tr>";
	$i = 0;
	while ($data = mysqli_fetch_assoc($res))
	{
		$nb = $data['id'];
		if ($nb < 10)
			$nb = "#00".$nb;
		else if ($nb < 100)
			$nb = "#0".$nb;
		else
			$nb = "#".$nb;
		if ($bdd_t = connect_db())
		{
			$req_t = "SELECT simg FROM types WHERE id = '".$data['type1']."'";
			$res_t = mysqli_query($bdd_t, $req_t);
			$data_t = mysqli_fetch_assoc($res_t);
		}
		else
			echo "ERROR: connect db";
		if ($bdd_st = connect_db())
		{
			$req_st = "SELECT simg FROM types WHERE id = '".$data['type2']."'";
			$res_st = mysqli_query($bdd_st, $req_st);
			$data_st = mysqli_fetch_assoc($res_st);
			disconnect_db($bdd_st);
		}
		echo "<tr>";
		echo "<td>".$nb."</td>";
		echo "<td><img src='".$data['simg']."'></td>";
		echo "<td>".$data['name']."</td>";
		echo "<td><img src='".$data_t['simg']."'>";
		if ($data['type2'] != 0)
			echo "<br /><img src='".$data_st['simg']."'>";
		echo "</td>";
		echo "<td>".$data['price']."</td>";
		echo "<td><input type='submit' name='modif[".$data['id']."]' value ='modif'></td>";
		echo "<td><input type='submit' name='del[".$data['id']."]' value ='X'></td>";
		echo "</tr>";
		$i++;
	}
	echo "</form>";
	echo "</table>";
	if ($i == 0)
		echo "<p>List is empty</p>";
}
else
	echo "ERROR: connect db";
?>
<html>
	<body>
		<a href="manage_pkm.php">Add Pokemon</a>
		<a href="admin.php">Back</a>
	</body>
</html>
