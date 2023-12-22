#include <bits/stdc++.h>

std::map<int, int> kamienie;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, input;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> input;
        if(kamienie[input]) std::cout << 'N' << "\n";
        else {
            kamienie[input] = 1;
            std::cout << 'T' << "\n";
        }
    }

    return 0;
}