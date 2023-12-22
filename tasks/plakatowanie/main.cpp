#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::set<int> wysokosci;
    std::vector<int> budynki;
    std::vector<int> budynkiOriginal;

    int n, b, counter = 0, roznica = 0, poprzedniaWysokosc = 0;
    bool wykrytoBudynek = false;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> b >> b;
        wysokosci.insert(b);
        budynki.push_back(b);
    }
    budynki.push_back(0);
    budynkiOriginal = budynki;

    while(!wysokosci.empty()) {
        roznica = *wysokosci.begin() - poprzedniaWysokosc;
        for(int i = 0; i < budynki.size(); i++) {
            while(budynki[i] > 0) { 
                if(budynkiOriginal[i] == *wysokosci.begin()) wykrytoBudynek = true; 
                budynki[i] -= roznica;
                i++;
            }
            if(wykrytoBudynek) {
                counter++;
                wykrytoBudynek = false;
            }
            
        }

        poprzedniaWysokosc = *wysokosci.begin();
        wysokosci.erase(wysokosci.begin());
        
    }
    
    std::cout << counter;

    return 0;
}