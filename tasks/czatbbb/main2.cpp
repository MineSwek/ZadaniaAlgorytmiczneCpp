#include <bits/stdc++.h>
long long k, kDivided;

int hashujString(std::string s) {
    unsigned long long hash = 7;
    
    for(size_t i = 0; i < k; i+=kDivided) {
        hash = hash * 31 + s[i] - 97;
    }
    return hash % 10000000;
}

struct element {
    element* nastepny;
    int data;
    std::vector<int> alfabet;
    int maxNumber = 1;
    char nextChar;
};

element* tablica[10000007] = {NULL};

int main()
{
    long long n, a, b;
    std::string S, R;

    std::cin >> n >> k >> a >> b >> S;

    kDivided = std::max<int>(1, int(sqrt(k)/3));

    for(long long iloscZnakow = 0; iloscZnakow < (n-k); iloscZnakow++) {
        R = S.substr(iloscZnakow, k);
        int hash = hashujString(R);
        element* pointer = tablica[hash];
        if(pointer) {
            while(true) {
                if(!S.compare(pointer->data, k, R)) {
                    int charIndex = int(S[iloscZnakow+k])-97;
                    pointer->alfabet[charIndex]++;
                    if(pointer->maxNumber < pointer->alfabet[charIndex]) pointer->maxNumber = pointer->alfabet[charIndex];
                    break;
                }
                if(pointer->nastepny == NULL) { //Dodanie R
                    element* r = new element;
                    r->data = iloscZnakow;
                    r->nastepny = NULL;
                    r->alfabet.assign(27, 0);
                    r->alfabet[int(S[iloscZnakow+k])-97]++;
                    pointer->nastepny = r;
                    break;
                }
                pointer = pointer->nastepny;
            }
        } else {
            element* r = new element;
            r->data = iloscZnakow;
            r->nastepny = NULL;
            r->alfabet.assign(27, 0);
            r->alfabet[int(S[iloscZnakow+k])-97]++;
            tablica[hash] = r;
        }
        
       
    }

    
    for(element* a: tablica) {
        while(a) {
            
            for(int x = 0; x < 27; x++) {
                if(a->alfabet[x] == a->maxNumber) {
                    a->nextChar = char(x+97);
                    break;
                }
            }
            a = a->nastepny;
        }
    }

    std::string previousR = " ", temp;
    char nextChar;
    element* pointer;
    R = S.substr(n-k, n);
    
    for(long long iloscZnakow = n; iloscZnakow < b; iloscZnakow++) {
        if(R == previousR) {
            for (iloscZnakow = (iloscZnakow > a) ? iloscZnakow : a-1; iloscZnakow < b; iloscZnakow++) {
                std::cout << nextChar;
            }
            break;
        }
        int hash = hashujString(R);
        pointer = tablica[hash];
        while(pointer && (S.compare(pointer->data, k, R))) {
            pointer = pointer->nastepny;
        }
        if(pointer) nextChar = pointer->nextChar;
        else nextChar = 'a';
        if(iloscZnakow >= a-1) std::cout << nextChar;
        
        previousR = R;
        R.push_back(nextChar);
        R.erase(R.begin());
        
    }

    return 0;
}
