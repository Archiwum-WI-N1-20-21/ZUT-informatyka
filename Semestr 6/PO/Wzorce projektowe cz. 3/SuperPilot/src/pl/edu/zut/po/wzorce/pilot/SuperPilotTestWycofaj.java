package pl.edu.zut.po.wzorce.pilot;

import pl.edu.zut.po.wzorce.pilot.polecenia.BrakPolecenia;
import pl.edu.zut.po.wzorce.pilot.polecenia.MakroPolecenie;
import pl.edu.zut.po.wzorce.pilot.polecenia.Polecenie;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieDrzwiOtworz;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieDrzwiZamknij;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieJacuzziWlacz;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieJacuzziWylacz;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieSwiatloSciemnij;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieTvWlacz;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieTvWlaczDVD;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieTvWylacz;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieWentylatorWylacz;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieWentylatorWysokieObroty;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieWiezaWlacz;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieWiezaWlaczCD;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieWiezaWlaczDVD;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieWiezaWylacz;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieWlaczSwiatlo;
import pl.edu.zut.po.wzorce.pilot.polecenia.PolecenieWylaczSwiatlo;
import pl.edu.zut.po.wzorce.pilot.sterowniki.DrzwiGarazu;
import pl.edu.zut.po.wzorce.pilot.sterowniki.Jacuzzi;
import pl.edu.zut.po.wzorce.pilot.sterowniki.Swiatlo;
import pl.edu.zut.po.wzorce.pilot.sterowniki.TV;
import pl.edu.zut.po.wzorce.pilot.sterowniki.WentylatorSufitowy;
import pl.edu.zut.po.wzorce.pilot.sterowniki.WiezaStereo;

