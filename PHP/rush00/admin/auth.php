<?php
session_start();
if (!isset($_SESSION['login']))
	$auth = FALSE;
else
	if ($_SESSION['lvl'] < 5)
		$auth = FALSE;
	else
		$auth = TRUE;
if ($auth == FALSE)
	header("Location: error401.html");
?>
<html>
	<head>
		<link rel='stylesheet' type='text/css' href='styles.css'>
	</head>
	<body>
