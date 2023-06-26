package pl.edu.zut.po.wzorce.cafe;

import pl.edu.zut.po.wzorce.cafe.napoje.*;
import pl.edu.zut.po.wzorce.cafe.skladniki.*;

public class StarCafe {
	public static void main(String... params) {
		Napoj napoj1 = new MocnoPalona();
		System.out.println(napoj1.pobierzOpis() + " " + napoj1.koszt() + "zł");
		
		System.out.println();
		
		Napoj napoj2 = new BitaSmietana(new Czekolada(new MocnoPalona()));
		System.out.println(napoj2.pobierzOpis() + " " + napoj2.koszt() + "zł");
		
		System.out.println();
		
		Napoj napoj3 = new Mleko(new Mleko(new Bezkofeinowa()));
		System.out.println(napoj3.pobierzOpis() + " " + napoj3.koszt() + "zł");
	}
}
