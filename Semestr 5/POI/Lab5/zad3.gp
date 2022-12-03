setup()={
    p = nextprime(random(10^2));
    N = [2,p-2];
    alpha = random(N);
    return([alpha,p]);
}

Prot(su)={
    N=[1,su[2]-1];
    x = random(N);
    ax = su[1]^x;
    return([ax,x]);
}

Wspol(a,i,p) = {
    K = Mod(a^i,p);
    return(K);
}

Diffie()={
    su = setup();
    print("alpha i p " su);
    a = Prot(su);
    print("a^x i x " a);
    b = Prot(su);
    print("b^y i y " b);
    Ka = Wspol(b[1], a[2], su[2]);
    Kb = Wspol(a[1], b[2], su[2]);
    print("Klucz wspoldzielny dla A " Ka);
    print("Klucz wspoldzielny dla B " Kb);
}