package pl.edu.zut.po.wzorce.pogodynka.wyswietl;
import pl.edu.zut.po.wzorce.pogodynka.DanePogodowe;
import pl.edu.zut.po.wzorce.pogodynka.Obserwator;
import pl.edu.zut.po.wzorce.pogodynka.WyswietlElement;

public class PrognozaWyswietlanie implements Obserwator, WyswietlElement {

	private float temperatura;
	private float wilgotnosc;
	private float cisnienie;
	private DanePogodowe dane;
	
    public PrognozaWyswietlanie(DanePogodowe i) {
    	this.dane = i;
    	dane.zarejestrujObserwatora(this);
    }

	public void aktualizacja(float temperatura, float wilgotnosc, float cisnienie) {
		this.temperatura = temperatura;
		this.wilgotnosc = wilgotnosc;
		this.cisnienie = cisnienie;
		wyswietl();
	}
	
	public void wyswietl() {
		System.out.println("Prognoza " + temperatura + " stopni C oraz " + wilgotnosc + "% wilgotność");
	}

}