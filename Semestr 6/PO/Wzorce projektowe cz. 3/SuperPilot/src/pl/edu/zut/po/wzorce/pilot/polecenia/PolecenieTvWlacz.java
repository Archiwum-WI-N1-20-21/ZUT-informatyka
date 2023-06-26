package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.TV;

public class PolecenieTvWlacz implements Polecenie {
    TV tv;

    public PolecenieTvWlacz(TV tv)
    {
        super();
        this.tv = tv;
    }

    @Override
    public void wykonaj() {
        tv.wlacz();
    }

    @Override
    public void wycofaj() {
        tv.wylacz();
    }
}
