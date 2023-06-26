package pl.edu.zut.po.wzorce.pizzeria;

import pl.edu.zut.po.wzorce.pizzeria.pizza.Pizza;

public class TestPizzerii {

	public static void main(String[] args) {
		WloskaPizzeria pizzeriaW = new WloskaPizzeria();
		AmerykanskaPizzeria pizzeriaA = new AmerykanskaPizzeria();
		
		Pizza pizza1 = pizzeriaW.zamowPizze("wegetariańska");
		System.out.println(pizza1);
		
		System.out.println();
		
		Pizza pizza2 = pizzeriaA.zamowPizze("pepperoni");
		System.out.println(pizza2);
	}
}
