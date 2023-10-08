#include <bits/stdc++.h>

bool czyPierwsza(long long n) {
    if(n < 2) return false;
    
    for(long long i = 2; i*i<=n; i++) {
        if(n%i == 0) return false;
    }
    return true;

}

long long sumaBitow(long long n, long long suma, long long temp) {
    if(n <= 1) return suma+n;
    if(czyPierwsza(n)) return sumaBitow(temp, suma+1, 0);
    else return sumaBitow(n-1, suma, temp+1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;
    if(n < 2) std::cout << 1;
    else if(n % 2 == 0 and n != 2) std::cout << 2;
    else std::cout << sumaBitow(n, 0, 0);
    

    return 0;
}