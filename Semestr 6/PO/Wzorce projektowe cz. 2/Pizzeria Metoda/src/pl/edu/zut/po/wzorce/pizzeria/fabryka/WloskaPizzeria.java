package pl.edu.zut.po.wzorce.pizzeria.fabryka;

import pl.edu.zut.po.wzorce.pizzeria.pizza.*;

public class WloskaPizzeria extends Pizzeria {
	public Pizza utworzPizza(String type) {
		Pizza pizza = null;
		
		if (type.equals("serowa")) {
			pizza = new WloskaSerowaPizza();
		} else if (type.equals("wegetarianska")) {
			pizza = new WloskaWegetarianskaPizza();
		} else if (type.equals("owoce morza")) {
			pizza = new WloskaOwoceMorzaPizza();
		} else if (type.equals("pepperoni")) {
			pizza = new WloskaPepperoniPizza();
		}
		
		return pizza;
	}
}
