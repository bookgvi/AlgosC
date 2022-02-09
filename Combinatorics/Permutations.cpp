#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<long> vl;

const int MAX = 20;

class Permutation {
private:
    vl fact, catalan;

    string getPermutationByNum(int n, int k) {
        string res;
        vi digits(n + 1, 0);
        for (int i = n - 1; i >= 0; i -= 1) {
            int pn = k % fact[i];
            int d = k / fact[i];
            if (pn == 0) pn = fact[i];
            else d += 1;
            k = pn;
            int pos = 0;
            for (int j = 1; j <= n; j += 1) {
                if (digits[j] != 1) pos += 1;
                if (d == pos) {
                    digits[j] = 1;
                    res += j + '0';
                    break;
                }
            }
        }
        return res;
    }

    vi nextPermutation(vi &arr) {
        int len = (int) arr.size();
        for (int i = len - 2; i >= 0; i -= 1) {
            if (arr[i] < arr[i + 1]) {
                int min = i + 1;
                for (int j = min; j < len; j += 1)
                    if (arr[j] < arr[min] && arr[j] > arr[i])
                        min = j;
                swap(arr[i], arr[min]);
                reverse(i + 1, len - 1, arr);
                break;
            }
        }
        return arr;
    }

    void reverse(int start, int end, vi &arr) {
        for (int i = start; i <= (start + end) >> 1; i += 1) {
            int tmp = start + end - i;
            swap(arr[tmp], arr[i]);
        }
    }

    vl getCatalan() {
        vl catalan(MAX, 1);
        for (int i = 2; i < MAX; i += 1)
            for (int j = 0; j < i; j += 1)
                catalan[i] += catalan[j] * catalan[i - j - 1];
        return catalan;
    }

    vl getFact() {
        vl fact(MAX, 1);
        for (int i = 1; i < MAX; i += 1)
            fact[i] = fact[i - 1] * i;
        return fact;
    }

    void display(vi &arr) {
        for (auto elt : arr)
            cout << elt << " ";
        cout << "\n";
    }

public:
    Permutation() {
        fact = getFact();
        catalan = getCatalan();
    }

    void work() {
        vi startArr = {1, 2, 3, 4, 5};
        int n = (int) startArr.size(), k = 3;
        printf("k = %d\n", k);
        cout << getPermutationByNum(n, k) << "\n";
        for (int i = 0; i < fact[n]; i += 1) {
            display(startArr);
            startArr = nextPermutation(startArr);
        }
    }
};