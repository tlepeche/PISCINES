<?PHP
Class Color {
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	public static $verbose = false;

	/* CONSTRUCTOR */
	public function __construct ( array $kwargs )
	{
		if ( array_key_exists( 'rgb' , $kwargs))
		{
			$red = $this->setRED(($kwargs['rgb'] >> 16) & 0xFF);
			$green = $this->setGREEN(($kwargs['rgb'] >> 8) & 0xFF);
			$blue = $this->setBLUE(($kwargs['rgb'] >> 0) & 0xFF);
		}
		else
		{
			if ( array_key_exists( 'red' , $kwargs))
				$this->red = $this->setRed($kwargs['red']);
			else
				$this->red = 0;

			if ( array_key_exists( 'green' , $kwargs))
				$this->green = $this->setGreen($kwargs['green']);
			else
				$this->green = 0;

			if ( array_key_exists( 'blue' , $kwargs))
				$this->blue = $this->setBlue($kwargs['blue']);
			else
				$this->blue = 0;
		}
		if (self::$verbose == true)
			print($this." constructed.\n");
	}

	/* DESTROY */
	public function __destruct ()
	{
		if (self::$verbose == true)
			print($this." destructed.\n");
	}

	/* DOC */
	public function doc() { print(file_get_contents("./Color.doc.txt")) ; return ;}

		/* GETTERS */
		public function getRed() { return $this->red; }
		public function getGreen() { return $this->green ;}
		public function getBlue() { return $this->blue ;}

		/* SETTERS */
		public function setRed($red)
		{
			if ($red > 255)
				$this->red = 255;
			else if ($red < 0)
				$this->red = 0;
			else
				$this->red = intval($red);
			return $this->red;
		}
	public function setGreen($green)
	{
		if ($green > 255)
			$this->green = 255;
		else if ($green < 0)
			$this->green = 0;
		else
			$this->green = intval($green);
		return $this->green;
	}
	public function setBlue($blue)
	{
		if ($blue > 255)
			$this->blue = 255;
		else if ($blue < 0)
			$this->blue = 0;
		else
			$this->blue = intval($blue);
		return $this->blue;
	}

	private function _put_color($color) {
		if ($color > 99)
			return ($color);
		if ($color > 9)
			return (' '.$color);
		else
			return ('  '.$color);
	}

	/* TOSTRING */
	public function __toString() {
		return 'Color( red: '.$this->_put_color($this->red).', green: '.$this->_put_color($this->green).', blue: '.$this->_put_color($this->blue)." )";
	}


	/* OTHER FUNCTIONS */
	public function add($color)
	{
		$new = new Color (array ('red' => ($this->red + $color->red), 'green' => ($this->green + $color->green), 'blue' => ($this->blue + $color->blue)));
		return $new;
	}

	public function sub($color)
	{
		$new = new Color (array ('red' => ($this->red - $color->red), 'green' => ($this->green - $color->green), 'blue' => ($this->blue - $color->blue)));
		return $new;
	}

	public function mult($f)
	{
		$new = new Color (array ('red' => ($this->red * $f), 'green' => ($this->green * $f), 'blue' => ($this->blue * $f)));
		return $new;
	}
}
?>
