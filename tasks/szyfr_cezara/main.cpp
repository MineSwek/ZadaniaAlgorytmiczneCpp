#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);


    std::string s1, s2;
    char c;
    int k, numer;


    std::cin >> s1 >> k >> c;
    std::getline(std::cin, s2);
    s2 = c + s2;
    if(s1 == "szyfruj")
    {
        for(int i = 0; i < s2.length(); i++)
        {
            numer = int(s2[i]);
            if(numer >= 97 && numer <= 122)
            {
                if(numer+k<=122) s2[i] = char(numer + k);
                else {
                    numer = 96 + (numer + k - 122);
                    s2[i]=char(numer);
                }
            }
            else if(numer >= 65 && numer <= 90)
            {
                if(numer+k<=90) s2[i] = char(numer + k);
                else {
                    numer = 64 + (numer + k - 90);
                    s2[i] = char(numer);
                }
            }
            
        }
    }
    else if(s1 == "odszyfruj")
    {
        for(int i = 0; i < s2.length(); i++)
        {
            numer = int(s2[i]);
            if(numer >= 97 && numer <= 122)
            {
                if(numer - k >= 97) s2[i] = char(numer - k);
                else {
                    numer = 122 - (96 - numer);
                    s2[i] = char(numer-k);
                }
            }
            else if(numer >= 65 && numer <= 90)
            {
                if(numer-k >= 65)
                    s2[i] = char(numer - k);
                else {
                    numer = 90 - (64 - numer);
                    s2[i] = char(numer - k);
                }
            }
        }
    }
    std::cout << s2;

    return 0;
}
