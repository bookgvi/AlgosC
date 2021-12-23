#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<vector<int>> vvi;
typedef vector<vector<long>> vvl;

class LongestCommonSubSequence {
private:
    long k = 1e5 + 5, mod = 1e9 + 7;
    vl pows, invPs;

    /*
     * string str1 = "acd";
      *  string str2 = "zcd";
     * */
    string search(string &str1, string &str2) {
        int len1 = str1.length(), len2 = str2.length(), pos = -1, l = 0, r = min(len1, len2) - 1;
        vl phs1 = prefixHash(str1), phs2 = prefixHash(str2);
        string res;
        while (r - l >= 0) {
            int mid = (r + l) >> 1;
            vl str1hashes(len1 - mid, 0);
            for (int i = 0; i + mid < len1; i += 1)
                str1hashes[i] = hash(phs1, i, mid);
            sort(str1hashes);
            int p = -1;
            for (int i = 0; i + mid < len2; i += 1) {
                long h = hash(phs2, i, mid);
                if (binSearch(h, str1hashes) != -1) {
                    p = i;
                    break;
                }
            }
            if (p != -1) {
                pos = p;
                l = mid + 1;
            } else r = mid - 1;
        }
        if (pos == -1) return "";
        return str2.substr(pos, l).c_str();
    }

    int binSearch(long n, vl &arr) {
        int len = (int) arr.size(), l = 0, r = len - 1;
        while (r - l >= 0) {
            int mid = (r + l) >> 1;
            if (arr[mid] == n) return mid;
            else if (arr[mid] <= n) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    void sort(vl &arr) {
        int len = (int) arr.size(), b = 8, dw = 4;
        vl t(len, 0);
        for (int p = 0; p < dw; p += 1) {
            vi count(1 << b, 0);
            for (int i = 0; i < len; i += 1)
                count[(int) ((arr[i] ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)] += 1;
            for (int i = 1; i < 1 << b; i += 1)
                count[i] += count[i - 1];
            for (int i = len - 1; i >= 0; i -= 1)
                t[--count[(int) ((arr[i] ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)]] = arr[i];
            for (int i = 0; i < len; i += 1)
                arr[i] = t[i];
        }
    }

    long hash(vl &phs, int pos, int off) {
        long strH = phs[pos + off];
        long prefH = pos > 0 ? phs[pos - 1] : 0;
        strH = strH - prefH < 0 ? strH + mod : strH;
        return (strH - prefH) * invPs[pos] % mod;
    }

    vl prefixHash(string &str) {
        int len = (int) str.length();
        vl hashes(len, 0);
        hashes[0] = (str[0] - 'a' + 1) * pows[0] % mod;
        for (int i = 1; i < len; i += 1)
            hashes[i] = hashes[i - 1] + (str[i] - 'a' + 1) * pows[i] % mod;
        return hashes;
    }

    vl getPows() {
        vl pow(k, 1);
        for (int i = 1; i < k; i += 1)
            pow[i] = pow[i - 1] * k % mod;
        return pow;
    }

    vl getInvp() {
        vl invP(k, 0);
        long p = phi(mod) - 1;
        for (int i = 0; i < k; i += 1)
            invP[i] = modPow(pows[i], p, mod);
        return invP;
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
    LongestCommonSubSequence() {
        pows = getPows();
        invPs = getInvp();
    }

    void work() {
        string str1 = "pig";
        string str2 = "ziggi";
        string res = search(str1, str2);
        cout << res;
    }
};