package pl.edu.zut.po.wzorce.symulator;

public class MiniSymulatorKaczki {

	public static void main(String[] args) {
		Kaczka dzika = new DzikaKaczka();
		dzika.wyswietl();
		dzika.wykonajKwacz();
		dzika.wykonajLec();
		System.out.println();
		
		Kaczka gumowa = new GumowaKaczka();
		gumowa.wyswietl();
		gumowa.wykonajKwacz();
		gumowa.wykonajLec();
		System.out.println();
		
		Kaczka wabik = new WabikKaczka();
		wabik.wyswietl();
		wabik.wykonajKwacz();
		wabik.wykonajLec();
		System.out.println();
		
		Kaczka plaskonos = new PlaskonosKaczka();
		plaskonos.wyswietl();
		plaskonos.wykonajKwacz();
		plaskonos.wykonajLec();
		
		System.out.println();
		
		Kaczka model = new ModelKaczki();
		model.wyswietl();
		model.wykonajKwacz();
		model.wykonajLec();
		model.ustawKwaczInt(new NieKwacz());
		model.ustawLecInt(new LatamBoMamSkrzydla());
		model.wykonajKwacz();
		model.wykonajLec();
	}
}
