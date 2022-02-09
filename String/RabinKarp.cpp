#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;

const int powsCount = 1e5 + 1;

class RabinKarp {
private:
    vl pows, invPs;
    int mod = 1e9 + 7, k = 1e5 + 5;

    vi searchSubstr(string &str, string &ss) {
        vi res;
        int lenStr = str.length(), lenSS = ss.length();
        long strHash = getHash(ss);
        vl phs = prefixHashes(str);
        for (int i = 0; i + lenSS - 1< lenStr; i += 1) {
            long calcHash = hash(phs, i, lenSS - 1);
            if (strHash == calcHash) res.push_back(i);
        }
        return res;
    }

    long getHash(string &str) {
        int len = str.length();
        long hash = 0;
        for (int i = 0; i < len; i += 1)
            hash = (hash + (str[i] - 'a' + 1) * pows[i]) % mod;
        return hash;
    }

    long hash(vl &phs, int pos, int off) {
        long strH = phs[pos + off];
        long prefH = pos > 0 ? phs[pos - 1] : 0;
        strH = strH - prefH < 0 ? strH + mod : strH;
        return (strH - prefH) * invPs[pos] % mod;
    }

    vl prefixHashes(string &str) {
        int len = str.length();
        vl hashes(len, 0);
        hashes[0] = (str[0] - 'a' + 1) * pows[0] % mod;
        for (int i = 1; i < len; i += 1)
            hashes[i] = hashes[i - 1] + (str[i] - 'a' + 1) * pows[i] % mod;
        return hashes;
    }

    long phi(long n) {
        long res = n;
        for (int i = 2; (long) i * i <= n; i += 1) {
            if (n % i == 0) {
                while (n % i == 0) n /= i;
                res -= res / i;
            }
        }
        if (n > 1) res -= res / n;
        return res;
    }

    long modPow(long n, long pow, int mod) {
        long res = 1;
        while (pow > 0) {
            if (pow & 1) res = res * n % mod;
            n = n * n % mod;
            pow >>= 1;
        }
        return res;
    }

    vl invP() {
        vl invP(powsCount, 0);
        long ph = phi(mod) - 1;
        for (int i = 0; i < powsCount; i += 1)
            invP[i] = modPow(pows[i], ph, mod);
        return invP;
    }

    vl pow() {
        vl pow(powsCount, 1);
        for (int i = 1; i < powsCount; i += 1)
            pow[i] = pow[i - 1] * k % mod;
        return pow;
    }

public:
    RabinKarp() : pows(powsCount, 1), invPs(powsCount, 0) {
        pows = pow();
        invPs = invP();
    }

    void work() {
        string str = "abracadabra";
        string ss = "a";
        vi res = searchSubstr(str, ss);
        for (auto i : res)
            printf("%d ", i);
        cout << "\n";
    }
};