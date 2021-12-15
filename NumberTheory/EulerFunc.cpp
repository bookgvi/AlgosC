#include "iostream"

class Euler {
public:
    static long euler(int n) {
        int res = n;
        for (int i = 2; (long) i * i <= n; i += 1) {
            if (!(n % i)) {
                while(!(n % i)) n /= i;
                res -= res / i;
            }
        }
        if (n > 1) res -= res / n;
        return res;
    }

    void work() {
        int n = 10;
        long eulerR = euler(n);
        printf("n = %d, euler (phi) = %ld", n, eulerR);
    }
};