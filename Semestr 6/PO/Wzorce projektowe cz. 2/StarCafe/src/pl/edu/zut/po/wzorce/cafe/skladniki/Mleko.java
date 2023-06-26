package pl.edu.zut.po.wzorce.cafe.skladniki;
import pl.edu.zut.po.wzorce.cafe.napoje.Napoj;

public class Mleko extends SkladnikiDekorator {
	public Mleko(Napoj napoj) {
		this.napoj = napoj;
	}
	
	public String pobierzOpis() {
		return napoj.pobierzOpis() + ", Mleko";
	}
	
	public double koszt() {
		return napoj.koszt() + 0.10;
	}
}
