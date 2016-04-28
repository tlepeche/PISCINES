<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Vertex.class.php                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/14 15:02:33 by sduprey           #+#    #+#              #
#    Updated: 2015/04/14 15:02:33 by sduprey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

require_once("Color.class.php");

Class Vertex {

	private			$_x = 0;
	private			$_y = 0;
	private			$_z = 0;
	private			$_w = 1.0;
	private			$_color = NULL;
	public static	$verbose = FALSE;

	public function __construct($kwargs) {
		if (array_key_exists('x', $kwargs)) {
			$this->setX($kwargs['x']);
		} else {
		}
		if (array_key_exists('y', $kwargs)) {
			$this->setY($kwargs['y']);
		} else {
		}
		if (array_key_exists('z', $kwargs)) {
			$this->setZ($kwargs['z']);
		} else {
		}
		if (array_key_exists('w', $kwargs)) {
			$this->setW($kwargs['w']);
		}
		if (array_key_exists('color', $kwargs)) {
			$this->_color = clone $kwargs['color'];
		} else {
			$this->_color = new Color(array('rgb' => 0xFFFFFF));
		}
		if (self::$verbose)
			print($this." constructed".PHP_EOL);
	}

	public function __destruct() {
		if (self::$verbose)
			print($this." destructed".PHP_EOL);
	}

	public function __toString() {
		$x = number_format($this->_x, 2,'.', '');
		$str = "Vertex( x: $x, ";
		$y = number_format($this->_y, 2,'.', '');
		$str = $str."y: $y, ";
		$z = number_format($this->_z, 2,'.', '');
		$str = $str."z:$z, ";
		$w = number_format($this->_w, 2,'.', '');
		$str = $str."w:$w";
		if (self::$verbose)
			$str = $str.", ".$this->_color;
		$str = $str." )";
		return ($str);
	}

	public function doc() {
		$str = file_get_contents("Vertex.doc.txt");
		print($str);
	}

# **************************************************************************** #
#                              GETTERS / SETTERS                               #
# **************************************************************************** #

	public function getX() {
		return ($this->_x);
	}

	public function getY() {
		return ($this->_y);
	}

	public function getZ() {
		return ($this->_z);
	}

	public function getW() {
		return ($this->_w);
	}

	public function getColor() {
		return ($this->_color);
	}

	public function setX($x) {
		$x = floatval($x);
		$this->_x = $x;
	}

	public function setY($y) {
		$y = floatval($y);
		$this->_y = $y;
	}

	public function setZ($z) {
		$z = floatval($z);
		$this->_z = $z;
	}

	public function setW($w) {
		$w = floatval($w);
		$this->_w = $w;
	}

	public function setColor($color) {
		$this->_color->setRed($color->getRed);
		$this->_color->setGreen($color->getGreen);
		$this->_color->setBlue($color->getBlue);

	}
}

?>
