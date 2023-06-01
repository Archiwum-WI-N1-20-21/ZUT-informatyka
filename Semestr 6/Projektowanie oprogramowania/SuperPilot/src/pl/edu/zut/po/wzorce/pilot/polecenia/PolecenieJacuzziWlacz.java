package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.Jacuzzi;

public class PolecenieJacuzziWlacz implements Polecenie {
	Jacuzzi jacuzzi;

    public PolecenieJacuzziWlacz(Jacuzzi jacuzzi)
    {
        super();
        this.jacuzzi = jacuzzi;
    }

    @Override
    public void wykonaj() {
        jacuzzi.wlacz();
    }

    @Override
    public void wycofaj() {
        jacuzzi.wylacz();
    }
}
