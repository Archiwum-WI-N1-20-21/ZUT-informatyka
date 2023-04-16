package pl.edu.zut.po.wzorce.symulator;

public class RakietowaKaczka extends Kaczka {
	public RakietowaKaczka() {
		ustawKwaczInt(new Kwacz());
		ustawLecInt(new LotZNapedemRakietowym());
	}
	
	public void wyswietl(){
		System.out.println("Wygląda jak rakieta");
	}
}
