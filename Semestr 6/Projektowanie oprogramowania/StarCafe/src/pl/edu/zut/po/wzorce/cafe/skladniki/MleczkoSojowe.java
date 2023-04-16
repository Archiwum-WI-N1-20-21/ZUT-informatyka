package pl.edu.zut.po.wzorce.cafe.skladniki;
import pl.edu.zut.po.wzorce.cafe.napoje.Napoj;

public class MleczkoSojowe extends SkladnikiDekorator {
	public MleczkoSojowe(Napoj napoj) {
		this.napoj = napoj;
	}
	
	public String pobierzOpis() {
		return napoj.pobierzOpis() + ", Mleczko sojowe";
	}
	
	public double koszt() {
		return napoj.koszt() + 0.15;
	}
}
