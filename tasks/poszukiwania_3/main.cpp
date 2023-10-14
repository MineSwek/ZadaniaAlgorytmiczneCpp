#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int mapa[309][309] = { 0 };

    int m, n;
    std::cin >> m >> n;
    mapa[0][1] = 1;
    
    for(int y = 1; y <= m; y++) {
        for(int x = 1; x <= n; x++) {
            mapa[x][y] = (mapa[x-1][y] + mapa[x][y-1]) % 1000000007;
        }
    }

    std::cout << mapa[n][m];


    return 0;
}