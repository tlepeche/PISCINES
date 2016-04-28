<?php
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Color.class.php                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sduprey <sduprey@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/14 12:05:52 by sduprey           #+#    #+#              #
#    Updated: 2015/04/14 12:05:52 by sduprey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                                                                              #
# **************************************************************************** #

Class Color {

	public 			$red = 0;
	public 			$green = 0;
	public			$blue = 0;
	public static 	$verbose = FALSE;

	public function __construct($kwargs) {
		if (array_key_exists('rgb', $kwargs)) {
			$rgb = intval($kwargs['rgb']);
			$this->setRed(($rgb >> 16) & 0xFF);
			$this->setGreen(($rgb >> 8) & 0xFF);
			$this->setBlue(($rgb >> 0) & 0xFF);
		} else {
			if (array_key_exists('red', $kwargs))
				$this->setRed(intval($kwargs['red']));
			if (array_key_exists('green', $kwargs))
				$this->setGreen(intval($kwargs['green']));
			if (array_key_exists('blue', $kwargs))
				$this->setBlue(intval($kwargs['blue']));
		}
		if (self::$verbose)
			print($this." constructed.".PHP_EOL);
	}

	public function __destruct() {
		if (self::$verbose)
			print($this." destructed.".PHP_EOL);
	}

	public function __toString() {
		$str = "Color( red: ".$this->color_to_str($this->red);
		$str = $str.", green: ".$this->color_to_str($this->green);
		$str = $str.", blue: ".$this->color_to_str($this->blue)." )";
		return ($str);
	}

	public static function doc() {
		$str = file_get_contents("Color.doc.txt");
		print($str);
	}

	public function add($val) {
		$r = $this->getRed() + $val->getRed();
		$g = $this->getGreen() + $val->getGreen();
		$b = $this->getBlue() + $val->getBlue();
		$new = new Color(array('red' => $r, 'green' => $g, 'blue' => $b));
		return ($new);
	}

	public function sub($val) {
		$r = $this->getRed() - $val->getRed();
		$g = $this->getGreen() - $val->getGreen();
		$b = $this->getBlue() - $val->getBlue();
		$new = new Color(array('red' => $r, 'green' => $g, 'blue' => $b));
		return ($new);
	}

	public function mult ($val) {
		$r = $this->getRed() * $val;
		$g = $this->getGreen() * $val;
		$b = $this->getBlue() * $val;
		$new = new Color(array('red' => $r, 'green' => $g, 'blue' => $b));
		return ($new);
	}

	private function color_to_str($color) {
		$str = $color;
		if ($color < 10)
			$str = "  ".$str;
		else if ($color < 100)
			$str = " ".$str;
		return ($str);
	}

# **************************************************************************** #
#                              GETTERS / SETTERS                               #
# **************************************************************************** #

	public function getRed() {
		return ($this->red);
	}

	public function getGreen() {
		return ($this->green);
	}

	public function getBlue() {
		return ($this->blue);
	}

	public function setRed($red) {
		$red = intval($red);
		if ($red > 255)
			$this->red = 255;
		else if ($red < 0)
			$this->red = 0;
		else
			$this->red = $red;
	}

	public function setGreen($green) {
		$green = intval($green);
		if ($green > 255)
			$this->green = 255;
		else if ($green < 0)
			$this->green = 0;
		else
			$this->green = $green;
	}

	public function setBlue($blue) {
		$blue = intval($blue);
		if ($blue > 255)
			$this->blue = 255;
		else if ($blue < 0)
			$this->blue = 0;
		else
			$this->blue = $blue;
	}
}
?>
