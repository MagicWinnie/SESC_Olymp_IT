// credit: https://brestprog.by/topics/modulo/
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const long long MOD = 1e9 + 7;

//base ^ p
long long bin_pow(long long base, long long p, long long MOD)
{
    if (p == 1)
    {
        return base;
    }

    if (p % 2 == 0)
    {
        long long t = bin_pow(base, p / 2, MOD);
        return t * t % MOD;
    }
    else
    {
        return bin_pow(base, p - 1, MOD) * base % MOD;
    }
}

long long inverse_element(long long x, long long MOD)
{
    return bin_pow(x, MOD - 2, MOD);
}

//(a / b) mod m
long long divide(long long a, long long b, long long MOD)
{
    return a * inverse_element(b, MOD) % MOD;
}

int main()
{
    unsigned long long a, q, l, p, top, down;
    cin >> a >> q >> l >> p;
    if (q == 1)
    {
        cout << (a * l) % p << endl;
        return 0;
    }
    top = ((a % p) * ((bin_pow(q, l, p) - (1 % p))% p)) % p;
    down = ((q % p) - (1 % p)) % p;
    cout << divide(top, down, p) << endl; 
}
// (a + b) % m = ((a % m) + (b % m)) % m
// (a - b) % m = ((a % m) - (b % m)) % m
// (a * b) % m = ((a % m) * (b % m)) % m

