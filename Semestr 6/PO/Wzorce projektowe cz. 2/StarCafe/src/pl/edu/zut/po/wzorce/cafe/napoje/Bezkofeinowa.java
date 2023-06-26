package pl.edu.zut.po.wzorce.cafe.napoje;

public class Bezkofeinowa extends Napoj {
	public Bezkofeinowa() {
		opis = "Bezkofeinowa";
	}

	public double koszt() {
		return 1.05;
	}
}