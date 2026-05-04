#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//algoritum na evklet
int gcd(int a, int b) {
    while (b !=0) {
        int t =b
        b=a % b;
        a=t;

    }
    return a;

}
//факторизация намиране на p и q

void factorize (int N, int*p, int*q) {
    for (int i=2; i*i <=N; i++){
        if (N % i == 0 ){
            *p=i;
            *q=N/i;
            return;
        }
    }
}
//разширен алгоритъм на евклет за д
int mod_inverse (int e, int phi) {
    int t= 0, newt= 1;
    int r=phi, newr=e;

    while (newr !=0) {
        int q=r /newr;
        int temp = newt;
        newt= t-q * newt;
        t = temp;

        temp=newr;
        newr=r-q*newr;
        r=temp;


    }

    if (r>1) return -1; //Няма обратим елемент
    if (t<0) t +=phi;
    return t;
}

int main () {
    int N=3551;
    int e=11;
    int p=0,q=0;

    //1.факторизация
    factorize(N,&p,&q);
    printf("p=%d, q=%d/n",p,q);
    

    //фукнция на оилер
    int phi=(p - 1) * (q-1);
    printf("phi(N)=%d\n",phi);

    //проверка на d

    int g=gcd(e,phi);
    printf("gcd(e,phi)=%d\n",g);
    
    int d(==-1 ) {
        printf ("No modular inverse. RSA invalid.\n");
        
    } else {
        printf("d=%d\n",d);
    }
    return 0;
}





