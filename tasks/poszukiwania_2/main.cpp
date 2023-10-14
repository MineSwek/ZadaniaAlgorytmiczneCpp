#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    
    auto mapa = new int[1009][1009];
    int n;
    std::string droga = "";
    std::cin >> n;

    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            int temp;
            std::cin >> temp;
            mapa[x][y] = std::max(mapa[x-1][y], mapa[x][y-1]) + temp;
        }
    }

    int x = n;
    int y = n;
    while(x > 1 || y > 1) {
        if(mapa[x-1][y] >= mapa[x][y-1]) {
            droga = "P" + droga;
            x--;
        }
        else {
            droga = "D" + droga;
            y--;
        }
            
    }

    std::cout << droga;

    return 0;
}