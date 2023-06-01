package pl.edu.zut.po.wzorce.pilot.polecenia;

import pl.edu.zut.po.wzorce.pilot.sterowniki.DrzwiGarazu;

public class PolecenieDrzwiOtworz implements Polecenie{
    DrzwiGarazu drzwi;

    public PolecenieDrzwiOtworz(DrzwiGarazu drzwi)
    {
        super();
        this.drzwi = drzwi;
    }

    @Override
    public void wykonaj()
    {
        drzwi.podnies();
    }

    @Override
    public void wycofaj()
    {
        drzwi.opusc();
    }
}