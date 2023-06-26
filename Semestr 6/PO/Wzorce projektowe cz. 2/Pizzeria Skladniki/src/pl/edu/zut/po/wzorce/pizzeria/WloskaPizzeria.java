package pl.edu.zut.po.wzorce.pizzeria;

import pl.edu.zut.po.wzorce.pizzeria.fabryka.FabrykaSkladnikowPizzy;
import pl.edu.zut.po.wzorce.pizzeria.fabryka.WloskaFabrykaSkladnikowPizzy;
import pl.edu.zut.po.wzorce.pizzeria.pizza.OwoceMorzaPizza;
import pl.edu.zut.po.wzorce.pizzeria.pizza.PepperoniPizza;
import pl.edu.zut.po.wzorce.pizzeria.pizza.Pizza;
import pl.edu.zut.po.wzorce.pizzeria.pizza.SerowaPizza;
import pl.edu.zut.po.wzorce.pizzeria.pizza.WegetarianskaPizza;

public class WloskaPizzeria extends Pizzeria {
	protected Pizza utworzPizze(String item) {
		Pizza pizza = null;
		FabrykaSkladnikowPizzy fabrykaSkladnikow = new WloskaFabrykaSkladnikowPizzy();
		if (item.equals("serowa")) {
			pizza = new SerowaPizza(fabrykaSkladnikow);
			pizza.ustawNazwa("Włoska Pizza Serowa");
		} else if (item.equals("wegetariańska")) {
			pizza = new WegetarianskaPizza(fabrykaSkladnikow);
			pizza.ustawNazwa("Włoska Pizza Wegetariańska");
		} else if (item.equals("owoce morza")) {
			pizza = new OwoceMorzaPizza(fabrykaSkladnikow);
			pizza.ustawNazwa("Włoska Pizza Owoce Morza");
		} else if (item.equals("pepperoni")) {
			pizza = new PepperoniPizza(fabrykaSkladnikow);
			pizza.ustawNazwa("Włoska Pizza Pepperoni");
		}
		return pizza;
	}
}