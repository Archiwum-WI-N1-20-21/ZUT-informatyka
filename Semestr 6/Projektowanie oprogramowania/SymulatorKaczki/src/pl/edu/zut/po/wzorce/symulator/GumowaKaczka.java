package pl.edu.zut.po.wzorce.symulator;


public class GumowaKaczka extends Kaczka {
	public GumowaKaczka() {
		ustawKwaczInt(new Piszcz());
		ustawLecInt(new LatamBoMamSkrzydla());
	}

	public void wyswietl(){
		System.out.println("Wygląda jak gumowa kaczka");
	}
}