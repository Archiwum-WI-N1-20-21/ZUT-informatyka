package pl.edu.zut.po.wzorce.pizzeria.pizza;

import pl.edu.zut.po.wzorce.pizzeria.skladniki.Ciasto;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Malze;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Pepperoni;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Ser;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Sos;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Warzywa;

public abstract class Pizza {
	String nazwa;
	Ciasto ciasto;
	Sos sos;
	Warzywa warzywa[];
	Ser sery[];
	Pepperoni pepperoni;
	Malze malze;

	public abstract void przygotowanie();

	public void pieczenie() {
		System.out.println("Pieczenie: 25 minut w temperaturze 180 stopni Celsjusza");
	}

	public void krojenie() {
		System.out.println("Krojenie pizzy na 8 kawałków");
	}

	public void pakowanie() {
		System.out.println("Pakowanie pizzy w oficjalne pudełko naszej sieci Pizzerii.");
	}

	public void ustawNazwa(String nazwa) {
		this.nazwa = nazwa;
	}

	public String pobierzNazwa() {
		return nazwa;
	}

	public String toString() { // NIE WIEM JAK NAPRAWIC PRINTOWANIE SIE NULLA TUTAJ
		String warz = null;
		if (warzywa != null) 
			for (Warzywa w : warzywa) {
				warz += (warz == null ? "" : ",") + w.getClass().getSimpleName();
			}
		String sers = null;
		if (sery != null) 
			for (Ser s : sery) {
				sers += (sers == null ? "" : ",") + s.getClass().getSimpleName();
			}
		String info = String.format("%s\n"
				+ "ciasto: %s\n"
				+ "sos: %s\n"
				+ "warzywa: %s\n"
				+ "sery: %s\n"
				+ "pepperoni: %s\n"
				+ "małże: %s", 
				nazwa, 
				ciasto == null ? "brak" : ciasto.getClass().getSimpleName(),
				sos == null ? "brak" : sos.getClass().getSimpleName(),
				warz == null ? "brak" : warz, 
				sers == null ? "brak" : sers,
				pepperoni == null ? "brak" : pepperoni.getClass().getSimpleName(),
				malze == null ? "brak" : malze.getClass().getSimpleName()); 
		return info;
	}
}