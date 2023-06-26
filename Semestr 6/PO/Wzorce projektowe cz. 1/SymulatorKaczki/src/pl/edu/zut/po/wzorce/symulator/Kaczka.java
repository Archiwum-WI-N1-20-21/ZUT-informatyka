package pl.edu.zut.po.wzorce.symulator;

public abstract class Kaczka {
	kwakanieInterfejs kwakanieInt;
	latanieInterfejs latanieInt;
	
    void plywaj() {
    	System.out.println("Pływam jak kaczka.");
    }
    void wyswietl() {
    	System.out.println("Wyglądam jak kaczka.");
    }
    
    void ustawKwaczInt(kwakanieInterfejs i) {
    	this.kwakanieInt = i;
    }
    
    void ustawLecInt(latanieInterfejs i) {
    	this.latanieInt = i;
    }
    
    void wykonajKwacz() {
    	kwakanieInt.kwacz();
    }
    
    void wykonajLec() {
    	latanieInt.lec();
    }
}
