<?php
include('mdp.php');

$con = mysqli_connect($host,$user,$userpass) or die("Impossible");
$sql="CREATE DATABASE pokebase_db";
mysqli_query($con,$sql) or die("fail to create database");
mysqli_select_db($con, "pokebase_db") or die("pas de base de donnees");
$filename = "pokebase_db.sql";
$templine = '';
$lines = file($filename);
foreach ($lines as $line)
{
if (substr($line, 0, 2) == '--' || $line == '')
    continue;

$templine .= $line;
if (substr(trim($line), -1, 1) == ';')
{
    mysqli_query($con,$templine) or print('Error performing query \'<strong>' . $templine . '\': ' . mysql_error() . '<br /><br />');
    $templine = '';
}
}
 echo "Tables imported successfully";
 mysqli_close($con);
?>
