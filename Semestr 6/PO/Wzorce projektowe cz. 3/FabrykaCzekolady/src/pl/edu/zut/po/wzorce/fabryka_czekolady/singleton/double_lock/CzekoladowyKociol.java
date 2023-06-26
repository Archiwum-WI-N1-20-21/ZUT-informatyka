package pl.edu.zut.po.wzorce.fabryka_czekolady.singleton.double_lock;

public class CzekoladowyKociol {
	private boolean pusty;
	private boolean ugotowany;
	private volatile static CzekoladowyKociol unikalnaInstancja;
	
	public static CzekoladowyKociol pobierzInstancje() {
		if (unikalnaInstancja == null) {
			synchronized (CzekoladowyKociol.class) {
				if (unikalnaInstancja == null) {
					unikalnaInstancja = new CzekoladowyKociol();
				}
			}
		}
		return unikalnaInstancja;
	}

	private CzekoladowyKociol() {
		pusty = true;
		ugotowany = false;
		System.out.println("Utworzenie instancji Czekoladowego Kotła: " + this.hashCode());
	}

	public void napelniaj() {
		if (jestPusty()) {
			pusty = false;
			ugotowany = false;
			// napełniaj bojler mieszanką mleka i czekolady
			System.out.println("Napełnianie bojlera mieszanką czekolady i mleka " + this.hashCode());
		}
	}

	public void oprozniaj() {
		if (!jestPusty() && jestUgotowany()) {
			// opróżniaj bojler z ugotowanej mieszanki mleka i czekolady
			System.out.println("Opróżnianie bojlera z ugotowanej mieszanki czekolady i mleka " + this.hashCode());
			pusty = true;
		}
	}

	public void gotuj() {
		if (!jestPusty() && !jestUgotowany()) {
			// gotuj zawartość kotła
			System.out.println("Gotowanie mieszanki czekolady i mleka " + this.hashCode());
			ugotowany = true;
		}
	}

	public boolean jestPusty() {
		return pusty;
	}

	public boolean jestUgotowany() {
		return ugotowany;
	}
}