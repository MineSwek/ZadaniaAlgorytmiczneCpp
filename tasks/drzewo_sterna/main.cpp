#include <bits/stdc++.h>

struct node {
    node* prawo;
    int licznik;
    int mianownik;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    
    node k = {NULL, 1, 0};
    node p = {&k, 0, 1};
    


    int n;
    std::cin >> n;
    if(n > 0) 
    for(int i = 0; i < n; i++) {
        node* poprzedni = &p;
        node* aktualny = p.prawo;

        while(true) {
            if(!aktualny) break;
            node* w = new node;
            poprzedni->prawo = w;
            w->prawo = aktualny;

            w->licznik = poprzedni->licznik + aktualny->licznik;
            w->mianownik = poprzedni->mianownik + aktualny->mianownik;

            poprzedni = aktualny;
            aktualny = aktualny->prawo;
            
        }
    }

    node* aktualny = &p;
    while(true) {
        if(!aktualny) break;
        std::cout << aktualny->licznik << "/" << aktualny->mianownik << " ";
        aktualny = aktualny->prawo;
    }

    return 0;
}