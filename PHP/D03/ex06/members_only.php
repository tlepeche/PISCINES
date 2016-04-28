<?PHP
foreach($_SERVER as $key => $val)
{
	if ($key == 'PHP_AUTH_USER')
		$user = $val;
	else if ($key == 'PHP_AUTH_PW')
		$pwd = $val;
}
$code = base64_encode($pwd);
if ($code == 'amFpbWVsZXNwZXRpdHNwb25leXM=' && $user == 'zaz')
{
	$img = file_get_contents("./../img/42.png");
	$img = base64_encode($img);
	echo"<html><body>\nBonjourZaz<br />\n<img src='data:image/png;base64,$img>\n</body></html>";
}
else
{
	$head = header("HTTP/1.0 401 Unauthorized");
	echo"<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
}
?>
