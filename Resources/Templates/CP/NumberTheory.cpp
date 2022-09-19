class NumberTheory
{

public:
    static int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static int lcm(int a, int b)
    {
        return a / gcd(a, b) * b;
    }

    static int mod(int a, int b)
    {
        return (a % b + b) % b;
    }

    static int modPow(int a, int n, int mod)
    {
        int res = 1;
        while (n > 0)
        {
            if (n & 1)
                res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }

    static int modInv(int a, int mod)
    {
        return modPow(a, mod - 2, mod);
    }

    static int modDiv(int a, int b, int mod)
    {
        return a * modInv(b, mod) % mod;
    }

    static int modComb(int n, int k, int mod)
    {
        int res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % mod;
            res = res * modInv(i + 1, mod) % mod;
        }
        return res;
    }

    static int modFact(int n, int mod)
    {
        int res = 1;
        for (int i = 1; i <= n; i++)
        {
            res = res * i % mod;
        }
        return res;
    }

    static int modPerm(int n, int k, int mod)
    {
        int res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % mod;
        }
        return res;
    }

    static int modCombWithFact(int n, int k, int mod)
    {
        return modDiv(modFact(n, mod), modFact(k, mod) * modFact(n - k, mod) % mod, mod);
    }

    static int modCombWithPerm(int n, int k, int mod)
    {
        return modDiv(modPerm(n, k, mod), modFact(k, mod), mod);
    }

    static int modCombWithFact2(int n, int k, int mod)
    {
        int res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % mod;
            res = res * modInv(i + 1, mod) % mod;
        }
        return res;
    }

    static int modCombWithPerm2(int n, int k, int mod)
    {
        int res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % mod;
        }
        return res;
    }
};