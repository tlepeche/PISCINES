<?PHP

include("bdd/bdd.php");
session_start();
if (isset($_SESSION['id']))
{
	$uid = $_SESSION['id'];
	$tt = "cart";
}
else if (isset($_SESSION['tmp']))
{
	$uid = $_SESSION['tmp'];
	$tt = "cart_tmp";
}
else
{
	$uid = 0;
	$tt = "cart";
}
$nb = 0;
if ($bdd = connect_db())
{
	$reqb = "SELECT qty FROM $tt WHERE log_id = '$uid'"; 
	$resb = mysqli_query($bdd, $reqb);
	while ($datab = mysqli_fetch_assoc($resb))
		$nb += $datab['qty'];
	disconnect_db($bdd);
}
echo "Panier";
if ($nb === 0)
	echo" est vide";
else
{
	echo": ".$nb." article";
	if ($nb > 1)
		echo"s";
}
?>
