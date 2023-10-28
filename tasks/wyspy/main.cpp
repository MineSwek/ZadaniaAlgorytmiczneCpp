#include <bits/stdc++.h>

int macierzSasiedztwa[59][59] = { 0 };
int n, a, b;

void dijkstra(std::vector<int>& odleglosci, std::vector<bool>& czyWierzcholekZrobiony, int wyspaStartowa) {
    odleglosci[wyspaStartowa] = 0;

    for(int i = 0; i < n-1; i++) {
        int min = INT_MAX, min_index;

        for(int w = 0; w < n; w++) {
            if(czyWierzcholekZrobiony[w] == false && odleglosci[w] <= min) 
                min = odleglosci[w], min_index = w;
        }

        int znajdzW = min_index;
        czyWierzcholekZrobiony[znajdzW] = true;

        for(int w = 0; w < n; w++) {
            if(!czyWierzcholekZrobiony[w] && macierzSasiedztwa[znajdzW][w] && odleglosci[znajdzW] != INT_MAX
               && odleglosci[znajdzW] + macierzSasiedztwa[znajdzW][w] < odleglosci[w] && macierzSasiedztwa[znajdzW][w] != odleglosci[znajdzW]) {
                    odleglosci[w] = odleglosci[znajdzW] + macierzSasiedztwa[znajdzW][w];
               }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::cin >> n >> a >> b;

    std::vector<int> odleglosci(n, INT_MAX);
    std::vector<bool> czyWierzcholekZrobiony(n, false);

    for(int y = 0; y < n; y++) {
        for(int x = 0; x < n; x++) {
            std::cin >> macierzSasiedztwa[y][x];
        }
    }

    dijkstra(odleglosci, czyWierzcholekZrobiony, a);


    std::cout << odleglosci[b];

    return 0;
}