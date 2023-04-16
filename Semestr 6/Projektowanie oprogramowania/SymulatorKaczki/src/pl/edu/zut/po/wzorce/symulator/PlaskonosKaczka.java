package pl.edu.zut.po.wzorce.symulator;

public class PlaskonosKaczka extends Kaczka {
	public PlaskonosKaczka() {
		ustawKwaczInt(new Kwacz());
		ustawLecInt(new LatamBoMamSkrzydla());
	}
	
	public void wyswietl(){
		System.out.println("Wygląda jak płaskonos");
	}
}