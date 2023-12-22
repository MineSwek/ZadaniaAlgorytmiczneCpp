#include <bits/stdc++.h>

std::vector<std::string> wyrazy;
std::vector<std::string> wyrazyOryginal;
void bubbleSort(std::string& str) {
    int n = str.length();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp; 
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::string wyraz;
    
    for(int i = 0; i < 277; i++) {
        std::cin >> wyraz;
        wyrazyOryginal.push_back(wyraz);
        bubbleSort(wyraz);
        wyrazy.push_back(wyraz);
    }
    int counter = 0;
    int maxNumber = 0;
    std::vector<std::string> output;
    std::vector<std::string> temp;
    for(int i = 0; i < 277; i++) {
        temp.clear();
        counter = 0;
        for(int j = 0; j < 277; j++) {
            if(wyrazy[i] == wyrazy[j] && i != j) {
                temp.push_back(wyrazyOryginal[j]);
                counter++;
            };
        }
        if(counter > maxNumber) {
            output.clear();
            output.push_back(wyrazyOryginal[i]);
            output.insert(output.end(), temp.begin(), temp.end());
            maxNumber = counter;
        }
    }

    for(auto a: output) {
        std::cout << a << "\n";
    }


    return 0;
}