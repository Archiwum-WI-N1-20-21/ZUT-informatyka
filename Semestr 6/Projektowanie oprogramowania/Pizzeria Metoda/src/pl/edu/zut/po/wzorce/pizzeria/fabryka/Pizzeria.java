package pl.edu.zut.po.wzorce.pizzeria.fabryka;

import pl.edu.zut.po.wzorce.pizzeria.pizza.Pizza;

public abstract class Pizzeria {
	public Pizza zamowPizze(String type) {
		Pizza pizza = null;
		
		pizza = utworzPizza(type);
		
		pizza.przygotowanie();
		pizza.pieczenie();
		pizza.krojenie();
		pizza.pakowanie();
		return pizza;
	}

	abstract Pizza utworzPizza(String type);
}
