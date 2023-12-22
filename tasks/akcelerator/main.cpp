#include <bits/stdc++.h>

int n, q, a;

int wyszukajBinarnie(const std::vector<int>& predkoscCzasteczek, int k) {
    int poczatek = 0, koniec = predkoscCzasteczek.size() - 1, srodek;

    while (poczatek <= koniec) {
        srodek = poczatek + (koniec - poczatek) / 2;
        if (predkoscCzasteczek[srodek] == k) {
            return srodek;
        } else if (k < predkoscCzasteczek[srodek]) {
            koniec = srodek - 1;
        } else {
            poczatek = srodek + 1;
        }
    }

    return -1;
}

int zliczWystapienia(const std::vector<int>& predkoscCzasteczek, int index, int k) {
    int suma = 0;
    int lewo = index-1, prawo = index+1;
    while(predkoscCzasteczek[lewo] == k || predkoscCzasteczek[prawo] == k) {
        if(predkoscCzasteczek[lewo] == k) suma++;
        if(predkoscCzasteczek[prawo] == k) suma++;
        lewo--;
        prawo++;
    }
    return suma+1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, q, a;
    std::cin >> n;

    std::vector<int> predCzasteczek(n);

    for (int i = 0; i < n; i++) {
        std::cin >> a;
        predCzasteczek[i] = a;
    }

    std::cin >> q;
    for (int i = 0; i < q; i++) {
        std::cin >> a;
        int index = wyszukajBinarnie(predCzasteczek, a);
        if(index == -1) std::cout << "0\n";
        else std::cout << zliczWystapienia(predCzasteczek, index, a) << "\n";
    }

    return 0;
}