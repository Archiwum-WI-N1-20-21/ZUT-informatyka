package pl.edu.zut.po.wzorce.pogodynka;

public interface Obserwator {
	void aktualizacja(float temperatura, float wilgotnosc, float cisnienie);
}
