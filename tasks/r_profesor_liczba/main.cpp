#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long long> liczbaSposobow(n+1);
    liczbaSposobow[0], liczbaSposobow[1] = 1;

    for(int i = 2; i <= n+1; i++) {
        liczbaSposobow[i] = liczbaSposobow[i-1] + liczbaSposobow[i-2];
    }

    std::cout << liczbaSposobow[n+1];

    return 0;
}