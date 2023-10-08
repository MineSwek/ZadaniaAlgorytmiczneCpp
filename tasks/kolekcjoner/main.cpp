#include <bits/stdc++.h>

int tab[100005];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    tab[0] = 0;
    std::cin >> tab[1];
    std::cin >> tab[2];
    for(int i = 3; i <= n; i++) {
        std::cin >> tab[i];
        tab[i] += std::max(tab[i-2], tab[i-3]);
    }
    std::cout << std::max(tab[n], tab[n-1]);

    return 0;
}