package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.Swiatlo;

public class PolecenieSwiatloSciemnij implements Polecenie {
	Swiatlo swiatlo;

	public PolecenieSwiatloSciemnij(Swiatlo swiatlo) {
		super();
		this.swiatlo = swiatlo;
	}

	public void wykonaj() {
		swiatlo.wlacz();
		swiatlo.sciemnij(50);
	}

	@Override
	public void wycofaj() {
		swiatlo.wlacz();
	}
}
