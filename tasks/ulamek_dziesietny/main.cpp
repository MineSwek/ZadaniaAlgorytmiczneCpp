#include <bits/stdc++.h>

int NWD(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return NWD(b, a % b);
    }
}

int main() {


    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        float d;
        std::cin >> d;


        int mianownik = 1000000;
        int licznik = round(d * mianownik);

        int nwd = NWD(licznik, mianownik);
        licznik /= nwd;
        mianownik /= nwd;


        if (licznik == 0) {
            std::cout << "0\n";
        } else {
            std::cout << licznik << '/' << mianownik << '\n';
        }
    }

    return 0;
}