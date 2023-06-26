package pl.edu.zut.po.wzorce.pizzeria;

import pl.edu.zut.po.wzorce.pizzeria.pizza.Pizza;

public class TestPizzerii {

	public static void main(String[] args) {
		Pizzeria pizzeria = new Pizzeria(null); // nie mam pojecia jak to ma zadzialac
		Pizza pizza = pizzeria.zamowPizze("serowa");
		System.out.println(pizzeria.getClass().getSimpleName() + " wyprodukowała " + pizza.getClass().getSimpleName());
	}
}
