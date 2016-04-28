<?PHP
foreach($_GET as $key => $val)
{
	if ($key == 'action')
		$action = $val;
	if ($key == 'name')
		$name = $val;
	if ($key == 'value')
		$valeur = $val;
}

if ($action == 'set')
{
	if ($name != NULL && $valeur != NULL)
		setcookie($name, $valeur, time()+3600);
}
else if ($action == 'get')
{
	if ($name != NULL)
		echo "$_COOKIE[$name]\n";
}
else if ($action == 'del')
{
	if ($name != NULL)
		setcookie($name, '42', time()-1);
}
?>
