#include <bits/stdc++.h>

int stadion[1009][1009] = {0};
int sumyPref[1009][1009] = {0};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    auto start = std::chrono::high_resolution_clock::now();

    
    int n, m, d, d1, d2;
    std::cin >> n >> m >> d;
    for(int i = 0; i < d; i++) {
        std::cin >> d1 >> d2;
        stadion[d1][d2] = 1;
    }

    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= m; x++) {
            sumyPref[y][x] = stadion[y][x] + sumyPref[y-1][x] + sumyPref[y][x-1] - sumyPref[y-1][x-1];
            std::cout << stadion[y][x] << " ";
        }
        std::cout << "\n";
    }

    
    // for(int y = 1; y <= n-k; y++) {
    //     for(int x = 1; x <= m-k; x++) {
    //         long long suma = sumyPref[y+k][x+k] - sumyPref[y-1][x+k] - sumyPref[y+k][x-1] + sumyPref[y-1][x-1];
    //         if(suma > maksimum) maksimum = suma; 
    //     }
    // }
    // std::cout << maksimum;



    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Czas wykonania: " << duration.count() << " sekundy\n";

    return 0;
}