package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.Jacuzzi;

public class PolecenieJacuzziWylacz implements Polecenie {
	Jacuzzi jacuzzi;

    public PolecenieJacuzziWylacz(Jacuzzi jacuzzi)
    {
        super();
        this.jacuzzi = jacuzzi;
    }

    @Override
    public void wykonaj() {
        jacuzzi.wylacz();
    }

    @Override
    public void wycofaj() {
        jacuzzi.wlacz();
    }
}
