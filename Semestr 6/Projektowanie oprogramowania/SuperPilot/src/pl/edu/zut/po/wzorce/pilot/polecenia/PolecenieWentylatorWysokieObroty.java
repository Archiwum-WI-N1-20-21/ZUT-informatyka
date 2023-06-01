package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.WentylatorSufitowy;

public class PolecenieWentylatorWysokieObroty implements Polecenie{
    private WentylatorSufitowy wentylator;

    public PolecenieWentylatorWysokieObroty(WentylatorSufitowy wentylator)
    {
        super();
        this.wentylator = wentylator;
    }

    @Override
    public void wykonaj() {
        wentylator.szybko();
    }

    @Override
    public void wycofaj() {
        wentylator.off();
    }
}