#!/usr/bin/php
<?PHP
if ($argv[1] != NULL)
{
	$curl = curl_init($argv[1]);
	curl_setopt($curl, CURLOPT_RETURNTRANSFER, true);
	curl_setopt($curl, CURLOPT_COOKIESESSION, true); 
	$return = curl_exec($curl);
	preg_match_all("/<img.+src=(.*?)[ >]/i",$return, $tab);
	if ($tab[1] != NULL)
	{
		if (preg_match("/^http[s]*:\/\/(.+)$/", $argv[1]) == 1)
			preg_match("/^http[s]*:\/\/(.+)$/", $argv[1], $dir);
		else
			$dir[1] = $argv[1];
		if (file_exists($dir[1]) == true)
		{
			echo"Directory already exists\n";
			return ;
		}
		if (mkdir($dir[1]) == false)
			return ;
		foreach($tab[1] as $elem)			
		{
			$elem = preg_replace("/[\"\']/", "", $elem);
			if (preg_match("/http[s]*:\/\/(.)+/", $elem) == 0)
			{
				if (preg_match("/http[s]*:\/\/(.+)$/", $argv[1]) == 0)
					$path = "http://".$argv[1].'/'.$elem;
				else
					$path = $argv[1].'/'.$elem;
			}
			else
				$path = $elem;
			preg_match("/\/([^\/]+)$/i", $elem, $photo);
			$curl_2 = curl_init($path);
			curl_setopt($curl_2, CURLOPT_RETURNTRANSFER, true);
			$img = curl_exec($curl_2);
			curl_close($curl_2);
			$photo[1] = preg_replace("/[\"\']/", "", $photo[1]);
			$fd = fopen($dir[1].'/'.$photo[1], 'w');
			fwrite($fd, $img);
			fclose($fd);
		}
	}
	curl_close($curl);
}
?>
