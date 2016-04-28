<?PHP
abstract class Fighter {
	private $named = 'hi';

	public function __construct ($var){
		$this->named = $var;
	}

	abstract public function fight($fighter);
	public function getName() { return $this->named; }
}
?>
