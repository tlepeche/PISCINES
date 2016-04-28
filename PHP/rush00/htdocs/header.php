<?php
session_start();
?>
<html>
	<head>
		<link rel="stylesheet" style="text/css" href="styles/styles.css">
	</head>
	</body>
		<table style="width:100%;" >
			<tr>
				<td id=left>
					<table>
						<tr>
							<td align=center>
								<a href="http://rush00.local.42.fr:8080/cart.php">
									<img src="http://fc06.deviantart.net/fs70/f/2010/208/7/6/Free_Avatar__PokeBag_by_TheArmamentarium.gif" title="panier" alt="panier"></img>
								</a>
							</td>
						</tr>
						<tr>
							<td id=text_cart><?PHP include("nb_prod.php"); ?></td>
						</tr>
					</table>
				</td>
				<td id="title">
					<img class="site" src="http://i42.tinypic.com/15cxzro.png">
				</td>
				<td id=right>
					<table align=right>
					<?PHP include("check_log.php"); ?>
				</td>
			</tr>
		</table>
