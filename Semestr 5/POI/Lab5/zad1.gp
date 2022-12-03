    setrand(2);
    p = nextprime(random(10^30));
    q = nextprime(random(10^25));
    print("q " q);
    print("p " p);
    n = p * q;    
    e = random(n);
    
    phin=(p-1)*(q-1);
    
    while(gcd(e,phin)!=1, e=e+1);
    print(e);
    
    d = lift(Mod(e,phin)^(-1));
    print((e*d)%phin);
    
    print(log(n)/log(27));
    m=5+21*27+12*27^2+5*27^3+18*27^4;
    print("Szyfrowanie");
    E(x)=lift(Mod(x,n)^e);
    print("Deszyfrowanie");
    D(x)=lift(Mod(x,n)^d);
    secret = lift(Mod(m,n)^e); \\E(x)
    print("sekret " secret);
    print("deszyfrowanie");
    print("wiadomosc m " m);
    print("deszyfrowanie " lift(Mod(secret,n)^d));
    
    print(m+O(27^5));
    factor(n);