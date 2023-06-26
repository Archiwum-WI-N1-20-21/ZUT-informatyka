package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.DrzwiGarazu;

public class PolecenieDrzwiZamknij implements Polecenie {
	DrzwiGarazu drzwi;

    public PolecenieDrzwiZamknij(DrzwiGarazu drzwi)
    {
        super();
        this.drzwi = drzwi;
    }

    @Override
    public void wykonaj()
    {
        drzwi.opusc();
    }

    @Override
    public void wycofaj()
    {
        drzwi.podnies();
    }
}