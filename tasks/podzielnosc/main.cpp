#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int a, b, k;
    std::cin >> a >> b >> k;
    std::cout << (b / k) - ((a-1) / k);

    return 0;
}