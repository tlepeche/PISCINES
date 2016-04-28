<?PHP
class Tyrion extends Lannister {
	public $relationship = brother;

	public function sleepWith($var) {
		if ($var->family == 'Lannister')
			print("Not even if I'm drunk !\n");
		else
			print("Let's do this.\n");
	}
}
?>
