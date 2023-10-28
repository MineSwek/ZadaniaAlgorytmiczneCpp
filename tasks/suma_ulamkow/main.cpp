#include <bits/stdc++.h>

struct ulamek {
    long long licznik;
    long long mianownik;
};

 long long nwd(long long a, long long b)
{
    if(b == 0) return a;
    return nwd(b, a%b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    ulamek u1, u2, u3;
    std::cin >> u1.licznik >> u1.mianownik >> u2.licznik >> u2.mianownik;

    u3.mianownik = u1.mianownik * u2.mianownik;
    u3.licznik = u1.licznik*u2.mianownik + u2.licznik*u1.mianownik;

    long long maxDzielna = nwd(u3.licznik, u3.mianownik);

    std::cout << u3.licznik/maxDzielna << "/" << u3.mianownik/maxDzielna;

    return 0;
}