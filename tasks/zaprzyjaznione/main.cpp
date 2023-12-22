#include <bits/stdc++.h>

int suma(int a) {
    int suma = 1;
    int k = 2;
    while(a > k*k) {
        if(a % k == 0) {
            suma += k;
            suma += a/k;
        }
        k += 1;
    }
    if(a % k == 0) {
        suma += k;
    }
    return suma;
}

int main() {
    int liczba1 = 220;
    int liczba2 = 284;

    if(suma(liczba1) == liczba2 && liczba1 == suma(liczba2)) std::cout << true;
    else std::cout << false;
    

    return 0;
}