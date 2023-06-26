package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.WiezaStereo;

public class PolecenieWylaczStereo implements Polecenie{
    WiezaStereo stereo;

    public PolecenieWylaczStereo(WiezaStereo stereo)
    {
        super();
        this.stereo = stereo;
    }

    @Override
    public void wykonaj() {
        stereo.wylacz();
    }
    @Override
    public void wycofaj() {
        stereo.wlacz();
    }
}