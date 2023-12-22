#include <bits/stdc++.h>

long long countCarrots(long long r) {
    long long y = 0, result = 0;

    y = r;
    for (long long x = 0; x <= r; x++) {
        while (((x * x) + (y * y) > (r * r)) && y >= 0)
            y--;
        result += y;
    }

    result = 4 * result + 1;

    return result;
}

long long findRadius(long long k) {
    long long left = 0;
    long long right = 5000000;
    while (left < right - 1) {
        long long mid = (left + right) / 2;
        if (countCarrots(mid) >= k)
            right = mid;
        else
            left = mid;
    }
    return right;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;
    std::cout << findRadius(n);

    return 0;
}