<?PHP include("./header.php");?>
		<div align=center class="research">
		<div>
<fieldset>
<legend>Liste</legend>
			<form action="http://rush00.local.42.fr:8080/index.php" method=POST>
			<input class=fl type="submit" name=submit value="liste complete"  />
			</form>
</fieldset>
		</div>
		<div class=s_type title=search style="display:inline-block">
		<fieldset>
			<legend>Recherche par type</legend>
			<form action="http://rush00.local.42.fr:8080/index.php" name=type method=POST>
				<table>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/b/b7/Type_miniat_acier.png></img></td>
						<td><input type="radio" id=type name="type" value="1"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/1/1e/Type_miniat_dragon.png ></img></td>
						<td><input type="radio" id=type name="type" value="2"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/4/41/Type_miniat_%C3%A9lectrique.png ></img></td>
						<td><input type="radio" id=type name="type" value="3"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/6/62/Type_miniat_feu.png ></img></td>
						<td><input type="radio" id=type name="type" value="4"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/9/92/Type_miniat_insecte.png ></img></td>
						<td><input type="radio" id=type name="type" value="5"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/d/dc/Type_miniat_plante.png ></img></td>
						<td><input type="radio" id=type name="type" value="6"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/2/26/Type_miniat_psy.png ></img></td>
						<td><input type="radio" id=type name="type" value="7"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/5/50/Type_miniat_sol.png ></img></td>
						<td><input type="radio" id=type name="type" value="8"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/8/89/Type_miniat_t%C3%A9n%C3%A8bres.png ></img></td>
						<td><input type="radio" id=type name="type" value="9"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/7/71/Type_miniat_combat.png ></img></td>
						<td><input type="radio" id=type name="type" value="10"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/a/a2/Type_miniat_eau.png ></img></td>
						<td><input type="radio" id=type name="type" value="11"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/c/cb/Type_miniat_glace.png ></img></td>
						<td><input type="radio" id=type name="type" value="13"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/9/91/Type_miniat_normal.png ></img></td>
						<td><input type="radio" id=type name="type" value="14"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/4/4c/Type_miniat_poison.png ></img></td>
						<td><input type="radio" id=type name="type" value="15"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/e/e6/Type_miniat_roche.png ></img></td>
						<td><input type="radio" id=type name="type" value="16"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/2/2e/Type_miniat_spectre.png ></img></td>
						<td><input type="radio" id=type name="type" value="17"/></td>
					</tr>
					<tr>
						<td><img src=http://www.pokepedia.fr/images/4/46/Type_miniat_vol.png ></img></td>
						<td><input type="radio" id=type name="type" value="18"/></td>
					</tr>
					<tr>
						<td>
							<br /><input class=sort_b type="submit" name=submit value="Sort" />
						</td>
					</tr>
				</table>
				</form>
			</fieldset>
		</div>
		<div>
				<fieldset>
					<legend>Recherche</legend>
					<form action="http://rush00.local.42.fr:8080/index.php" method=POST>
						<input id=txt_search type="text" name="pokename" />
						<input type="submit" name="submit" value="Search"/>
					</form>
				</fieldset>
			</div> 
		</div>
		<div class=list align=center>
			<table align=center>
				<?PHP include("list.php"); ?>
			</table>
		</div>
		<?php include("footer.php"); ?>
