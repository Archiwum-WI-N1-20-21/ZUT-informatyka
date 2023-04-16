package pl.edu.zut.po.wzorce.pogodynka;

public interface Podmiot {
	void zarejestrujObserwatora(Obserwator o);
	void usunObserwatora(Obserwator o);
	void powiadomObserwatorow();
}
