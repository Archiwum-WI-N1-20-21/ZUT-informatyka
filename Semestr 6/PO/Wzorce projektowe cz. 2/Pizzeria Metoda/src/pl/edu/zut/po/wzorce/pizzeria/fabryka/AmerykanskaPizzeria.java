package pl.edu.zut.po.wzorce.pizzeria.fabryka;

import pl.edu.zut.po.wzorce.pizzeria.pizza.*;

public class AmerykanskaPizzeria extends Pizzeria {
	public Pizza utworzPizza(String type) {
		Pizza pizza = null;
		
		if (type.equals("serowa")) {
			pizza = new AmerykanskaSerowaPizza();
		} else if (type.equals("wegetarianska")) {
			pizza = new AmerykanskaWegetarianskaPizza();
		} else if (type.equals("owoce morza")) {
			pizza = new AmerykanskaOwoceMorzaPizza();
		} else if (type.equals("pepperoni")) {
			pizza = new AmerykanskaPepperoniPizza();
		}
		
		return pizza;
	}
}