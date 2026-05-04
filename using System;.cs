using System;
using System.Numerics;

class RSA
{
    static void Main(){
        BigInteger n = 55; //
        BigInteger e = 3; //
        BigInteger c = 10; //
       
        BigInteger p = 0, q = 0;
        for (BigInteger i = 2; i * i<= n; i++)
        {
            if (n % i == 0)
            {
                p = i;
                q = n /i;
                break;
            }
        }
 Console.WriteLine($"p ={p},q={q}");
 BigInteger phi = (p-1)*(q-1);
 Console.WriteLine($"phi(n)={phi}");
 BigInteger d = ModInverse(e,phi);
 Console.WriteLine($"d = {d}");
 BigInteger M = BigInteger.ModPow(C,d,n);
 Console.WriteLine($"M = {M}");
    }
    static BigInteger
    ModInverse(BigInteger a,BigInteger m)
    {
BigInteger m0 = m,t,q;
BigInteger x0 = 0, x1 = 1;

if (m==1) return 0;
while (a > 1)
{ 
q = a/m;
t = m;

m = a % m;
a = t;
t = x0;

x0 = x1 - q * x0;
x1 = t;
}
if (x1 < 0)
   x1 += m0;
   return x1;
    }
}
    
