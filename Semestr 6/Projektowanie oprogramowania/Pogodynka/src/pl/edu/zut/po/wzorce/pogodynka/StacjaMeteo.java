package pl.edu.zut.po.wzorce.pogodynka;

import pl.edu.zut.po.wzorce.pogodynka.wyswietl.Indeks;
import pl.edu.zut.po.wzorce.pogodynka.wyswietl.PrognozaWyswietlanie;
import pl.edu.zut.po.wzorce.pogodynka.wyswietl.StatystykaWyswietlanie;
import pl.edu.zut.po.wzorce.pogodynka.wyswietl.WarunkiBiezaceWyswietlanie;

public class StacjaMeteo {

	public static void main(String[] args) {
		DanePogodowe danePogodowe = new DanePogodowe();
		
		PrognozaWyswietlanie prognoza = new PrognozaWyswietlanie(danePogodowe);
        StatystykaWyswietlanie statystyka = new StatystykaWyswietlanie(danePogodowe);
        WarunkiBiezaceWyswietlanie warunki = new WarunkiBiezaceWyswietlanie(danePogodowe);
        Indeks indeks = new Indeks(danePogodowe);
		
		danePogodowe.ustawOdczyty(26.6f, 65, 1013.1f);
		System.out.println();
		danePogodowe.ustawOdczyty(27.7f, 70, 997.0f);
		System.out.println();
		danePogodowe.ustawOdczyty(25.5f, 90, 997.0f);
		System.out.println();
		
		danePogodowe.usunObserwatora(prognoza);
		danePogodowe.ustawOdczyty(20.0f, 75, 1001.0f);
		System.out.println();
		
		danePogodowe.zarejestrujObserwatora(prognoza);
		danePogodowe.ustawOdczyty(25.5f, 90, 997.0f);
	}
	
}