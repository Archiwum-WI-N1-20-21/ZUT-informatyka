package pl.edu.zut.po.wzorce.symulator;

public class DzikaKaczka extends Kaczka {
	public DzikaKaczka() {
		ustawKwaczInt(new Kwacz());
		ustawLecInt(new LatamBoMamSkrzydla());
	}
	
	public void wyswietl(){
		System.out.println("Wygląda jak dzika kaczka");
	}
}