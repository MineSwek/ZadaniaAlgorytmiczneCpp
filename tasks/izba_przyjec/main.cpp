#include <bits/stdc++.h>

struct pacjent {
    long long czas_przyjscia;
    long long numer_opaski;

    bool operator < (const pacjent& p) const {
        if(numer_opaski == p.numer_opaski) {
            return czas_przyjscia > p.czas_przyjscia;
        } else return numer_opaski > p.numer_opaski;
    }

};

std::priority_queue<pacjent> kolejka;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    long long n, k;
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> k;
        if(k == -1) {
            std::cout << kolejka.top().czas_przyjscia << "\n";
            kolejka.pop();
        } else {
            pacjent p;
            p.czas_przyjscia = i;
            p.numer_opaski = k;
            kolejka.push(p);
        }
        
    }

    return 0;
}