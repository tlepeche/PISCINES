<?PHP
Class Vector {
	private $_x = 0.0;
	private $_y = 0.0;
	private $_z = 0.0;
	private $_w = 0.0;
	public static $verbose = false;

	/* CONSTRUCTOR */
	public function __construct (array $kwargs)
	{
		if (array_key_exists( 'dest', $kwargs))
		{
			if (array_key_exists( 'orig', $kwargs))
				$origin = $kwargs['orig'];
			else
				$origin = new Vertex( array( 'x' => 0, 'y' => 0, 'z' => 0) );
			$this->_x =  $kwargs['dest']->getX() - $origin->getX();
			$this->_y =  $kwargs['dest']->getY() - $origin->getY();
			$this->_z =  $kwargs['dest']->getZ() - $origin->getZ();

		}
		else
		{
			echo"Error class require 'dest' variable\n";
			exit ;
		}
		if (self::$verbose == true)
			print($this." constructed\n");
	}

	/* DESTRUCTOR */
	public function __destruct () {
		if (self::$verbose == true)
			print($this." destructed\n");
	}


	/* TO STRING */
	public function __toString() {
		if (self::$verbose == true)
			return 'Vector( x:' . number_format($this->_x, '2', '.', '') . ', y:' . number_format($this->_y, '2', '.', '') . ', z:' . number_format($this->_z, '2', '.', '') . ', w:' . number_format($this->_w, '2', '.', '') . ' )';
	}

	/* DOC */
	public function doc() { print(file_get_contents("./Vector.doc.txt")); return ;}

		/* GETTER */
		public function getX() { return $this->_x; }
		public function getY() { return $this->_y; }
		public function getZ() { return $this->_z; }
		public function getW() { return $this->_w; }

		/* SETTERS (none)*/

		/* OTHER */
		public function magnitude() {
			return sqrt(pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2) ); }

		public function normalize()
		{
			$n_x = $this->_x / $this->magnitude();
			$n_y = $this->_y / $this->magnitude();
			$n_z = $this->_z / $this->magnitude();
			$ver = new Vertex( array( 'x' => $n_x, 'y' => $n_y, 'z' => $n_z) );
			return new Vector( array( 'dest' => $ver) );
		}

		public function add($vect)
		{
			$x2 = $this->getX() + $vect->getX();
			$y2 = $this->getY() + $vect->getY();
			$z2 = $this->getZ() + $vect->getZ();
			$ver_n = new Vertex( array( 'x' => $x2, 'y' => $y2, 'z' => $z2) );
			return new Vector( array( 'dest' => $ver_n) );
		}

		public function sub($vect)
		{
			$x2 = $this->getX() - $vect->getX();
			$y2 = $this->getY() - $vect->getY();
			$z2 = $this->getZ() - $vect->getZ();
			$ver_n = new Vertex( array( 'x' => $x2, 'y' => $y2, 'z' => $z2) );
			return new Vector( array( 'dest' => $ver_n) );
		}

		public function opposite()
		{
			$x2 = -$this->getX();
			$y2 = -$this->getY();
			$z2 = -$this->getZ();
			$ver_n = new Vertex( array( 'x' => $x2, 'y' => $y2, 'z' => $z2) );
			return new Vector( array( 'dest' => $ver_n) );
		}

		public function scalarProduct($f)
		{
			$x2 = $this->getX() * $f;
			$y2 = $this->getY() * $f;
			$z2 = $this->getZ() * $f;
			$ver_n = new Vertex( array( 'x' => $x2, 'y' => $y2, 'z' => $z2) );
			return new Vector( array( 'dest' => $ver_n) );
		}

		public function dotProduct($vect)
		{
			$div1 = $this->getX() * $vect->getX() + $this->getY() * $vect->getY() + $this->getZ() * $vect->getZ();
			return $div1;
		}

		public function cos($vect)
		{
			$div1 = $this->dotProduct($vect);
			$div2 = $this->magnitude() * $vect->magnitude();
			return $div1 / $div2;
		}

		public function crossProduct($vect)
		{
			$x2 = $this->getY() * $vect->getZ() - $this->getZ() * $vect->getY(); 
			$y2 = $this->getZ() * $vect->getX() - $this->getX() * $vect->getZ();
			$z2 = $this->getX() * $vect->getY() - $this->getY() * $vect->getX();
			$ver_n = new Vertex( array( 'x' => $x2, 'y' => $y2, 'z' => $z2) );
			return new Vector( array( 'dest' => $ver_n) );
		}
		
}
?>
