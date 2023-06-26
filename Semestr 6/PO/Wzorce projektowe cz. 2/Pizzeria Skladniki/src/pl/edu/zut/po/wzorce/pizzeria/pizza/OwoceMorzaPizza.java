package pl.edu.zut.po.wzorce.pizzeria.pizza;

import pl.edu.zut.po.wzorce.pizzeria.fabryka.FabrykaSkladnikowPizzy;

public class OwoceMorzaPizza extends Pizza {
	FabrykaSkladnikowPizzy fabrykaSkladnikow;

	public OwoceMorzaPizza(FabrykaSkladnikowPizzy fabrykaSkladnikow) {
		this.fabrykaSkladnikow = fabrykaSkladnikow;
	}

	@Override
	public void przygotowanie() {
		System.out.println("Przygotowywanie: " + nazwa);
		ciasto = fabrykaSkladnikow.utworzCiasto();
		sos = fabrykaSkladnikow.utworzSos();
		sery = fabrykaSkladnikow.utworzSer();
		malze = fabrykaSkladnikow.utworzMalze();
	}
}