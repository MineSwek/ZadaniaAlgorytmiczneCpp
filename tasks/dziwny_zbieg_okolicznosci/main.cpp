#include <bits/stdc++.h>

int plansza[2009][2009] = {0};
int sumyPref[2009][2009] = {0};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m, q;
    char input;
    std::cin >> n >> m >> q;
    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= m; x++) {
            std::cin >> input;
            if(input == '#') plansza[y][x] = 1;
        }
    }

    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= m; x++) {
            sumyPref[y][x] = plansza[y][x] + sumyPref[y-1][x] + sumyPref[y][x-1] - sumyPref[y-1][x-1];
        }
    }
    int x1, y1, x2, y2;
    for(int i = 0; i < q; i++) {
        std::cin >> x1 >> y1 >> x2 >> y2;
        int suma = sumyPref[y2][x2] - sumyPref[y1-1][x2] - sumyPref[y2][x1-1] + sumyPref[y1-1][x1-1];
        if(suma == 0) std::cout << "TAK\n";
        else std::cout << "NIE\n";
    }

    return 0;
}