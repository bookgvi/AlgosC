#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class Eratosthen {
private:
    vi sieve(int n) {
        vi erat(n + 1, 0), primes;
        for (int i = 2; i <=n; i += 1) {
            if (erat[i]) continue;
            primes.push_back(i);
            for (int j = i; j <= n; j += i)
                erat[j] = 1;
        }
        return primes;
    }

public:
    void work() {
        int n = 20;
        vi primes = sieve(n);
        cout << "primes";
    }
};
