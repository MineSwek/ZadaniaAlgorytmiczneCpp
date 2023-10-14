#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int mapa[309][309] = { 0 };

    int n;
    std::cin >> n;
    mapa[0][1] = 1;

    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            int temp;
            std::cin >> temp;
            if(temp != 1)
                mapa[x][y] = (mapa[x-1][y] + mapa[x][y-1]) % 1000000007;
            else 
                mapa[x][y] = 0;
        }
    }

    std::cout << mapa[n][n];


    return 0;
}