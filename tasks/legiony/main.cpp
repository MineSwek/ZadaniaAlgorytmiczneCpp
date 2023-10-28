#include <bits/stdc++.h>

long long q=1000000007;

long long potega(long long base, long long power) {
    if (power == 0)
        return 1;
    else if (power % 2 == 0) {
        long long result = potega(base, power / 2);
        return (result * result) % q;
    }
    else
        return (base * potega(base, power - 1)) % q;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, r, k, b, m;

    std::cin>>n;

    for(int i = 0; i < n; i++) {
        std::cin >> r >> k >> b >> m;
        std::cout << (potega(r,k) * potega(b,m)) % q << "\n";
    }

    return 0;
}