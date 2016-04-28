<?php
include("../bdd/bdd.php");
include("auth.php");
if (isset($_POST['modif']))
{
	foreach ($_POST['modif'] as $key => $val)
		$mid = $key;
	echo "$mid";
	if ($bdd = connect_db())
	{
		$req = "SELECT * FROM pokedex WHERE id = '$mid'";
		$res = mysqli_query($bdd, $req);
		$data = mysqli_fetch_assoc($res);
		if ($data == NULL)
			echo "error";
		$pkid = $data['id'];
		$pkname = $data['name'];
		$ty1 = $data['type1'];
		$ty2 = $data['type2'];
		$prc = $data['price'];
		$lig = $data['limg'];
		$sig = $data['simg'];
		$vig = $data['vlimg'];
		disconnect_db($bdd);
	}
	else
		echo "ERROR: connect db";
}
else if (isset($_POST['del']))
{
	foreach ($_POST['del'] as $key => $val)
		$mid = $key;
	if ($bdd = connect_db())
	{
		$req = "DELETE FROM pokedex WHERE id = '$mid'";
		if (!mysqli_query($bdd, $req))
			echo mysqli_error($bdd);
		disconnect_db($bdd);
	}
	header("Location: del_pkm.php");
}
?>
<html>
	<body>
		<form action="add_pkm.php" method="POST">
			<table>
				<tr>
					<td>Id</td>
					<td><input type="number" name="pkm_id" value="<?php echo $pkid; ?>" required></td>
				</tr>
				<tr>
					<td>Name</td>
					<td><input type="text" name="pkm_name" value="<?php echo $pkname; ?>" required></td>
				</tr>
				<tr>
					<td>Type 1</td>
					<td>
					<select name="pkm_type1">
							<option value="1" <?php if ($ty1 == 1) echo "selected"; ?>>Acier</option>
							<option value="2" <?php if ($ty1 == 2) echo "selected"; ?>>Dragon</option>
							<option value="3" <?php if ($ty1 == 3) echo "selected"; ?>>Elecrtik</option>
							<option value="4" <?php if ($ty1 == 4) echo "selected"; ?>>Feu</option>
							<option value="5" <?php if ($ty1 == 5) echo "selected"; ?>>Insecte</option>
							<option value="6" <?php if ($ty1 == 6) echo "selected"; ?>>Plante</option>
							<option value="7" <?php if ($ty1 == 7) echo "selected"; ?>>Psy</option>
							<option value="8" <?php if ($ty1 == 8) echo "selected"; ?>>Sol</option>
							<option value="9" <?php if ($ty1 == 9) echo "selected"; ?>>Tenebres</option>
							<option value="10" <?php if ($ty1 == 10) echo "selected"; ?>>Combat</option>
							<option value="11" <?php if ($ty1 == 11) echo "selected"; ?>>Eau</option>
							<option value="13" <?php if ($ty1 == 13) echo "selected"; ?>>Glace</option>
							<option value="14" <?php if ($ty1 == 14) echo "selected"; ?>>Normal</option>
							<option value="15" <?php if ($ty1 == 15) echo "selected"; ?>>Poison</option>
							<option value="16" <?php if ($ty1 == 16) echo "selected"; ?>>Roche</option>
							<option value="17" <?php if ($ty1 == 17) echo "selected"; ?>>Spectre</option>
							<option value="18" <?php if ($ty1 == 18) echo "selected"; ?>>Vol</option>
						</select>
					</td>
				</tr>
				<tr>
					<td>Type 2</td>
					<td>
						<select name="pkm_type2">
							<option value="0" <?php if ($ty2 == 0) echo "selected"; ?>>Aucun</option>
							<option value="1" <?php if ($ty2 == 1) echo "selected"; ?>>Acier</option>
							<option value="2" <?php if ($ty2 == 2) echo "selected"; ?>>Dragon</option>
							<option value="3" <?php if ($ty2 == 3) echo "selected"; ?>>Elecrtik</option>
							<option value="4" <?php if ($ty2 == 4) echo "selected"; ?>>Feu</option>
							<option value="5" <?php if ($ty2 == 5) echo "selected"; ?>>Insecte</option>
							<option value="6" <?php if ($ty2 == 6) echo "selected"; ?>>Plante</option>
							<option value="7" <?php if ($ty2 == 7) echo "selected"; ?>>Psy</option>
							<option value="8" <?php if ($ty2 == 8) echo "selected"; ?>>Sol</option>
							<option value="9" <?php if ($ty2 == 9) echo "selected"; ?>>Tenebres</option>
							<option value="10" <?php if ($ty2 == 10) echo "selected"; ?>>Combat</option>
							<option value="11" <?php if ($ty2 == 11) echo "selected"; ?>>Eau</option>
							<option value="13" <?php if ($ty2 == 13) echo "selected"; ?>>Glace</option>
							<option value="14" <?php if ($ty2 == 14) echo "selected"; ?>>Normal</option>
							<option value="15" <?php if ($ty2 == 15) echo "selected"; ?>>Poison</option>
							<option value="16" <?php if ($ty2 == 16) echo "selected"; ?>>Roche</option>
							<option value="17" <?php if ($ty2 == 17) echo "selected"; ?>>Spectre</option>
							<option value="18" <?php if ($ty2 == 18) echo "selected"; ?>>Vol</option>
						</select>
					</td>
				</tr>
				<tr>
					<td>Price</td>
					<td><input type="number" name="price" value="<?php echo $prc;?>" required></td>
				</tr>
				<tr>
					<td>Large image</td>
					<td><input type="text" name="limg" value="<?php echo $lig; ?>" required></td>
				</tr>
				<tr>
					<td>Small image</td>
					<td><input type="text" name="simg" value="<?php echo $sig; ?>" required></td>
				</tr>
				<tr>
					<td>Very large image</td>
					<td><input type="text" name="vlimg" value="<?php echo $vig; ?>" required></td>
				</tr>
				<tr>
					<td><input type="submit" name="submit" value="Validate"></td>
				</tr>
			</table>
		</form>
<a href="del_pkm.php">Back to list</a>
	</body>
</html>
