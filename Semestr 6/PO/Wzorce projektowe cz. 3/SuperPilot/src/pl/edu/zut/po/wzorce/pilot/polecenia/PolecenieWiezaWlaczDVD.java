package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.WiezaStereo;

public class PolecenieWiezaWlaczDVD implements Polecenie {
    WiezaStereo stereo;

    public PolecenieWiezaWlaczDVD(WiezaStereo stereo)
	{
	    super();
	    this.stereo = stereo;
	}

	@Override
	public void wykonaj() {
	    stereo.ustawDVD();
	}
	@Override
	public void wycofaj() {
	    stereo.wlacz();
	}
}
