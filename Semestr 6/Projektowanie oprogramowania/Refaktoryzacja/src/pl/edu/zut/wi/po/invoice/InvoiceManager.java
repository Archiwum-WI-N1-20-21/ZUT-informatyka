package pl.edu.zut.wi.po.invoice;

import java.time.LocalDate;

public class InvoiceManager {

	public static void printOwing(Invoice invoice) {
		double outstanding = 0;
		
		wyswietlNaglowek();
		// Wyliczenie nale�no�ci.
		outstanding = wyliczNaleznosci(invoice, outstanding);
		
		// Zapisanie daty p�atno�ci.
		invoice = zapiszDatePlatnosci(invoice);
		
		// Wy�wietlenie szczeg��w.
		wyswietlSzczegoly(invoice, outstanding);
	}
	
	public static void wyswietlNaglowek() {
		System.out.println("************************");
		System.out.println("* Rachunek dla klienta *");
		System.out.println("************************");
	}
	
	public static double wyliczNaleznosci(Invoice invoice, double outstanding) {
		for (Order o : invoice.getOrders()) {
			outstanding += o.getAmount();
		}
		return outstanding;
	}
	
	public static Invoice zapiszDatePlatnosci(Invoice invoice) {
		LocalDate today = LocalDate.now();  
		invoice.setDueDate(today.plusDays(30));
		
		return invoice;
	}
	
	public static void wyswietlSzczegoly(Invoice invoice, double outstanding) {
		System.out.println(String.format("nazwa: %s", invoice.getCustomer()));
		System.out.println(String.format("kwota: %.2f", outstanding));
		System.out.println(String.format("p�atno�� do: %s", invoice.getDueDate()));	
	}

}