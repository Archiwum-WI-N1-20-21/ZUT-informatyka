package pl.edu.zut.po.wzorce.pizzeria;

import pl.edu.zut.po.wzorce.pizzeria.fabryka.FabrykaSkladnikowPizzy;
import pl.edu.zut.po.wzorce.pizzeria.fabryka.AmerykanskaFabrykaSkladnikowPizzy;
import pl.edu.zut.po.wzorce.pizzeria.pizza.OwoceMorzaPizza;
import pl.edu.zut.po.wzorce.pizzeria.pizza.PepperoniPizza;
import pl.edu.zut.po.wzorce.pizzeria.pizza.Pizza;
import pl.edu.zut.po.wzorce.pizzeria.pizza.SerowaPizza;
import pl.edu.zut.po.wzorce.pizzeria.pizza.WegetarianskaPizza;

public class AmerykanskaPizzeria extends Pizzeria {
	protected Pizza utworzPizze(String item) {
		Pizza pizza = null;
		FabrykaSkladnikowPizzy fabrykaSkladnikow = new AmerykanskaFabrykaSkladnikowPizzy();
		if (item.equals("serowa")) {
			pizza = new SerowaPizza(fabrykaSkladnikow);
			pizza.ustawNazwa("Amerykanska Pizza Serowa");
		} else if (item.equals("wegetariańska")) {
			pizza = new WegetarianskaPizza(fabrykaSkladnikow);
			pizza.ustawNazwa("Amerykanska Pizza Wegetariańska");
		} else if (item.equals("owoce morza")) {
			pizza = new OwoceMorzaPizza(fabrykaSkladnikow);
			pizza.ustawNazwa("Amerykanska Pizza Owoce Morza");
		} else if (item.equals("pepperoni")) {
			pizza = new PepperoniPizza(fabrykaSkladnikow);
			pizza.ustawNazwa("Amerykanska Pizza Pepperoni");
		}
		return pizza;
	}
}