package pl.edu.zut.po.wzorce.pizzeria;

import pl.edu.zut.po.wzorce.pizzeria.pizza.Pizza;

public abstract class Pizzeria {
	public Pizza zamowPizze(String type) {
		Pizza pizza = null;
		
		pizza = utworzPizze(type);
		
		pizza.przygotowanie();
		pizza.pieczenie();
		pizza.krojenie();
		pizza.pakowanie();
		
		return pizza;
	}

	abstract Pizza utworzPizze(String type);
}