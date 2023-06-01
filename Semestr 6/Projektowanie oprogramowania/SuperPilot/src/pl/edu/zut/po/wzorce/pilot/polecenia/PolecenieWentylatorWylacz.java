package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.WentylatorSufitowy;

public class PolecenieWentylatorWylacz implements Polecenie {
    private WentylatorSufitowy wentylator;

    public PolecenieWentylatorWylacz(WentylatorSufitowy wentylator)
    {
        super();
        this.wentylator = wentylator;
    }

    @Override
    public void wykonaj() {
        wentylator.off();
    }

    @Override
    public void wycofaj() {
        
    }
}