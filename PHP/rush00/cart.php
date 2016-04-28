<?php
include("bdd/bdd.php");
include("header.php");
session_start();
if (isset($_SESSION['id']))
{
	$id = $_SESSION['id'];
	$tab = "cart";
	$ord = TRUE;
}
else
{
	if (!isset($_SESSION['tmp']))
		$_SESSION['tmp'] = time();
	$id = $_SESSION['tmp'];
	$tab = "cart_tmp";
	$ord = FALSE;
}
if (isset($_POST['submit']))
{
	foreach ($_POST['submit'] as $key => $val)
		$idp = $key;
	if ($bdd = connect_db())
	{
		$sql = "DELETE FROM $tab WHERE pkm_id = '$idp' AND log_id = '".$id."'";
		if (!mysqli_query($bdd, $sql))
			echo mysqli_error($bdd);
	}
}

if ($bdd = connect_db())
{
	$req = "SELECT $tab.qty, $tab.pkm_id, pokedex.name, pokedex.price, pokedex.simg
		FROM $tab, pokedex
		WHERE pokedex.id = $tab.pkm_id and $tab.log_id = '$id'";
	$res = mysqli_query($bdd, $req);
	$data = mysqli_fetch_assoc($res);
	if ($data == NULL)
	{
		$emp = TRUE;
		echo "<p>Your cart is empty !</p>";
	}
	else
	{
		$emp = FALSE;
		echo "<table class='tab_cart'>";
		echo "<tr>";
		echo "<th class='th_cart'>Image</th>";
		echo "<th class='th_cart'>Product</th>";
		echo "<th class='th_cart'>Quantity</th>";
		echo "<th class='th_cart'>Price</th>";
		echo "<th class='th_cart'>Del</th>";
		echo "</tr>";
		do {
			echo "<tr>";
			$price = $data['price'] * $data['qty'];
			$total += $price;
			echo "<td class='td_cart'><img src='".$data['simg']."'></td>";
			echo "<td class='td_cart'>".$data['name']."</td>";
			echo "<td class='td_cart'>".$data['qty']."</td>";
			echo "<td class='td_cart'>".$price."</td>";
			echo "<td class='td_cart'><form action='cart.php' method='POST'>";
			echo "<input type='submit' name='submit[".$data['pkm_id']."]' value='X'>";
			echo "</form></td>";
			echo "</tr>";
		} while ($data = mysqli_fetch_assoc($res));
		mysqli_free_result($res);
		echo "<tr class='td_cart'><th class='th_cart' colspan='5'>Total : ".$total."</th></tr>";
		echo "</table>";
	}
	disconnect_db($bdd);
}
else
	echo "ERROR: connect db";
if (!$ord or $emp)
	$dis = "disabled";
else
	$dis = "";
if (!$ord)
	echo "<p class='msg_cart'>Login required</p>";
echo "<form action='order.php' method='POST'>";
echo "<input class='btn_cart' type='submit' name='order' value='Order' $dis>";
echo "</form>";
echo "<a href='http://rush00.local.42.fr:8080/index.php'>Back</a>";
include("footer.php");
?>
