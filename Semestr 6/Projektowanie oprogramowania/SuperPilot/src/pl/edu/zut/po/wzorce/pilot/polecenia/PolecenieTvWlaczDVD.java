package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.TV;

public class PolecenieTvWlaczDVD implements Polecenie {
    TV tv;

    public PolecenieTvWlaczDVD(TV tv)
    {
        super();
        this.tv = tv;
    }

    @Override
    public void wykonaj() {
        tv.ustawDVD();
    }

    @Override
    public void wycofaj() {
        tv.wylacz();
    }
}
