package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.WiezaStereo;

public class PolecenieWiezaWlacz implements Polecenie {
	WiezaStereo stereo;

    public PolecenieWiezaWlacz(WiezaStereo stereo)
    {
        super();
        this.stereo = stereo;
    }

    @Override
    public void wykonaj() {
        stereo.wlacz();
    }
    @Override
    public void wycofaj() {
        stereo.wylacz();
    }
}