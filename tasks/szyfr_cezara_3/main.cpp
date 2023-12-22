#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, licznik = 0;
    bool czyWpisac = true;
    std::string wyniki[3001];
    std::cin >> n;
    for(int i = 0; i<n; i++)
    {
        std::string s1, s2;
        std::cin >> s1 >> s2;
        int sprawdzer = 0;
        czyWpisac = true;
        for(int j = 0; j < s1.size()-1; j++)
        {
            int c1=0,c2=0;
            c2 = s2[j] - '0';
            c1 = s1[j] - '0';
            if(j == 0) sprawdzer = c2 - c1 > 0 ? c2 - c1 : c2 - c1 + 26;
            else {
                int temp = c2 - c1 > 0 ? c2 - c1 : c2 - c1 + 26;
                if(temp != sprawdzer) czyWpisac = false;
            }
        }
        if(!czyWpisac) wyniki[licznik++] = s1;
    }
    
    for(int i = 0; i < licznik; i++)
    {
        std::cout << wyniki[i] << "\n";
    }


    return 0;
}