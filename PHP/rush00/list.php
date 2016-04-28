<?PHP
include("bdd/bdd.php");
if ($bdd = connect_db())
{
	if ($_POST['submit'] == "liste complete" || !($_POST['submit']))
		$stype = 1;
	else if ($_POST['submit'] == "Search")
	{
		$stype = 2;
		$list = mb_strtolower($_POST['pokename']);
	}
	else if ($_POST['submit'] == "Sort")
	{
		$stype = 3;
		$type = $_POST['type'];
	}
	$sql = "SELECT * FROM pokedex";
	$req = mysqli_query($bdd, $sql);
	$y = 1;
	if ($data = mysqli_fetch_assoc($req))
		do 	{
			if ($data['type2'] == 0)
				$col = 1;
			else
				$col = 2;
			$ok = 0;
			$nb = $data['id'];
			if ($nb < 10)
				$nb = '#00';
			else if ($nb < 100)
				$nb = '#0';
			else
				$nb = '#';
			if ($stype == 2 && (strpos(mb_strtolower($data['name']), $list) !== FALSE) || $stype == 1)
				$ok = 1;
			else if ($stype == 3 && ($data['type1'] == $type || $data['type2'] == $type))
				$ok = 1;
			if ($data['id'] == 0)
				$ok = 0;
			if ($y == 1)
				echo"<tr>";
			if ($ok == 1)
			{
				echo"<td>";
				echo"<form action='http://rush00.local.42.fr:8080/info.php' method='POST'>";
				echo"<table id=list>";
				echo"<tr class=entete>";
				echo"<td align=center>";
				echo"<p><span class=index>".$nb.$data['id']."</span> ";
				echo"<b>".$data['name']."</b></p>";
				echo"</td>";
				echo"</tr>";
				echo"<tr class=pict>";
				echo"<td align=center>";
				echo"<input type='image' src=".$data['limg']." name='info' value=".$data['id']." />";
				echo"</td>";
				echo"</tr>";
				$sql_t = "SELECT * FROM types";
				$req_t = mysqli_query($bdd, $sql_t);
				$case = 1;
				if ($data_t = mysqli_fetch_assoc($req_t))
					do {
						if ($data_t['id'] == $data['type1'])
							$t1 = $data_t['simg'];
						if ($data_t['id'] == $data['type2'])
						{
							if ($data['type2'] == 0)
								$t2 = NULL;
							else
								$t2 = $data_t['simg'];
						}
					}
				while ($data_t = mysqli_fetch_assoc($req_t));
				if ($t2 == NULL)
				{
					echo"<tr class=typ>";
					echo"<td align=center>";
					echo" <img src=".$t1." > <img>";
					echo"</td>";
					echo"</tr>";
				}
				else
				{
					echo"<tr class=typ>";
					echo"<td align=center>";
					echo"<img src=".$t1." > <img src=".$t2." >";
					echo"</td>";
					echo"</tr>";
				}
				echo"</tr>";
				echo"</table>";
				echo"</form>";
				echo"</td>";
			}
			if ($y == 6)
			{
				echo"</tr>";
				$y = 1;
			}
			else if ($ok == 1)
				$y++;
		}
	while ($data = mysqli_fetch_assoc($req));
	disconnect_db($bdd);
}
?>
