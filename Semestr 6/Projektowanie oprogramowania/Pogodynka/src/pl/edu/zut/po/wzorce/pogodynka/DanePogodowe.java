package pl.edu.zut.po.wzorce.pogodynka;
import java.util.ArrayList;

import pl.edu.zut.po.wzorce.pogodynka.wyswietl.PrognozaWyswietlanie;
import pl.edu.zut.po.wzorce.pogodynka.wyswietl.StatystykaWyswietlanie;
import pl.edu.zut.po.wzorce.pogodynka.wyswietl.WarunkiBiezaceWyswietlanie;


public class DanePogodowe implements Podmiot {
	private float temperatura;
	private float wilgotnosc;
	private float cisnienie;
	
	private ArrayList<Obserwator> obserwatorzy = new ArrayList<>();

	public void odczytyZmiana(){
		powiadomObserwatorow();
	}

	private float pobierzTemperature(){
		return temperatura;
	}

	private float pobierzWilgotnosc(){
		return wilgotnosc;
	}

	private float pobierzCisnienie(){
		return cisnienie;
	}
	
	public void ustawOdczyty(float temperatura, float wilgotnosc, float cisnienie) {
		this.temperatura = temperatura;
		this.wilgotnosc = wilgotnosc;
		this.cisnienie = cisnienie;
		odczytyZmiana();
	}
	
	public void zarejestrujObserwatora(Obserwator o) {
		obserwatorzy.add(o);
	}
	
	public void usunObserwatora(Obserwator o) {
		obserwatorzy.remove(o);
	}
	
	public void powiadomObserwatorow() {
		for (Obserwator obs : obserwatorzy) {
			obs.aktualizacja(temperatura, wilgotnosc, cisnienie);
		}
	}
}
