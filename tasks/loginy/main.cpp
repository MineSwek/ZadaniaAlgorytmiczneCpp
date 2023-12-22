#include <bits/stdc++.h>



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::map<std::string, int> baza;

    int n;
    std::string input;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> input;
        if(baza[input]) {
            std::cout << input << baza[input] << "\n";
            baza[input]++;
        } else {
            std::cout << "OK\n";
            baza[input] = 1;
        }
    }

    return 0;
}