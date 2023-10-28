#include <bits/stdc++.h>


bool drzewo[3000000];

int usunGalez(int a) {
    if(!drzewo[a]) return 0;
    drzewo[a] = false;
    return usunGalez(a*2) + usunGalez(a*2 + 1) + 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int h, n, a, counter;
    std::cin >> h >> n;
    counter = pow(2, h) - 1;
    
    for(int i = 1; i <= pow(2, h)-1; i++) {
        drzewo[i] = true;
    }
    for(int i = pow(2, h); i <= pow(2, h+1)-1; i++) {
        drzewo[i] = false;
    }
    
    while(n != 0) {
        std::cin >> a;
        counter -= usunGalez(a);
        n--;
    }
    
    std::cout << counter;
    return 0;
}