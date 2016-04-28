<?PHP
Class UnholyFactory
{
	private $absorbed = array();

	public function __construct() {}
	public function __destruct() {}

	public function absorb($fighter)
	{
		if ($fighter instanceof Fighter)
		{
			$ok = 1;
			foreach ($this->absorbed as $key => $val)
			{
				if ($key == $fighter->getName())
					$ok = 0;
			}
			if ($ok == 1)
			{
				$this->absorbed[$fighter->getName()] = $fighter;
				print('(Factory absorbed a fighter of type ' . $fighter->getName(). ")\n");
			}
			else
				print("(Factory already absorbed a fighter of type " . $fighter->getName(). ")\n");
		}
		else
			print("(Factory can't absorb this, it's not a fighter)\n");
	}

	public function fabricate($fighter)
	{
		$ok = 0;
		foreach ($this->absorbed as $key => $val)
		{
			if ($key == $fighter)
				$ok = 1;
		}
		if ($ok == 1)
		{
			print('(Factory fabricates a fighter of type ' . $fighter. ")\n");
			return new $this->absorbed[$fighter];
		}
		else
			print("(Factory hasn't absorbed any fighter of type " . $fighter. ")\n");
	}
}
?>
