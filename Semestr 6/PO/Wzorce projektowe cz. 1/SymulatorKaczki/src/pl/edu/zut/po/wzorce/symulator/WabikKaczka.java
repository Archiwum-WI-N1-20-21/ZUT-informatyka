package pl.edu.zut.po.wzorce.symulator;

public class WabikKaczka extends Kaczka {
	public WabikKaczka() {
		ustawKwaczInt(new Kwacz());
		ustawLecInt(new NieLatam());
	}
	
	public void wyswietl(){
		System.out.println("Wygląda jak wabik");
	}
}
