package pl.edu.zut.po.wzorce.cafe.skladniki;
import pl.edu.zut.po.wzorce.cafe.napoje.*;

public abstract class SkladnikiDekorator extends Napoj {
	protected Napoj napoj;
	public abstract String pobierzOpis();
}
