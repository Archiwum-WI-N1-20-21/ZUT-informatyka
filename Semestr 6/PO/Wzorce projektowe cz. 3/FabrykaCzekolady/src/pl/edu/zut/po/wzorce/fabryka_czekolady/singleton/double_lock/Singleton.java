package pl.edu.zut.po.wzorce.fabryka_czekolady.singleton.double_lock;

public class Singleton {
	private volatile static Singleton unikalnaInstancja;

	private Singleton() {
	}

	public static Singleton pobierzInstancje() {
		if (unikalnaInstancja == null) {
			synchronized (Singleton.class) {
				if (unikalnaInstancja == null) {
					unikalnaInstancja = new Singleton();
				}
			}
		}
		return unikalnaInstancja;
	}
}