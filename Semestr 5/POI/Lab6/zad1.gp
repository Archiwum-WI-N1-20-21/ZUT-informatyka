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

p = nextprime(random(10^6));
alfa = lift(znprimroot(p));
a = random(p-2);
y = lift(modexp(alfa, a, p));
\\ Klucz publiczny to (p, alfa, y)
\\ Klucz prywatny to a
prywatny = a;
print("Klucz publiczny: p: ", p, ", alfa: ", alfa, ", y: ", y);
print("Klucz prywatny: a: ", a);

m = 35;
print("Wiadomosc: ", m);

k = 20; \\losowa k 
gama = lift(modexp(alfa, k, p));
\\ delta = m * lift(modexp(y, k, p));
delta = m * lift(Mod((y^k), p));

print("C = gamma: ", gama, ", delta: " , delta);

m2 = lift(Mod((gama ^ -(a) * delta), p));
print("Odszyfrowana wiadomosc: " m2);