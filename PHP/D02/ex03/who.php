#!/usr/bin/php
<?PHP
date_default_timezone_set("Europe/Paris");

$fd = fopen("/var/run/utmpx", 'r');
$line = fread($fd, 628);
$line = fread($fd, 628);
while($line = fread($fd, 628))
{
	$tab = unpack ("a256login/a4id/a32line/ipid/itype/i2time/a256host/i16pad", $line);
	if ($tab["type"] == 7)
		$new[] = $tab;
}
sort($new);
foreach($new as $tab)
{
	echo($tab["login"]." ".$tab["line"]."  ".date("M d H:i", $tab["time1"])."\n");
}
?>
