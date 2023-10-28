#include <bits/stdc++.h>

std::vector<int> alfabet(27, 0);
std::unordered_map<std::string, char> powtorzenie = {};
std::unordered_map<std::string, std::vector<int>> powtorzeniePPrzejscie = {};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    
    long long n, k, a, b;
    std::string S, R;

    std::cin >> n >> k >> a >> b >> S;

    for(long long iloscZnakow = 0; iloscZnakow < (n-k); iloscZnakow++) {
        R = S.substr(iloscZnakow, k);
        if(powtorzeniePPrzejscie.find(R) == powtorzeniePPrzejscie.end()) 
            powtorzeniePPrzejscie[R] = alfabet;
       powtorzeniePPrzejscie[R][int(S[iloscZnakow+k])-97]++;
    }

    for(auto key: powtorzeniePPrzejscie) {
        int maks = *std::max_element(key.second.begin(), key.second.end());
        for(int i = 0; i < 27; i++) {
            if(key.second[i] == maks) {
                powtorzenie[key.first] = char(i+97);
                break;
            }
        }
    }

    std::string output = "";
    char nextChar;
    R = S.substr(n-k, n);
    for(long long iloscZnakow = n; iloscZnakow < b; iloscZnakow++) {
        nextChar = powtorzenie[R];
        if(!nextChar) {
            nextChar = 'a';
            powtorzenie[R] = 'a';
        }
        output.push_back(nextChar);
        R.push_back(nextChar);
        R.erase(R.begin());
        
    }

    std::cout << output.substr(a-n-1, b-n);


    return 0;
}