#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::string slowo;
    std::string najwiekszeSlowo;

    int counter = 0;
    while(std::cin >> slowo) {
        std::vector<bool> litery(27, false);
        bool found = false;
        for(auto a: slowo) {
            if(litery[int(a)-65] == false) litery[int(a)-65] = true;
            else {
                found = true;
                break;
            }
        }
        if(found == false) {
            counter++;
            if(slowo > najwiekszeSlowo) najwiekszeSlowo = slowo;
        }
        
    }

    std::cout << counter << " " << najwiekszeSlowo;

    return 0;
}