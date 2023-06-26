package pl.edu.zut.po.wzorce.cafe.skladniki;
import pl.edu.zut.po.wzorce.cafe.napoje.Napoj;

public class Czekolada extends SkladnikiDekorator {
	public Czekolada(Napoj napoj) {
		this.napoj = napoj;
	}
	
	public String pobierzOpis() {
		return napoj.pobierzOpis() + ", Czekolada";
	}
	
	public double koszt() {
		return napoj.koszt() + 0.2;
	}
}
