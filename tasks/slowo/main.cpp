#include <bits/stdc++.h>

long long counter = 0;

void podzielStringa(std::string slowo, int iloscGrup, std::string output = "") {
    if(iloscGrup == 1) {
        if(slowo.find('1') != std::string::npos) counter++;
        return;
    } else {
        for(int i = 1; i <= slowo.length() - iloscGrup + 1; i++) {
            std::string substring = slowo.substr(0, i);
            std::string reszta = slowo.substr(i);
            if(substring.find('1') != std::string::npos) podzielStringa(reszta, iloscGrup - 1, output + substring + " ");
            
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::string slowo = "";
    int counterSamoglosek = 0;
    char s;
    while(std::cin >> s) {
        if(s == 'a' or s == 'o' or s == 'i' or s == 'e' or s == 'u' or s == 'y') {
            slowo += "1";
            counterSamoglosek++;
        } else {
            slowo += "0";
        }
        
    }

    for(int i = 2; i <= counterSamoglosek; i++)
        podzielStringa(slowo, i, "");
    std::cout << counter;
    

    return 0;
}