#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string output;
    while(n >= 1) {
        output = std::to_string(n % 2) + output;
        n /= 2;
    }

    std::cout << output;
    return 0;
}