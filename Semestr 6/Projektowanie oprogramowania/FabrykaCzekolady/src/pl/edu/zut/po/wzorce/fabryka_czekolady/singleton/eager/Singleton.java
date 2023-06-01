package pl.edu.zut.po.wzorce.fabryka_czekolady.singleton.eager;


public class Singleton {
	private static Singleton unikalnaInstancja = new Singleton();

	// tutaj umieść inne użyteczne zmienne obiektowe
	private Singleton() {
	}

	public static synchronized Singleton pobierzInstancje() {
		return unikalnaInstancja;
	}
	// tutaj umieść inne użyteczne metody
}