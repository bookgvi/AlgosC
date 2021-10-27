#include "iostream"

class Euler {

public:
    static long euler(int n) {
        int res = n;
        for (int i = 2; i * i <= n; i += 1) {
            if (!(n % i)) {
                while (!(n % i)) n /= i;
                res -= res / i;
            }
        }
        if (n > 1) res -= res / n;
        return res;
    }
};

int amain() {
    const int n = 10;
    std::cout << Euler::euler(n) << "\n";
    return 0;
}
