<?PHP
class NightsWatch {
	public $fight = "";

	public function recruit($var)
	{
		if($var instanceof IFighter)
		$this->fight = $this->fight.$var->fight();
	}

	public function fight() {
		print($this->fight);
	}
}
?>
