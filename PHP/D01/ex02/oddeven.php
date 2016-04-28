#!/usr/bin/php
<?PHP
while (1)
{
	echo"Entrez un nombre: ";
	$answer = fgets(STDIN);
	if(!$answer)
		break;
	$answer = substr($answer, 0, -1);
	if (is_numeric($answer))
	{
		if (substr($answer, -1) % 2 == 0)
			echo"Le chiffre $answer est Pair\n";
		else
			echo"Le chiffre $answer est Impair\n";
	}
	else
		echo"'$answer' n'est pas un chiffre\n";
}
echo"\n";
?>
