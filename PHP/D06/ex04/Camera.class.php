<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Camera.class.php                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/15 19:01:15 by sduprey           #+#    #+#              #
#    Updated: 2015/04/15 19:01:15 by sduprey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Class Camera {

	private $_origin = NULL;
	private $_orientation = NULL;
	private $_width = 0;
	private $_height = 0;
	private $_fov = 0;
	private $_near = 0;
	private $_far = 0;
	private $_tT = NULL;
	private $_tR = NULL;
	private $_tmp = NULL;
	private $_proj = NULL;
	public static $verbose = FALSE;

	public function __construct($kwargs) {
		if (array_key_exists('origin', $kwargs)) {
			$this->_origin = $kwargs['origin'];
		} else {
			print("ERROR: origin undefined".PHP_EOL);
			return;
		}
		if (array_key_exists('orientation', $kwargs)) {
			$this->_orientation = $kwargs['orientation'];
		} else {
			print("ERROR: orientation undefined".PHP_EOL);
			return;
		}
		if (array_key_exists('width', $kwargs)) {
			$this->_width = $kwargs['width'];
		} else {
			$this->_width = 640;
		}
		if (array_key_exists('height', $kwargs)) {
			$this->_height = $kwargs['height'];
		} else {
			$this->_height = 480;
		}
		if (array_key_exists('fov', $kwargs)) {
			$this->_fov = $kwargs['fov'];
		} else {
			$this->_fov = 60;
		}
		if (array_key_exists('near', $kwargs)) {
			$this->_near = $kwargs['near'];
		} else {
			$this->_near = 1.0;
		}
		if (array_key_exists('far', $kwargs)) {
			$this->_far = $kwargs['far'];
		} else {
			$this->_far = 100.0;
		}
		$v = new Vector (array( 'dest' => $this->_origin));
		$oppv = $v->opposite();
		$this->_tT = new Matrix(array('preset' => Matrix::TRANSLATION, 'vtc' => $oppv));
		$this->_tR = $this->_orientation;
		$this->_tmp = $this->_tR->mult($this->_tT);
		$this->_proj = new Matrix(array('preset' => Matrix::PROJECTION, 'fov' => $this->_fov,
			'ratio' => $this->_width / $this->_height,
			'near' => $this->_near, 'far' => $this->_far));
		if (self::$verbose)
			print("Camera instance constructed".PHP_EOL);
	}

	public function __destruct() {
		print("Camera instance destructed".PHP_EOL);
	}

	public function __toString() {
		$str = "Camera( ".PHP_EOL;
		$str = $str."+ Origine: ";
		$str = $str.$this->_origin.PHP_EOL;
		$str = $str."+ tT:".PHP_EOL;
		$str = $str.$this->_tT.PHP_EOL;
		$str = $str."+ tR:".PHP_EOL;
		$str = $str.$this->_tR.PHP_EOL;
		$str = $str."+ tR->mult( tT ):".PHP_EOL;
		$str = $str.$this->_tmp.PHP_EOL;
		$str = $str."+ Proj:".PHP_EOL;
		$str = $str.$this->_proj.PHP_EOL;
		$str = $str.")";

		return ($str);
	}

	public function doc() {
		$str = file_get_contents("Camera.doc.txt");
		print($str.PHP_EOL);
	}

	public function watchVertex($worldVertex) {
		$x = $worldVertex->getX();
		$y = $worldVertex->getY();
		$z = $worldVertex->getZ();
		$w = $this->_width;
		$h = $this->_height;
		$nx = ($w / 2) * $x + ($w / 2);
		$ny = ($h / 2) * $y + ($h / 2);
		return new Vertex(array('x' => $nx, 'y' => $ny, 'z' => $z));
	}
}

?>
