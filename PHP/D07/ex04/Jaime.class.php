<?PHP
class Jaime extends Lannister {
	public $relationship = brother;

	public function sleepWith($var) {
		if ($var->family == 'Lannister')
		{
		   	if ( $var->relationship == 'sister')
				print("With pleasure, but only in a tower in Winterfell, then.\n");
			else
				print("Not even if I'm drunk !\n");
		}
		else
			print("Let's do this.\n");
	}
}
?>
