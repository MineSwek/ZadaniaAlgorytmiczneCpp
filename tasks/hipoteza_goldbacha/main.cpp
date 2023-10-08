#include <iostream>
#include <vector>

std::vector<bool> sito(100000009);

void sitoErytotenesa(int n) {
    
    for(int i = 2; i*i <= n; i++) {
        if(sito[i] == 0) {
            for(int j = i*i; j <= n; j += i) {
                sito[j] = 1;
            }
        }
            
    }
    
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, drugaLiczba, counter = 0;
    std::cin >> n;

    sito[0], sito[1] = 1;
    sitoErytotenesa(n);
    for(int i = n-1; i >= n/2; i-=2) { 
        if(!sito[i] and !sito[n-i]) counter++;
       
    }
    
    std::cout << counter;
    
    return 0;
}