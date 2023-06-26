package pl.edu.zut.po.wzorce.cafe.skladniki;

import pl.edu.zut.po.wzorce.cafe.napoje.Napoj;

public class BitaSmietana extends SkladnikiDekorator {
	public BitaSmietana(Napoj napoj) {
		this.napoj = napoj;
	}
	
	public String pobierzOpis() {
		return napoj.pobierzOpis() + ", Bita smietana";
	}
	
	public double koszt() {
		return napoj.koszt() + 0.1;
	}
}
