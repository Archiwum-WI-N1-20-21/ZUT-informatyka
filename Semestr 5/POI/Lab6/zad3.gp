p = nextprime(random(10^30));
q = nextprime(random(10^25));

while(lift(modexp(p,1,4)) != 3, p = nextprime(random(10^30)));
while(lift(modexp(p,1,4)) != 3, q = nextprime(random(10^25)));
n = p*q;

m = 78965;

c = lift(modexp(m, 2, n));


mp = lift(modexp(c, 1/4 * (p+1), p));
mq = lift(modexp(c, 1/4 * (q+1), q));

y = bezout(p, q);
yp = y[1];
yq = y[2];

temp = yp * p + yq * q;

r1 = lift(modexp(yp * p * mq + yq * q * mp, 1, n));
r2 = n - r1;
r3 = lift(modexp(yp * p * mq - yq * q * mp, 1, n));
r4 = n - r3;

if (m == r1, print("r1 == m"));
if (m == r2, print("r2 == m"));
if (m == r3, print("r3 == m"));
if (m == r4, print("r4 == m"));