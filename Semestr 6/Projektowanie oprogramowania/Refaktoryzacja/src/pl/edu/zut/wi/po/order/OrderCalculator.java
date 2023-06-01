package pl.edu.zut.wi.po.order;

public class OrderCalculator {

	public static double price(Order order) {
		// Cena ko�cowa = cena bazowa � upust + koszt wysy�ki.
		double quantity = order.getQuantity();
		double itemPrice = order.getItemPrice();
		final double result = quantity * itemPrice
				- Math.max(0, quantity - 500) * itemPrice * 0.05
				+ Math.min(quantity * itemPrice * 0.1, 100);
		return result;
	}
}