public class SuperPilotTestWycofaj {
	public static void main(String[] args) {
		SuperPilot superPilot = new SuperPilot();
 
		Swiatlo salonSwiatlo = new Swiatlo("Salon");
		Swiatlo kuchniaSwiatlo = new Swiatlo("Kuchnia");
		WentylatorSufitowy wentylatorSufitowy = new WentylatorSufitowy("Salon");
		DrzwiGarazu garazDrzwi = new DrzwiGarazu("Garaz");
		WiezaStereo wieza = new WiezaStereo("Wieza");
		TV telewizor = new TV("Telewizor");
		Jacuzzi jacuzzi = new Jacuzzi();
		
		Polecenie salonSwiatloWlacz = new PolecenieWlaczSwiatlo(salonSwiatlo);
		Polecenie salonSwiatloWylacz = new PolecenieWylaczSwiatlo(salonSwiatlo);
		Polecenie salonSwiatloSciemnij = new PolecenieSwiatloSciemnij(salonSwiatlo);
		Polecenie kuchniaSwiatloWlacz = new PolecenieWlaczSwiatlo(kuchniaSwiatlo);
		Polecenie kuchniaSwiatloWylacz = new PolecenieWylaczSwiatlo(kuchniaSwiatlo);
		Polecenie kuchniaSwiatloSciemnij = new PolecenieSwiatloSciemnij(kuchniaSwiatlo);
		Polecenie salonWentylatorWysObr = new PolecenieWentylatorWysokieObroty(wentylatorSufitowy);
		Polecenie salonWentylatorWylacz = new PolecenieWentylatorWylacz(wentylatorSufitowy);
		Polecenie garazDrzwiOtworz = new PolecenieDrzwiOtworz(garazDrzwi);
		Polecenie garazDrzwiZamknij = new PolecenieDrzwiZamknij(garazDrzwi);
		Polecenie stereoWlacz = new PolecenieWiezaWlacz(wieza);
		Polecenie stereoWlaczCD = new PolecenieWiezaWlaczCD(wieza);
		Polecenie stereoWlaczDVD = new PolecenieWiezaWlaczDVD(wieza);
		Polecenie stereoWylacz = new PolecenieWiezaWylacz(wieza);
		Polecenie tvWlacz = new PolecenieTvWlacz(telewizor);
		Polecenie tvWlaczDVD = new PolecenieTvWlaczDVD(telewizor);
		Polecenie tvWylacz = new PolecenieTvWylacz(telewizor);
		Polecenie jacuzziWlacz = new PolecenieJacuzziWlacz(jacuzzi);
		Polecenie jacuzziWylacz = new PolecenieJacuzziWylacz(jacuzzi);
		
		Polecenie[] wszystkieSwiatloWlacz = {salonSwiatloWlacz, kuchniaSwiatloWlacz};
		Polecenie[] wszystkieSwiatloWylacz = {salonSwiatloWylacz, kuchniaSwiatloWylacz};
		MakroPolecenie swiatlaWlacz = new MakroPolecenie(wszystkieSwiatloWlacz);
		MakroPolecenie swiatlaWylacz = new MakroPolecenie(wszystkieSwiatloWylacz);
		
		Polecenie[] imprezaParWlacz = {salonSwiatloSciemnij, kuchniaSwiatloSciemnij, stereoWlacz, stereoWlaczDVD, tvWlacz, tvWlaczDVD, jacuzziWlacz};
		Polecenie[] imprezaParWylacz = {salonSwiatloWlacz, kuchniaSwiatloWlacz, stereoWylacz, tvWylacz, jacuzziWylacz};
		MakroPolecenie imprezaWlacz = new MakroPolecenie(imprezaParWlacz);
		MakroPolecenie imprezaWylacz = new MakroPolecenie(imprezaParWylacz);
		
		superPilot.ustawPolecenie(0, salonSwiatloWlacz, salonSwiatloWylacz);
		superPilot.ustawPolecenie(1, kuchniaSwiatloWlacz, kuchniaSwiatloWylacz);
		superPilot.ustawPolecenie(2, salonWentylatorWysObr, salonWentylatorWylacz);
		superPilot.ustawPolecenie(3, garazDrzwiOtworz, garazDrzwiZamknij);
		superPilot.ustawPolecenie(4, stereoWlaczCD, stereoWylacz);
		superPilot.ustawPolecenie(5, swiatlaWlacz, swiatlaWylacz);
		superPilot.ustawPolecenie(6, imprezaWlacz, imprezaWylacz);
		
		System.out.println(superPilot);
 
		superPilot.wcisnietoPrzyciskWlacz(0);
		superPilot.wcisnietoPrzyciskWycofaj();
		superPilot.wcisnietoPrzyciskWylacz(0);
		superPilot.wcisnietoPrzyciskWlacz(1);
		superPilot.wcisnietoPrzyciskWycofaj();
		superPilot.wcisnietoPrzyciskWylacz(1);
		superPilot.wcisnietoPrzyciskWycofaj();
		superPilot.wcisnietoPrzyciskWlacz(2);
		superPilot.wcisnietoPrzyciskWycofaj();
		superPilot.wcisnietoPrzyciskWylacz(2);
		superPilot.wcisnietoPrzyciskWycofaj();
		superPilot.wcisnietoPrzyciskWlacz(3);
		superPilot.wcisnietoPrzyciskWycofaj();
		superPilot.wcisnietoPrzyciskWylacz(3);
		superPilot.wcisnietoPrzyciskWycofaj();
		superPilot.wcisnietoPrzyciskWlacz(4);
		superPilot.wcisnietoPrzyciskWycofaj();
		superPilot.wcisnietoPrzyciskWylacz(4);
		superPilot.wcisnietoPrzyciskWycofaj();
		
		System.out.println();
		superPilot.wcisnietoPrzyciskWlacz(5);
		superPilot.wcisnietoPrzyciskWycofaj();
		
		System.out.println();
		superPilot.wcisnietoPrzyciskWlacz(6);
		superPilot.wcisnietoPrzyciskWycofaj();
	}
}
