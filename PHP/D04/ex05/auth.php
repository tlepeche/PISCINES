<?PHP
function auth($login, $passwd)
{
	$registre = unserialize(file_get_contents("./../private/passwd"));
	foreach ($registre as $elem)
	{
		if ($elem['login'] == $login && $elem['passwd'] == hash("whirlpool", $passwd))
			return TRUE;
	}
	return FALSE;
}
?>
