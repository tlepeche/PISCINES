<?PHP
include("header.php");
include("bdd/bdd.php");
echo "<table class=pokeinfo>";
if (!($_POST['info']))
	$id = 0;
else
	$id = $_POST['info'];
if ($bdd = connect_db())
{
	$sql = "SELECT * FROM pokedex";
	$req = mysqli_query($bdd, $sql);
	if ($data = mysqli_fetch_assoc($req))
		do 	{
			if ($data['id'] == $id)
			{
				if ($data['type2'] == 0)
					$col = 2;
				else
					$col = 3;
				$nb = $data['id'];
				if ($nb < 10)
					$nb = '#00';
				else if ($nb < 100)
					$nb = '#0';
				else
					$nb = '#';
				echo"<tr class=pokeinfo>";
				echo"<th class=title colspan=2 >";
				echo$nb.$data['id']." ".$data['name']."\n</th>";
				echo"</tr>";
				echo"<tr class=pokeinfo>";
				echo"<td colspan=2 style='height:80px;width:80px;'>";
				echo"<img src=".$data['vlimg']."></td>";
				echo"</tr>";
				$sql_t = "SELECT * FROM types";
				$req_t = mysqli_query($bdd, $sql_t);
				if ($data_t = mysqli_fetch_assoc($req_t))
					do {
						if ($data_t['id'] == $data['type1'])
							$t1 = $data_t['name'];
						if ($data_t['id'] == $data['type2'])
						{
							if ($data['type2'] == 0)
								$t2 = NULL;
							else
								$t2 = $data_t['name'];
						}
					}
				while ($data_t = mysqli_fetch_assoc($req_t));
				if ($t2 == NULL)
				{
					echo"<tr class=pokeinfo>";
					echo"<td colspan=2><p class='c_type".$data['type1']."'>".$t1."</p></td>";
					echo"</tr>";
				}
				else
				{
					echo"<tr>";
					echo"<td class=pokeinfo ><p class='c_type".$data['type1']."'>$t1</p></td><td><p class='c_type".$data['type2']."'>$t2</p></td>";
					echo"</tr>";
				}
				echo"<tr class=pokeinfo>";
				echo"<td class=pokeinfo>";
				echo"<b id=price>".$data['price']."<img id=pkdol src=http://img.xooimage.com/files9//8/d/e/pokedollar-2-2a2ac4e.png ></b>";
				echo"</td>";
			}
		}
	while ($data = mysqli_fetch_assoc($req));
	echo"<td class=pokeinfo>";
	echo"<form  id=order action='http://rush00.local.42.fr:8080/add_cart.php' method=POST>";
	echo"<input type='hidden' name='pkid' value=".$id." />";
	echo"<input type='number' name='quantity' value='1' min='1' max='10'/> ";
	echo"<input type='submit' name='submit' value='Add to cart' />";
	echo"</form>";
	echo"</td>";
	echo"</tr>";
	disconnect_db($bdd);
}
else
	echo "<tr><td>DB CONNECTION ERROR</td></tr>";
echo "</table>";
echo "<p class=back><a href='http://rush00.local.42.fr:8080/index.php'>Retour a la page principale</a></p>";
include("footer.php");
?>
