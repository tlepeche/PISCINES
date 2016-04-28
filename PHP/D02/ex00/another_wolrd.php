#!/usr/bin/php
<?PHP
if ($argv[1] !== NULL)
{
	$str =  preg_replace('/[ \t]+/', ' ', trim($argv[1]));
	echo"$str\n";
}
?>
