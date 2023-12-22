#include <bits/stdc++.h>

int bursztyny[1009][1009] = {0};
long long sumyPref[1009][1009] = {0};
long long maksimum = 0;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    
    int n, m, k;
    std::cin >> n >> m >> k;
    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= m; x++) {
            std::cin >> bursztyny[y][x];
        }
    }

    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= m; x++) {
            sumyPref[y][x] = bursztyny[y][x] + sumyPref[y-1][x] + sumyPref[y][x-1] - sumyPref[y-1][x-1];
        }
    }

    k--;
    for(int y = 1; y <= n-k; y++) {
        for(int x = 1; x <= m-k; x++) {
            long long suma = sumyPref[y+k][x+k] - sumyPref[y-1][x+k] - sumyPref[y+k][x-1] + sumyPref[y-1][x-1];
            if(suma > maksimum) maksimum = suma; 
        }
    }
    std::cout << maksimum;

    return 0;
}