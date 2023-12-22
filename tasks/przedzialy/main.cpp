#include <bits/stdc++.h>


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    std::set<int> ciag;

    int maxLiczba = 0;
    std::string pNawias, kNawias;
    int przedzialOd, przedzialDo;

    for(int i = 1; i <= 50; i++) {
        std::cin >> pNawias >> przedzialOd >> przedzialDo >> kNawias;

        int j = (pNawias == "<") ? przedzialOd : przedzialOd+1;
        int k = (kNawias == ">") ? przedzialDo : przedzialDo-1;
        int counter = 0;
        for(j; j <= k; j++) {
            ciag.insert(j);
        }

    }
    int counter = 0;
    int maxPrzedzial = 0;
    int maxPoczatek = 0;
    std::set<int>::iterator poczatek = ciag.begin();
    std::set<int>::iterator it = ciag.begin();
    int poprzednia = *it;
    it++;
    for(it; it != ciag.end(); it++) {
        if(poprzednia+1 == *it) {
            counter++;
        } else {
            if(maxPrzedzial < counter) {
                maxPrzedzial = counter;
                maxPoczatek = *poczatek;
            }
            poczatek = it;
            counter = 0;
            
        }
        poprzednia = *it;
    }
    std::cout << "<" << maxPoczatek << ", " << maxPoczatek+maxPrzedzial << ">";

    return 0;
}