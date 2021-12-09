#include "iostream"

class Euler {
public:
    static long euler(int n) {
        int res = n;
        for (int i = 2; (long) i * i <= n; i += 1) {
            if (n % i == 0) {
                while(n % i == 0) n /= i;
                res -= res / i;
            }
        }
        if (n > 1) res -= res / n;
        return res;
    }

    void work() {
        int n = 10;
        long eulerR = euler(n);
        cout << "res";
    }
};