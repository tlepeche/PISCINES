<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Vector.class.php                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/14 16:30:41 by sduprey           #+#    #+#              #
#    Updated: 2015/04/14 16:30:41 by sduprey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


Class Vector {

	private			$_x = 0.0;
	private			$_y = 0.0;
	private			$_z = 0.0;
	private			$_w = 0.0;
	public static	$verbose = FALSE;

	public function __construct($kwargs) {
		if (array_key_exists('dest', $kwargs)) {
			$dest = $kwargs['dest'];
			$this->_x = $dest->getX();
			$this->_y = $dest->getY();
			$this->_z = $dest->getZ();
		} else {

		}
		if (array_key_exists('orig', $kwargs)) {
			$orig = $kwargs['orig'];
		} else {
			$orig = new Vertex(array('x' => 0.0, 'y' => 0.0, 'z' => 0.0));
		}
		$this->_x -= $orig->getX();
		$this->_y -= $orig->getY();
		$this->_z -= $orig->getZ();
		if (self::$verbose)
			print($this." constructed".PHP_EOL);
	}

	public function __destruct() {
		if (self::$verbose)
			print($this." destructed".PHP_EOL);
	}

	public function __toString() {
		$str = "Vector( ";
		$x = number_format($this->_x, 2, '.', '');
		$str = $str."x:$x, ";
		$y = number_format($this->_y, 2, '.', '');
		$str = $str."y:$y ";
		$z = number_format($this->_z, 2, '.', '');
		$str = $str."z:$z, ";
		$w = number_format($this->_w, 2, '.', '');
		$str = $str."w:$w )";
		return ($str);
	}

	public static function doc() {
	}

	public function magnitude() {
		$m = pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2);
		$m = sqrt($m);
		return ($m);
	}

	public function normalize() {
		$x = $this->_x / $this->magnitude();
		$y = $this->_y / $this->magnitude();
		$z = $this->_z / $this->magnitude();
		$v = new Vertex(array('x' => $x, 'y' => $y, 'z' => $z));
		$norm = new Vector(array ( 'dest' => $v));
		return ($norm);
	}

	public function add($rhs) {
		$x = $this->_x + $rhs->getX();
		$y = $this->_y + $rhs->getY();
		$z = $this->_z + $rhs->getZ();
		$nv = new Vertex(array('x' => $x, 'y' => $y, 'z' => $z));
		$new = new Vector(array('dest' => $nv));
		return ($new);
	}

	public function sub($rhs) {
		$x = $this->_x - $rhs->getX();
		$y = $this->_y - $rhs->getY();
		$z = $this->_z - $rhs->getZ();
		$nv = new Vertex(array('x' => $x, 'y' => $y, 'z' => $z));
		$new = new Vector(array('dest' => $nv));
		return ($new);
	}

	public function opposite() {
		$x = $this->_x * -1;
		$y = $this->_y * -1;
		$z = $this->_z * -1;
		$nv = new Vertex(array('x' => $x, 'y' => $y, 'z' => $z));
		$new = new Vector(array('dest' => $nv));
		return ($new);

	}

	public function scalarProduct($k) {
		$x = $this->_x * $k;
		$y = $this->_y * $k;
		$z = $this->_z * $k;
		$nv = new Vertex(array('x' => $x, 'y' => $y, 'z' => $z));
		$new = new Vector(array('dest' => $nv));
		return ($new);
	}

	public function dotProduct($rhs) {
		$x = $this->_x * $rhs->getX();
		$y = $this->_y * $rhs->getY();
		$z = $this->_z * $rhs->getZ();
		$ret = $x + $y + $z;
		return ($ret);
	}

	public function cos($rhs) {
		$v1 = $this->dotProduct($rhs);
		$v2 = $this->magnitude() * $rhs->magnitude();
		return ($v1 / $v2);
	}

	public function crossProduct($rhs) {
		$nx = ($this->getY() * $rhs->getZ()) - ($this->getZ() * $rhs->getY());
		$ny = ($this->getZ() * $rhs->getX()) - ($this->getX() * $rhs->getZ());
		$nz = ($this->getX() * $rhs->getY()) - ($this->getY() * $rhs->getX());
		$nv = new Vertex(array('x' => $nx, 'y' => $ny, 'z' => $nz));
		$new = new Vector(array('dest' => $nv));
		return ($new);
	}

# **************************************************************************** #
#                                 GETTERS / SETTERS                            #
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

}
?>
