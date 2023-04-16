package pl.edu.zut.po.wzorce.symulator;

public class ModelKaczki extends Kaczka {
	public ModelKaczki() {
		ustawKwaczInt(new Kwacz());
		ustawLecInt(new LotZNapedemRakietowym());
	}
	
	public void ustawKwacz(kwakanieInterfejs i) {
		this.kwakanieInt = i;
	}
	
	public void ustawLec(latanieInterfejs i) {
		this.latanieInt = i;
	}
	
	public void wyswietl(){
		System.out.println("Wygląda jak model kaczki");
	}
}
