package pl.edu.zut.po.wzorce.pizzeria.fabryka;

import pl.edu.zut.po.wzorce.pizzeria.skladniki.*;

public class WloskaFabrykaSkladnikowPizzy implements FabrykaSkladnikowPizzy {
	public Ciasto utworzCiasto() {
		return new CienkieChrupkieCiasto();
	}

	public Sos utworzSos() {
		return new SosMarinara();
	}

	public Ser[] utworzSer() {
		Ser sery[] = { new SerReggiano() };
		return sery;
	}

	public Warzywa[] utworzWarzywa(String type) {
		Warzywa warzywa[] = { new Czosnek(), new Cebula(), new Pieczarki(), new CzerwonaPapryka() };
		return warzywa;
	}

	public Pepperoni utworzPepperoni() {
		return new PlastryPepperoni();
	}

	public Malze utworzMalze() {
		return new SwiezeMalze();
	}
}