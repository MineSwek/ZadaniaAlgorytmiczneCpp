#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, najwiekszyDzielnik = 1;
    std::cin >> n;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (i % 2 != 0) najwiekszyDzielnik = std::max(najwiekszyDzielnik, i);
            if ((n / i) % 2 != 0) najwiekszyDzielnik = std::max(najwiekszyDzielnik, n / i);
        }
    }

    std::cout << najwiekszyDzielnik;

    return 0;
}