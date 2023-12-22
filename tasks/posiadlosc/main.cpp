#include <bits/stdc++.h>


int sumaCyfr(const std::vector<int>& liczby) {
    int suma = 0;
    for (auto a : liczby)
        suma += a;
    return suma;
}

std::vector<int> zamienNaOsobneCyfry(long long a) {
    std::vector<int> cyfry;
    for (int i = 0; i < 19; i++) {
        cyfry.push_back(a % 10);
        a /= 10;
    }
    reverse(cyfry.begin(), cyfry.end());
    return cyfry;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);


    long long a, b;
    std::cin >> a >> b;
    std::vector<int> cyfryA = zamienNaOsobneCyfry(a);
    std::vector<int> cyfryB = zamienNaOsobneCyfry(b);
    std::vector<int> cyfryWynik = cyfryB;

    bool czyDziewiatka = false;
    for (int i = 0; i < 19; i++) {
        if (czyDziewiatka)
            cyfryWynik[i] = 9;
        else if (cyfryA[i] != cyfryB[i]) {
            cyfryWynik[i] = cyfryB[i] - 1;
            czyDziewiatka = true;
        }
    }

    std::cout << std::max(sumaCyfr(cyfryB), sumaCyfr(cyfryWynik)) << "\n";


    return 0;
}