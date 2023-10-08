#include <bits/stdc++.h>


int liczbaOperPrzen(unsigned long long l1, unsigned long long l2, int przeniesienia, int przeniesiona) {
    if(l1 == 0 and l2 == 0) return przeniesienia;
    bool czyWieksza = (l1 % 10 + przeniesiona) + (l2 % 10) >= 10;
    return liczbaOperPrzen(l1/10, l2/10, przeniesienia+czyWieksza, czyWieksza);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    unsigned long long liczba1, liczba2;

    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> liczba1 >>  liczba2;
        std::cout << liczbaOperPrzen(liczba1, liczba2, 0, 0) << "\n";
    }

    return 0;
}