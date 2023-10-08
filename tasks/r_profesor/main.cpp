#include <bits/stdc++.h>
int counter = 0;
std::string output = "";

void przejscie(int n, std::string schody) {
    if(n == 0) {
        counter++;
        output += schody + "\n";
    }
    if(n >= 1) przejscie(n-1, schody + "1 ");
    if(n >= 2) przejscie(n-2, schody + "2 ");
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    przejscie(n, "");
    std::cout << counter << "\n" << output;

    return 0;
}