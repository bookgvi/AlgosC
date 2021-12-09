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
        vi indexes;
        int lenStr =  (int) str.length(), lenSS = (int) ss.length();
        vl phs = prefixHashes(str);
        long strHash = getHash(ss);
        for (int i = 0; i + lenSS - 1 < lenStr; i += 1) {
            long calcHash = hash(phs, i, lenSS - 1);
            if (strHash == calcHash) indexes.push_back(i);
        }
        return indexes;
    }

    long getHash(string &str) {
        int len = (int) str.length();
        long hash = 0;
        for (int i = 0; i < len; i += 1)
            hash = (hash + (str[i] - 'a' + 1) * pows[i]) % mod;
        return hash;
    }

    long hash(vl phs, int pos, int off) {
        long strH = phs[pos + off];
        long prefH = pos > 0 ? phs[pos - 1] : 0;
        strH = strH - prefH < 0 ? strH + mod : strH;
        return (strH - prefH) * invPs[pos] % mod;
    }

    vl prefixHashes(string &str) {
        int len = (int) str.length();
        vl hash(len, 0);
        hash[0] = (str[0] - 'a' + 1) * pows[0] % mod;
        for (int i = 1; i < len; i += 1)
            hash[i] = hash[i - 1] + (str[i] - 'a' + 1) * pows[i] % mod;
        return hash;
    }
    
    vl pow() {
        vl _pows(powsCount, 1);
        for (int i = 1; i < powsCount; i += 1)
            _pows[i] = _pows[i - 1] * k % mod;
        return _pows;
    }
    
    vl invP() {
        vl _invP(powsCount, 0);
        long _phi = phi(mod) - 1;
        for (int i = 0; i < powsCount; i += 1)
            _invP[i] = modPow(pows[i], _phi, mod);
        return _invP;
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

public:
    RabinKarp() : pows(powsCount, 1), invPs(powsCount, 0) {
        pows = pow();
        invPs = invP();
    }

    void work() {
        string str = "abracadabra";
        string ss = "";
        vi res = searchSubstr(str, ss);
        for (auto i : res)
            printf("%d ", i);
        cout << "\n";
    }
};