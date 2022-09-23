template <typename T>
class NumberTheory
{
public:
    static T gcd(T a, T b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    static T lcm(T a, T b)
    {
        return a / gcd(a, b) * b;
    }

    static T mod(T a, T b)
    {
        return (a % b + b) % b;
    }

    static T modPow(T a, T n, T mod)
    {
        T res = 1;
        while (n > 0)
        {
            if (n & 1)
                res = res * a % mod;
            a = a * a % mod;
            n >>= 1;
        }
        return res;
    }

    static T modInv(T a, T mod)
    {
        return modPow(a, mod - 2, mod);
    }

    static T modDiv(T a, T b, T mod)
    {
        return a * modInv(b, mod) % mod;
    }

    static T modComb(T n, T k, T mod)
    {
        T res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % mod;
            res = res * modInv(i + 1, mod) % mod;
        }
        return res;
    }

    static T modFact(T n, T mod)
    {
        T res = 1;
        for (int i = 1; i <= n; i++)
        {
            res = res * i % mod;
        }
        return res;
    }

    static T modPerm(T n, T k, T mod)
    {
        T res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % mod;
        }
        return res;
    }

    static T modCombWithFact(T n, T k, T mod)
    {
        return modDiv(modFact(n, mod), modFact(k, mod) * modFact(n - k, mod) % mod, mod);
    }

    static T modCombWithPerm(T n, T k, T mod)
    {
        return modDiv(modPerm(n, k, mod), modFact(k, mod), mod);
    }

    static T modCombWithFact2(T n, T k, T mod)
    {
        T res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % mod;
            res = res * modInv(i + 1, mod) % mod;
        }
        return res;
    }

    static T modCombWithPerm2(T n, T k, T mod)
    {
        T res = 1;
        for (int i = 0; i < k; i++)
        {
            res = res * (n - i) % mod;
        }
        return res;
    }
};