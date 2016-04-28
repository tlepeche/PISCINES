<?php

function connect_db()
{
	if ($bdd = mysqli_connect('localhost', 'root', 'sauciflon','pokebase_db'))
		return ($bdd);
	else
		return FALSE;
}

function disconnect_db($bdd)
{
	if (mysqli_close($bdd))
		return TRUE;
	else
		return FALSE;
}
