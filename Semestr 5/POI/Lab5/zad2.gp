modexp(a,b,n)={
    local(d, bin);
    d=1;
    bin = binary(b);
    for(i=1,length(bin),
    	d=Mod(d*d,n);
    	if(bin[i]==1, d=Mod(d*a,n);
    	);
    );
    return(d);
}

generuj_n() = {
    setrand(2);
    p = nextprime(random(10^30));
    q = nextprime(random(10^25));
    n = p * q;
    return(n);
}

KluczPubliczny(n) = {
    e = random(eulerphi(n));
    while (gcd(e, eulerphi(n)) != 1, e = random(eulerphi(n)));
    return(e);    
}

KluczPrywatny(e,n)={
    bez = bezout(e, eulerphi(n));
    d = lift(Mod(bez[1], eulerphi(n)));
    return(d);
}

hash01(x) = {
	return (x);
}

m = 11;

	print("Generowanie kluczy");
	n = generuj_n();
	print("Wygenerowane n: " n);
	e = KluczPubliczny(n);
	print("Klucz publiczny: " e);
	d = KluczPrywatny(e, n);
	print("Klucz prywatny: " d);

	print("Podpis");
	print("Wiadomosc przed hashowaniem: " m);
	mh = hash01(m);
	print("Wiadomosc po hashowaniu: " m);

	s = lift(modexp(mh, d, n));
	print("Podpis podmiotu A: " s);

	print("Weryfikacja");
	m1 = lift(modexp(s, e, n));
	m2 = hash01(m1);
	
	print("Mh: " mh);
	print("M2: " m2);

	if (mh == m2, print("Prawda"));
	if (mh != m2, print("Falsz"));