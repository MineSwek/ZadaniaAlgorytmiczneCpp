#include <bits/stdc++.h>

int tab[100009];
int n;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    
    std::cin >> n;
    std::cin >> tab[0];
    std::cin >> tab[1];
    for(int i = 2; i <= n; i++) {
        std::cin >> tab[i];
        tab[i] += std::min(tab[i-1], tab[i-2]);
    }
    std::cout << std::min(tab[n], tab[n-1]);


    return 0;
}