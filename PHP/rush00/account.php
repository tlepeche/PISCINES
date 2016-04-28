<?php
include("bdd/bdd.php");
include("header.php");
session_start();
if (isset($_SESSION['id']))
{
	$uid = $_SESSION['id'];

	if ($_POST['update'] == "Update")
	{
		$fname = $_POST['fname'];
		$lname = $_POST['lname'];
		$email = $_POST['email'];
		$addr = $_POST['addr'];
		$city = $_POST['city'];
		$state = $_POST['state'];
		$zip = $_POST['zip'];
		if($bdd = connect_db())
		{
			$req = "UPDATE address SET 
				first_name = ?,
				last_name = ?,
				email = ?,
				address = ?,
				city = ?,
				state = ?,
				zip = ?
				WHERE id = '$uid'";
			$req_pre = mysqli_prepare($bdd, $req);
			mysqli_stmt_bind_param($req_pre, "ssssssi", $fname, $lname, $email, $addr, $city, $state, $zip);
			mysqli_stmt_execute($req_pre);
		}
		else
			echo "ERROR: connect db";
	}
	if ($bdd = connect_db())
	{
		$req = "SELECT * FROM address WHERE id = '$uid'";
		$res = mysqli_query($bdd, $req);
		if(!$data = mysqli_fetch_assoc($res))
		{
			echo mysqli_error($bdd);
			echo "ERROR: select<br />";
		}
		else
		{
			$fname = $data['first_name'];
			$lname = $data['last_name'];
			$email = $data['email'];
			$addr = $data['address'];
			$city = $data['city'];
			$state = $data['state'];
			$zip = $data['zip'];
		}
		disconnect_db($bdd);
	}
	else
		echo "ERROR: connect db";
?>
<form action="account.php" method='POST'>
	<fieldset class='form_reg'>
		<legend>Shipping Address</legend>
		<table>
			<tr>
				<td>First name : </td>
				<td><input type="text" name="fname" value="<?php echo $fname; ?>" required></td>
			</tr>
			<tr>
				<td>Last name : </td>
				<td><input type="text" name="lname" value="<?php echo $lname; ?>"  required></td>
			</tr>
			<tr>
				<td>Email : </td>
				<td><input type="email" name="email" value="<?php echo $email; ?>" required></td>
			</tr>
			<tr>
				<td>Address : </td>
				<td><input type="text" name="addr" value="<?php echo $addr; ?>" required></td>
			</tr>
			<tr>
				<td>City : </td>
				<td><input type="text" name="city" value="<?php echo $city; ?>" required></td>
			</tr>
			<tr>
				<td>State : </td>
				<td><input type="text" name="state" value="<?php echo $state; ?>" required></td>
			</tr>
			<tr>
				<td>Zip : </td>
				<td><input type="number" name="zip" value="<?php echo $zip; ?>" min="1" required></td>
			</tr>
		</table>
	</fieldset>
	<fieldset class='form_reg'>
		<input type="submit" name="update" value="Update">
	</fieldset>
</form>
<?php
	if ($bdd = connect_db())
	{
		$req = "SELECT * FROM bill WHERE log_id = '$uid'";
		$res = mysqli_query($bdd, $req);
		echo "<table class='form_bill'>";
			echo "<th class='td_reg'>Id</th>";
			echo "<th class='td_reg'>Date</th>";
			echo "<th class='td_reg'>Total</th>";
		while ($data = mysqli_fetch_assoc($res))
		{
			echo "<tr>";
			echo "<td class='td_reg'>".$data['cmd_id']."</td>";
			echo "<td class='td_reg'>".$data['date']."</td>";
			echo "<td class='td_reg'>".$data['total']."</td>";
			echo "</tr>";
		}
		disconnect_db($bdd);
		echo "<table>";
	}
	else
		echo "ERROR: connect db";
}
else
{
	echo "<p>Login required</p>";
}
echo "<a href='http://rush00.local.42.fr:8080/index.php'>Retour</a>";
include("footer.php");
?>
