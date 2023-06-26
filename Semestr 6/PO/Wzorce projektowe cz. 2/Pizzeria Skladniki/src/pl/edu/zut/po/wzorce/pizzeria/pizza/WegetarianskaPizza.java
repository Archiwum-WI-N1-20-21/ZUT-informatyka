package pl.edu.zut.po.wzorce.pizzeria.pizza;

import pl.edu.zut.po.wzorce.pizzeria.fabryka.FabrykaSkladnikowPizzy;

public class WegetarianskaPizza extends Pizza {
	FabrykaSkladnikowPizzy fabrykaSkladnikow;

	public WegetarianskaPizza(FabrykaSkladnikowPizzy fabrykaSkladnikow) {
		this.fabrykaSkladnikow = fabrykaSkladnikow;
	}

	@Override
	public void przygotowanie() {
		System.out.println("Przygotowywanie: " + nazwa);
		ciasto = fabrykaSkladnikow.utworzCiasto();
		sos = fabrykaSkladnikow.utworzSos();
		sery = fabrykaSkladnikow.utworzSer();
		warzywa = fabrykaSkladnikow.utworzWarzywa(this.getClass().getSimpleName());
	}

}
