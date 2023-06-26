package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.WiezaStereo;

public class PolecenieWiezaWlaczCD implements Polecenie {
    WiezaStereo stereo;

    public PolecenieWiezaWlaczCD(WiezaStereo stereo)
	{
	    super();
	    this.stereo = stereo;
	}

	@Override
	public void wykonaj() {
	    stereo.ustawCD();
	}
	@Override
	public void wycofaj() {
	    stereo.wlacz();
	}
}
