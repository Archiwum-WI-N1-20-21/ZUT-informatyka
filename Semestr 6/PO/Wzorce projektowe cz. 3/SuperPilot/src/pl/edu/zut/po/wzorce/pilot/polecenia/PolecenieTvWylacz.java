package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.TV;

public class PolecenieTvWylacz implements Polecenie {
    TV tv;

    public PolecenieTvWylacz(TV tv)
    {
        super();
        this.tv = tv;
    }

    @Override
    public void wykonaj() {
        tv.wylacz();
    }

    @Override
    public void wycofaj() {
        tv.wlacz();
    }
}
