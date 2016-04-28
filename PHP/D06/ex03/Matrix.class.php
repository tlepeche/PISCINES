<?php
require_once("Vertex.class.php");

Class Matrix {

	const IDENTITY = 1;
	const SCALE = 2;
	const RX = 3;
	const RY = 4;
	const RZ = 5;
	const TRANSLATION = 6;
	const PROJECTION = 7;
	private $_matrix = array();
	public static $verbose = FALSE;

	public function __construct($kwargs) {
		if (array_key_exists('preset', $kwargs)) {
			$preset = $kwargs['preset'];
			if ($preset == self::IDENTITY) {
				$this->buildMIdent();
				$type = "IDENTITY";
			}
			else if ($preset == self::SCALE) {
				if (array_key_exists('scale', $kwargs)) {
					$scale = $kwargs['scale'];
					$this->buildMIdent();
					$this->buildMScale($scale);
					$type = "SCALE preset";
				} else {
					print("ERROR: scale undefined".PHP_EOL);
					return;
				}
			}
			else if ($preset == self::RX) {
				$angle = $kwargs['angle'];
				$this->buildMIdent();
				$this->buildMRX($angle);
				$type = "Ox ROTATION preset";
				if (array_key_exists('angle', $kwargs)) {
				} else {
					print("ERROR: angle undefined".PHP_EOL);
					return;
				}
			}
			else if ($preset == self::RY) {
				if (array_key_exists('angle', $kwargs)) {
					$angle = $kwargs['angle'];
					$this->buildMIdent();
					$this->buildMRY($angle);
					$type = "Oy ROTATION preset";
				} else {
					print("ERROR: angle undefined".PHP_EOL);
					return;
				}
			}
			else if ($preset == self::RZ) {
				if (array_key_exists('angle', $kwargs)) {
					$angle = $kwargs['angle'];
					$this->buildMIdent();
					$this->buildMRZ($angle);
					$type = "Oz ROTATION preset";
				} else {
					print("ERROR: angle undefined".PHP_EOL);
					return;
				}
			}
			else if ($preset == self::TRANSLATION) {
				if (array_key_exists('vtc', $kwargs)) {
					$vtc = $kwargs['vtc'];
					$this->buildMIdent();
					$this->buildMTranslat($vtc);
					$type = "TRANSLATION preset";
				} else {
					print("ERROR: vtc undefined".PHP_EOL);
					return;
				}
			}
			else if ($preset == self::PROJECTION) {
				if (array_key_exists('fov', $kwargs)) {
					$fov = $kwargs['fov'];
				} else {
					print("ERROR: fov undefined".PHP_EOL);
					return;
				}
				if (array_key_exists('ratio', $kwargs)) {
					$ratio = $kwargs['ratio'];
				} else {
					print("ERROR: ratio undefined".PHP_EOL);
					return;
				}
				if (array_key_exists('near', $kwargs)) {
					$near = $kwargs['near'];
				} else {
					print("ERROR: near undefined".PHP_EOL);
					return;
				}
				if (array_key_exists('far', $kwargs)) {
					$far = $kwargs['far'];
				} else {
					print("ERROR: far undefined".PHP_EOL);
					return;
				}
				$this->_OpenGLPerspective($fov, $ratio, $near, $far);
				$type = "PROJECTION preset";
			} else {
				print("ERROR: unknown preset".PHP_EOL);
				return;
			}
		}
		else if (array_key_exists('matrix', $kwargs)) {
			$this->_matrix = $kwargs['matrix'];
			$type = "new";
		} else {
			print ("ERROR: preset undefined".PHP_EOL);
			return;
		}
		if (self::$verbose and $type != "new")
			print("Matrix ".$type." instance constructed".PHP_EOL);
	}

	public function __destruct() {
		if (self::$verbose)
			print("Matrix instance destructed".PHP_EOL);
	}

	public function __toString() {
		return ($this->printMatrix());
	}

	public static function doc() {
		$str = file_get_contents("Matrix.doc.txt");
		print ($str);
	}

	public function mult($rhs) {
		$m1 = $rhs->getMatrix();
		$m2 = $this->_matrix;
		
		$i = 0;
		while ($i < 4) {
			$j = 0;
			while ($j < 4) {
				$k = 0;
				$nm[$j][$i] = 0;
				while ($k < 4) {
					$nm[$j][$i] += $m1[$k][$i] * $m2[$j][$k];
					$k++;
				}
				$j++;
			}
			$i++;
		}
		$new = new Matrix(array('matrix' => $nm));
		return ($new);
	}

	public function transformVertex($vtx)
	{
		$m = $this->_matrix;
		$v[0] = $vtx->getX();
		$v[1] = $vtx->getY();
		$v[2] = $vtx->GetZ();
		$v[3] = $vtx->getW();

		$i = 0;
		while ($i < 4) {
			$j = 0;
			$w[$i] = 0;
			while ($j < 4) {
				$w[$i] += $m[$i][$j] * $v[$j];
				$j++;
			}
			$i++;
		}
		$new = new Vertex(array('x' => $w[0], 'y' => $w[1], 'z' => $w[2],
			'w' =>$w[3]));
		return ($new);
	}

	private function buildMIdent()
	{
		$i = 0;
		while ($i < 4) {
			$j = 0;
			while ($j < 4) {
				if ($i == $j)
					$this->_matrix[$i][$j] = 1.0;
				else
					$this->_matrix[$i][$j] = 0.0;
				$j++;
			}
			$i++;
		}
	}

	private function buildMScale($scale) {
		$this->_matrix[0][0] *= $scale;
		$this->_matrix[1][1] *= $scale;
		$this->_matrix[2][2] *= $scale;
	}

	private function buildMTranslat($vtc) {
		$this->_matrix[0][3] += $vtc->getX();
		$this->_matrix[1][3] += $vtc->getY();
		$this->_matrix[2][3] += $vtc->getZ();
	}

	private function buildMRX($angle) {
		$this->_matrix[1][1] = cos($angle);
		$this->_matrix[1][2] = -sin($angle);
		$this->_matrix[2][1] = sin($angle);
		$this->_matrix[2][2] = cos($angle);
	}

	private function buildMRZ($angle) {
		$this->_matrix[0][0] = cos($angle);
		$this->_matrix[0][1] = -sin($angle);
		$this->_matrix[1][0] = sin($angle);
		$this->_matrix[1][1] = cos($angle);
	}

	private function buildMRY($angle) {
		$this->_matrix[0][0] = cos($angle);
		$this->_matrix[0][2] = sin($angle);
		$this->_matrix[2][0] = -sin($angle);
		$this->_matrix[2][2] = cos($angle);
	}

	private function _OpenGLPerspective($fov, $ratio, $near, $far) {
		$scale = tan(deg2rad($fov * 0.5)) * $near;
		$right = $ratio * $scale;
		$left = -$right;
		$top = $scale;
		$bottom = -$top;
		self::_OpenGLFrustrum($left, $right, $bottom, $top, $near, $far);
	}

	private function _OpenGLFrustrum($left, $right, $bottom, $top, $near, $far) {
		$this->_matrix[0][0] = (2 * $near) / ($right - $left);
		$this->_matrix[0][1] = 0;
		$this->_matrix[0][2] = ($right + $left) / ($right - $left);
		$this->_matrix[0][3] = 0;

		$this->_matrix[1][0] = 0;
		$this->_matrix[1][1] = (2 * $near) / ($top - $bottom);
		$this->_matrix[1][2] = ($top + $bottom) / ($top - $bottom);
		$this->_matrix[1][3] = 0;

		$this->_matrix[2][0] = 0;
		$this->_matrix[2][1] = 0;
		$this->_matrix[2][2] = -(($far + $near) / ($far - $near));
		$this->_matrix[2][3] = -((2 * $far * $near) / ($far - $near));

		$this->_matrix[3][0] = 0;
		$this->_matrix[3][1] = 0;
		$this->_matrix[3][2] = -1;
		$this->_matrix[3][3] = 0;
	}

	private function printMatrix()
	{
		$str = "M | vtcX | vtcY | vtcZ | vtxO".PHP_EOL;
		$str = $str."-----------------------------".PHP_EOL;
		$i = 0;
		$c = 'x';
		while ($i < 4)
		{
			$str = $str.$c." | ";
			$c++;
			if ($i == 2)
				$c = 'w';
			$j = 0;
			while ($j < 4)
			{
				$n = number_format($this->_matrix[$i][$j], 2, '.', '');
				$str = $str.$n;
				if ($j != 3)
					$str = $str." | ";
				$j++;
			}
			if ($i != 3)
			$str = $str.PHP_EOL;
			$i++;
		}
		return ($str);
	}

# **************************************************************************** #
#                             GETTERS / SETTERS                                #
# **************************************************************************** #

	public function getMatrix() {
		return ($this->_matrix);
	}
}

?>
