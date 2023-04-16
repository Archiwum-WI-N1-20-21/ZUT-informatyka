package pl.edu.zut.po.wzorce.pizzeria.fabryka;

import pl.edu.zut.po.wzorce.pizzeria.skladniki.*;

public class AmerykanskaFabrykaSkladnikowPizzy implements FabrykaSkladnikowPizzy {
	public Ciasto utworzCiasto() {
		return new Ciasto();
	}

	public Sos utworzSos() {
		return new SosZPomidorowSliwkowych();
	}

	public Ser[] utworzSer() {
		Ser sery[] = { new SerMozzarella(), new SerParmezan() };
		return sery;
	}

	public Warzywa[] utworzWarzywa(String type) {
		if (type.equals("WegetarianskaPizza")) {
			Warzywa warzywa[] = { new Baklazany(), new Szpinak(), new CzarneOliwki()};
			return warzywa;
		} else if (type.equals("SerowaPizza")) {
			Warzywa warzywa[] = { new Oregano()};
			return warzywa;
		} else if (type.equals("PepperoniPizza")) {
			Warzywa warzywa[] = { new Baklazany(), new Szpinak(), new CzarneOliwki()};
			return warzywa;
		} else {
			Warzywa warzywa[] = { new Cebula(), new Pieczarki(), new Oregano(), new Baklazany(), new Szpinak(), new CzarneOliwki() };
			return warzywa;
		}
	}

	public Pepperoni utworzPepperoni() {
		return new Pepperoni();
	}

	public Malze utworzMalze() {
		return new Malze();
	}
}