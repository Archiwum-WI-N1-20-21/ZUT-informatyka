\\ to zadanie prawdopodobnie ma blad w konspekcie, jakis wzor jest zly 

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
alfa = znprimroot(p);
a = random(p-2);
y = lift(modexp(alfa, a, p));
\\ Klucz publiczny to (p, alfa, y)
\\ Klucz prywatny to a
prywatny = a;
print("Klucz publiczny: p: ", p, ", alfa: ", alfa, ", y: ", y);
print("Klucz prywatny: a: ", a);

k = random(p);
phin=(p-1);
while(gcd(k,phin)!=1, k=k+1);

r = lift(modexp(alfa, k, p));
k1 = lift(modexp(k, -1, p-1));
s = lift(modexp(k1 * (m - a * r), 1, p-1));
print("Podpisem wiadomosci jest r: ", r, " // s: ", s);

yr = y ^ r;
rs = r ^ s;
v1 = lift(modexp(yr * rs, 1, p));
v2 = lift(modexp(alfa, m, p));
if (v1 == v2, print("V1 == V2"));