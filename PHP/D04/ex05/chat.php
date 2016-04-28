<?PHP
if(file_exists("./../private/chat") == true)
	$chat = unserialize(file_get_contents("./../private/chat"));
date_default_timezone_set("Europe/Paris");
foreach($chat as $elem)
{
?>
	<?PHP echo date("[H:i]", $elem['time']);?> <b><?PHP echo $elem['login']?></b> <?PHP echo":".$elem['msg'];?><br />
<?PHP
}
?>
