<?PHP
session_start();
$log = $_SESSION['loggued_on_user'];
if ($log != "")
{
	if ($_POST['msg'] != "")
	{
		if(file_exists("./../private/chat") == true)
			$chat = unserialize(file_get_contents("./../private/chat"));
		date_default_timezone_set("Europe/Paris");
		$time = time();
		$msg = $_POST['msg'];
		$tab['login'] = $log;
		$tab['time'] = $time;
		$tab['msg'] = $msg;
		$chat[] = $tab;
		file_put_contents("./../private/chat", serialize($chat), LOCK_EX);
	}
}
?>
<html>
	<head>
		<script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
	</head>
	<body>
		<form action="speak.php" method=post>
			<input type=text name=msg style="width=50%"/>
			<input type=submit name=submit value="Send"/>
		</form>
	</body>
</html>
