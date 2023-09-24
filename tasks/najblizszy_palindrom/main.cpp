#include <bits/stdc++.h>

bool czy_palindrom(int k, int dlugosc_k) {
    int i = 0;

    while (i <= (dlugosc_k / 2)) {
        if ((k / int(pow(10, dlugosc_k - i))) % 10 != (k / int(pow(10, i))) % 10) return false;
        i++;
    }
    return true;

}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int k;
    
    std::cin >> k;

    int dlugosc_k = (int)std::log10(k);

    while(!czy_palindrom(k, dlugosc_k)) {
        k += 1;
    }
    std::cout << k;

    return 0;
}