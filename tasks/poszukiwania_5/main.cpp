#include <bits/stdc++.h>

int mapa[309][309] = { 0 };
int mapaDrog[309][309] = { 0 };

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    mapaDrog[0][1] = 1;

    int n;
    std::cin >> n;

    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            int temp;
            std::cin >> temp;
            mapa[x][y] = (std::max(mapa[x-1][y], mapa[x][y-1]) + temp) % 1000000007;
            if(mapa[x-1][y] > mapa[x][y-1]) mapaDrog[x][y] = mapaDrog[x-1][y];
            else if (mapa[x-1][y] < mapa[x][y-1]) mapaDrog[x][y] = mapaDrog[x][y-1];
            else mapaDrog[x][y] = mapaDrog[x-1][y] + mapaDrog[x][y-1];
            mapaDrog[x][y] %= 1000000007;
            
        }
    }

    std::cout << mapaDrog[n][n];
    


    return 0;
}