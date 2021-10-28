#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;

vl fact();

long catalan(int n);

void nextPermutation(int * arr, int len);

vi getPermutationByNum(int n, int k);

void sort(int * arr, int start, int len);

void displayArrP(vi arr);

const vl factorial = fact();

int main() {
    vi arr = {1, 2, 3, 4};
    int k = 4;
    vi numP = getPermutationByNum(arr.size(), k);
    cout << "#" << k << ": ";
    displayArrP(numP);
    cout << "\n";

    cout << "1)\t";
    displayArrP(arr);
    for (int i = 1; i < catalan(arr.size()); i += 1) {
        nextPermutation(&arr[0], arr.size());
        cout << i + 1 << ")\t";
        displayArrP(arr);
    }
}

vi getPermutationByNum(int n, int k) {
    vi res;
    int digits[n + 1];
    memset(digits, 0, (n + 1) * sizeof(int));
    for (int i = n; i > 0; i -= 1) {
        int pn = k % factorial[i - 1];
        int d = k / factorial[i - 1];
        if (!pn) pn += factorial[i - 1];
        else d += 1;
        k = pn;
        int pos = 0;
        for (int j = 1; j <= n; j += 1) {
            if (!digits[j]) pos += 1;
            if (d == pos) {
                digits[j] = 1;
                res.push_back(j);
                break;
            }
        }
    }
    return res;
}


void nextPermutation(int * arr, int len) {
    for (int i = len - 2; i >= 0; i -= 1) {
        if (arr[i] < arr[i + 1]) {
            int min = i + 1;
            for (int j = min; j < len; j += 1)
                if (arr[j] < arr[min] && arr[j] > arr[i])
                    min = j;
            swap(arr[i], arr[min]);
            sort(arr, i + 1, len);
            break;
        }
    }
}

void sort(int * arr, int start, int len) {
    int b = 8, dw = 4;
    vi t(len - start);
    int count[1 << b];
    if (len - start > 1) {
        for (int p = 0; p < dw; p += 1) {
            memset(count, 0, (1 << b) * sizeof(int));
            for (int i = start; i < len; i += 1)
                count[((*(arr + i) ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)] += 1;
            for (int i = 1; i < 1 << b; i += 1)
                count[i] += count[i - 1];
            for (int i = len - 1; i >= start; i -= 1)
                t[--count[((*(arr + i) ^ INT_MIN) >> (p * b)) & ((1 << b) - 1)]] = *(arr + i);
            int k = 0;
            for (int i = start; i < len; i += 1)
                *(arr + i) = t[k++];
        }
    }
}

long catalan(int n) {
    return factorial[2 * n] / (factorial[n] * factorial[n + 1]);
}

vl fact() {
    int max = 1e5;
    vl fact(max);
    fact[0] = 1;
    for (int i = 1; i < max; i += 1)
        fact[i] = fact[i - 1] * i;
    return fact;
}

void displayArrP(vi arr) {
    for (int i = 0, len = arr.size(); i < len; i += 1)
        cout << arr[i] << " ";
    cout << "\n";
}