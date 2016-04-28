<?PHP
require_once 'Color.class.php';
Class Vertex {
	private $_x = 0.0;
	private $_y = 0.0;
	private $_z = 0.0;
	private $_w = 1.0;
	private $_color = array( 'rgb' => 0xFFFFFF );
	public static $verbose = false;

	/* CONSTRUCTOR */
	public function __construct (array $kwargs)
	{
		if (array_key_exists( 'x', $kwargs))
			$this->_x = $this->setX($kwargs['x']);
		else
		{
			echo"Error class require 'x' variable\n";
			exit ;
		}
		if (array_key_exists( 'y', $kwargs))
			$this->_y = $this->setY($kwargs['y']);
		else
		{
			echo"Error class require 'y' variable\n";
			exit ;
		}
		if (array_key_exists( 'z', $kwargs))
			$this->_z = $this->setZ($kwargs['z']);
		else
		{
			echo"Error class require 'z' variable\n";
			exit ;
		}
		if (array_key_exists( 'w', $kwargs))
			$this->_w = $this->setW($kwargs['w']);

		if (array_key_exists( 'color', $kwargs))
			$this->_color = ($kwargs['color']);
		else
			$this->_color = $this->setColor($this->_color);
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
			return 'Vertex( x: ' . number_format($this->_x, '2', '.', '') . ', y: ' . number_format($this->_y, '2', '.', '') . ', z:' . number_format($this->_z, '2', '.', '') . ', w:' . number_format($this->_w, '2', '.', '') . ', ' . $this->_color . ' )';
		else
			return 'Vertex( x: ' . number_format($this->_x, '2', '.', '') . ', y: ' . number_format($this->_y, '2', '.', '') . ', z:' . number_format($this->_z, '2', '.', '') . ', w:' . number_format($this->_w, '2', '.', '') . ' )';

	}

	/* DOC */
	public function doc() { print(file_get_contents("./Vertex.doc.txt")); return ;}

		/* GETTER */
		public function getX() { return $this->_x; }
		public function getY() { return $this->_y; }
		public function getZ() { return $this->_z; }
		public function getW() { return $this->_w; }
		public function getColor() { return $this->_color; }

		/* SETTERS */
		public function setX($x)
		{
			$this->_x = floatval($x);
			return $this->_x;
		}

	public function setY($y)
	{
		$this->_y = floatval($y);
		return $this->_y;
	}

	public function setZ($z)
	{
		$this->_z = floatval($z);
		return $this->_z;
	}

	public function setW($w)
	{
		$this->_w = floatval($w);
		return $this->_w;
	}

	public function setColor($color)
	{
		$this->_color = new Color ($color); 
		return $this->_color;
	}
}
?>
