#include <bits/stdc++.h>

int tab[1009][1009] = { 0 };

int pierwsze2[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

bool sprawdzCzyZgodne(int a, int b) {
    int index = 0;
    
    while(pierwsze2[index] <= std::max(a, b)) {
        bool przyp1 = (a % pierwsze2[index] != 0) and (b % pierwsze2[index] == 0);
        bool przyp2 = (a % pierwsze2[index] == 0) and (b % pierwsze2[index] != 0);
        if(przyp1 or przyp2) return false;
        index++;
    }
    return true;
}

bool sprawdzSasiadow(int y, int x) {
    if(tab[y][x-1] != 0 and sprawdzCzyZgodne(tab[y][x], tab[y][x-1])) return true; 
    if(tab[y][x+1] != 0 and sprawdzCzyZgodne(tab[y][x], tab[y][x+1])) return true;
    if(tab[y-1][x] != 0 and sprawdzCzyZgodne(tab[y][x], tab[y-1][x])) return true;
    if(tab[y+1][x] != 0 and sprawdzCzyZgodne(tab[y][x], tab[y+1][x])) return true;
    return false;
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, a1;

    std::cin >> n >> a1;
    int ostatnia = a1;
    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            if(y == 1 and x == 1) tab[y][x] = a1;
            else {
                tab[y][x] = (3*ostatnia%53);
                ostatnia = tab[y][x];              
            }
            
        }
    }
    int counter = 0;
    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            if(sprawdzSasiadow(y, x)) counter++;
        }
    }
    std::cout << counter;

    return 0;
}