package pl.edu.zut.po.wzorce.pizzeria;

import pl.edu.zut.po.wzorce.pizzeria.fabryka.*;
import pl.edu.zut.po.wzorce.pizzeria.pizza.Pizza;

public class TestPizzerii {

	public static void main(String[] args) {
		WloskaPizzeria pizzeria_w = new WloskaPizzeria();
		Pizza pizza_wp = pizzeria_w.zamowPizze("pepperoni");
		System.out.println(pizzeria_w.getClass().getSimpleName() + " wyprodukowała " + pizza_wp.getClass().getSimpleName());
		
		System.out.println();
		
		Pizza pizza_ws = pizzeria_w.zamowPizze("serowa");
		System.out.println(pizzeria_w.getClass().getSimpleName() + " wyprodukowała " + pizza_ws.getClass().getSimpleName());
		
		System.out.println();
		
		AmerykanskaPizzeria pizzeria_a = new AmerykanskaPizzeria();
		Pizza pizza_ap = pizzeria_a.zamowPizze("pepperoni");
		System.out.println(pizzeria_a.getClass().getSimpleName() + " wyprodukowała " + pizza_ap.getClass().getSimpleName());
		
		System.out.println();
		
		Pizza pizza_as = pizzeria_a.zamowPizze("serowa");
		System.out.println(pizzeria_a.getClass().getSimpleName() + " wyprodukowała " + pizza_as.getClass().getSimpleName());
	}
}
