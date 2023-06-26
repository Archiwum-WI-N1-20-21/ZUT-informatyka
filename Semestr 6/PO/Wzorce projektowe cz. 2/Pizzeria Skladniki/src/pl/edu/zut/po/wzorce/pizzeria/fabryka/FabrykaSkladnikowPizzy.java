package pl.edu.zut.po.wzorce.pizzeria.fabryka;

import pl.edu.zut.po.wzorce.pizzeria.skladniki.Ciasto;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Malze;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Pepperoni;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Ser;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Sos;
import pl.edu.zut.po.wzorce.pizzeria.skladniki.Warzywa;

public interface FabrykaSkladnikowPizzy {
	public Ciasto utworzCiasto();

	public Sos utworzSos();

	public Ser[] utworzSer();

	public Warzywa[] utworzWarzywa(String type);

	public Pepperoni utworzPepperoni();

	public Malze utworzMalze();
}