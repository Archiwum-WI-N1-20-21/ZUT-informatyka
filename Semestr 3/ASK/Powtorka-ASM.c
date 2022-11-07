#include <stdio.h>

int main(int argc, const char * argv[]) {
    //Zadanie 1
    //wejscie 8 bitowe wyjscie 16 bitowe
    /*
    unsigned char y = 0xff;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    
    a = y * 20;
    a = (y << 4) + (y << 2)
    
    printf("W C %d \n", a);
    
    //Wersja z dodawaniem
    __asm {
        xor ax, ax
        xor bx, bx
        mov al, y
        mov bl, y
        shl ax, 4
        shl bx, 2
        add ax, bx
        mov b, ax
    }
    printf("W ASM Z Dodawaniem %d \n", b);
    
    __asm {
        xor ax, ax
        xor bx, bx
        xor cx, cx
        mov al, y
        mov bl, y
        mov cl, y
        shl ax, 5
        shl bx, 3
        shl cx, 2
        sub ax, bx
        sub ax, cx
        mov c, ax
    }
    
    printf("W ASM Z Odejmowaniem %d \n", c);
    */
    //Zad. 2
    //wejscie ,wyjscie 8 bitowe
    /*
    unsigned char y = 10;
    unsigned char a;
    unsigned char b;
    unsigned char c;

    a = (y << 3) + (y << 1);
    printf("W C %d \n",a);
    
    //Z dodawaniem
    __asm {
        xor ax, ax
        xor bx, bx
        mov al, y
        mov bl, y
        shl al, 3
        shl bl, 1
        add al, bl
        mov b, al
    }
    printf("W ASM z dodawaniem %d \n", b);
    
    //z odejmowaniem
    __asm {
        xor ax, ax
        xor bx, bx
        xor cx, cx
        xor dx, dx
        
        mov al, y
        mov bl, y
        mov cl, y
        
        shl al, 4
        shl bl, 1
        shl cl, 2
        
        sub al, bl
        sub al, cl
        
        mov c, al
    }
    printf("W ASM z Odejmowaniem %d \n", c);
    */
    //Zadanie 3
    //y = 4,75 * a
    //a, y 16-bitowe
    /*
    unsigned short y = 1000;
    unsigned short a;
    unsigned short b;
    unsigned short c;
    
    a = (y << 2) + (y >> 1) + (y >> 2);
    
    printf("W C %d \n", a);

    
    printf("W ASM z dodawaniem %d \n", b);
    
    //Z Odejmowaniem 8 - 2 - 1 - 0.25
    __asm {
        xor ax, ax
        xor bx, bx
        xor cx, cx
        xor dx, dx
        
        mov ax, y
        mov bx, y
        mov cx, y
        mov dx, y
        
        shl ax, 3
        shl bx, 1
        shl cx, 0
        shr dx, 2
        
        sub ax, bx
        sub ax, cx
        sub ax, dx
        
        mov c, ax
    }
    
    printf("W ASM z odejmowaniem %d \n", c);
     */
    
    //Zadanie 4
    // IF ELSE
    /*
    unsigned char y = 0x32;
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    
    if(y == 0x32) {
        a = 0;
    } else {
        a = 1;
    }
    
    printf("W C %d \n", a);
    
    __asm {
        xor ax, ax
        mov al, y
        add al, -0x32
        JNZ et
            mov b, 0
            jmp koniec
        et:
            mov b, 1
            jmp koniec
    koniec:
        
        
    }
    printf("W ASM z dodawaniem %d \n", b);
    
    __asm {
        xor ax, ax
        mov al, y
        sub al, 0x32
        JNZ et
            mov c,0
            jmp koniec
        et:
            mov c, 1
            jmp koniec
    koniec:
        
    }
    
    printf("W ASM z odejmowaniem %d \n", c);
    
    
    __asm {
        xor ax, ax
        mov al, y
        cmp al, 0x32
        JNZ et
            mov d, 0
            jmp koniec
        et:
            mov c, 1
            jmp koniec
        koniec:
    }
    
    printf("W ASM z CMP %d \n", d);
    */
    //Zad 5
    //Pętla For
    /*
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int c = 0;
    
    for(int i =0; i!=5; i++) {
        a += i;
    }
    printf("W C %d \n", a);
    
    __asm {
        xor eax, eax
        xor ebx, ebx
        mov eax, 0
        petla_for:
        cmp eax, 5
        jz petla_for_koniec
            add ebx, eax
            add eax, 1
            jmp petla_for
        petla_for_koniec:
            mov b, ebx
    }
    printf("W ASM Z CMP %d \n", b);
    
    __asm {
        xor eax, eax
        xor ebx, ebx
        mov eax, 5
        petla_for:
        sub eax, 1
        jz petla_for_koniec
            add ebx, eax
            jmp petla_for
        petla_for_koniec:
            mov c, ebx
    }
    
    printf("W ASM Z SUB %d \n", c);
     */
    //Zad 6
    // petla while
    /*
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int c = 0;
    
    while(a != 5) {
        a +=1;
    }
    
    printf("W C %d \n", a);
    
    __asm {
        xor eax, eax
        mov eax ,0
        petla_while:
            cmp eax, 5
            jz petla_while_koniec
                add eax, 1
                jmp petla_while
        petla_while_koniec:
        mov b, eax
    }
    
    printf("W C %d z CMP \n", b);
    
    __asm {
        xor eax, eax
        xor ebx, ebx
    start:
        mov ebx, eax
        sub ebx, 5
        jz koniec
            add eax,1
            jmp start
    koniec:
        mov c, eax
    }
    
    printf("W C %d z SUB \n", c);
    */
    //Zadanie 7
    // do while
    /*
    unsigned int y = 0x00;
    unsigned int y1 = 0x00;
    
    do {
        y+=1;
    } while (y!=5);
    
    printf("W C %d, ", y);
    
    __asm {
        xor eax, eax
        mov eax, y1
    petla_do_while:
        add eax, 1
        cmp eax, 5
        jnz petla_do_while
    mov y1, eax
    }
    
    printf("W ASM %d \n", y1);
     */
    
    //Zadanie 8
    // Zliczanie 1
    /*
    unsigned char x = 0;
    unsigned char y = 0xff;
    
    if(y & 0x01) x +=1;
    if(y & 0x02) x +=1;
    if(y & 0x04) x +=1;
    if(y & 0x08) x +=1;
    if(y & 0x10) x +=1;
    if(y & 0x20) x +=1;
    if(y & 0x40) x +=1;
    if(y & 0x80) x +=1;
    
    printf("Wynik w C %d", x);
    
    unsigned char x1 = 0;
    
    __asm {
        xor al, al
        xor bl, bl
        mov al, 0
        
        mov bl, y
        and bl, 0x01
        add al, bl
        shr y, 1

        mov bl, y
        and bl, 0x01
        add al, bl
        shr y, 1

        mov bl, y
        and bl, 0x01
        add al, bl
        shr y, 1

        mov bl, y
        and bl, 0x01
        add al, bl
        shr y, 1

        mov bl, y
        and bl, 0x01
        add al, bl
        shr y, 1

        mov bl, y
        and bl, 0x01
        add al, bl
        shr y, 1

        mov bl, y
        and bl, 0x01
        add al, bl
        shr y, 1

        mov bl, y
        and bl, 0x01
        add al, bl
        shr y, 1;
        mov x1, al;
    }
    
    printf("W ASM %d \n",x1);
    */
    //Zliczanie 0
    /*
    unsigned char cnt = 8;
    unsigned char y = 0x01;
    
    for(int i = 0; i < 8; i++) {
        cnt -= (y & 0x01);
        y >>= 1;
    }
    
    printf("W C %d", cnt);
    
    cnt = 8;
    y = 0x01;
    
    __asm {
        mov eax, 0
        mov cl, 8
        
        mov al, y
        and al, 0x01
        add bl, al
        shr y, 1
        
        mov al, y
        and al, 0x01
        add bl, al
        shr y, 1
        
        mov al, y
        and al, 0x01
        add bl, al
        shr y, 1
        
        mov al, y
        and al, 0x01
        add bl, al
        shr y, 1
        
        mov al, y
        and al, 0x01
        add bl, al
        shr y, 1
        
        mov al, y
        and al, 0x01
        add bl, al
        shr y, 1
        
        mov al, y
        and al, 0x01
        add bl, al
        shr y, 1
        
        mov al, y
        and al, 0x01
        add bl, al
        shr y, 1
        
        sub cl, bl
        mov cnt, cl
    }
    
    printf("W ASM %d \n", cnt);
     */
    /*
    unsigned char b = 0xAA;
    
    __asm {
        mov bl, b
        and bl, 0xAA
        shr bl, 1
        
        mov al, b
        and al, 0x55
        shl al, 1
        
        or al, bl
        mov b, al
    }
    
    printf("Wynik w ASM %d \n", b);
    */
    return 0;
}
