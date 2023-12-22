#include <bits/stdc++.h>

struct wyklad {
    int from;
    int to;
    int original_index;
    bool checked;

    wyklad();

    wyklad(int from, int to, int original_index, bool checked = false) {
        this->from = from;
        this->to = to;
        this->checked = checked;
        this->original_index = original_index;
    }
};

struct graniceWykladu {
    int granicaOd;
    int granicaDo;
    int indexWykladu;

    graniceWykladu(int granicaOd, int granicaDo, int indexWykladu) {
        this->granicaOd = granicaOd;
        this->granicaDo = granicaDo;
        this->indexWykladu = indexWykladu;
    }
};

std::vector<wyklad> wyklady;
std::vector<graniceWykladu> graniceWykladow;
std::vector<graniceWykladu> unikatoweWyklady;
std::vector<std::pair<int, int>> paryWykladow;
int n;

bool sortujPoDrugim(const wyklad &a, const wyklad &b) {
    if(a.to < b.to) {
        return true;
    } else if(a.to > b.to) {
        return false;
    } else {
        return (a.from > b.from);
    }
    
}

int sprawdzPrzedzial(int granicaOd, int granicaDo) {
    for(int i = granicaOd; i < granicaDo; i++) {
        if(wyklady[i].to <= wyklady[granicaDo].from && wyklady[i].from >= wyklady[granicaOd].to && wyklady[i].checked == false) {
            wyklady[i].checked = true;
            return i;
        }
    }
    return -1;
}
void znajdzWszystkieUnikatoweWyklady(int indeksGranicyOd, int indexWykladu, int indeksGranicyDo) {
    std::vector<graniceWykladu> graniceWykladow2;
    int aktualnyIndexWykladu = indexWykladu;
    int indOstatniWyklad = -1;
    for(int i = indexWykladu+1; i <= std::min(indeksGranicyDo, n); i++) {
        wyklady[i].checked = false;

        if(wyklady[i].from >= indeksGranicyOd) {
            graniceWykladu gWykladu(aktualnyIndexWykladu, 0, i);
            graniceWykladow2.push_back(gWykladu);
            indOstatniWyklad++;

            indeksGranicyOd = wyklady[i].to;
            aktualnyIndexWykladu = i;
            wyklady[i].checked = true;
            
        }
    }
    
    if(graniceWykladow.size() > 0) {
        while(graniceWykladow[0].indexWykladu <= indeksGranicyDo && graniceWykladow.size() > 0) graniceWykladow.erase(graniceWykladow.begin());
        graniceWykladow2.insert(graniceWykladow2.end(), graniceWykladow.begin(), graniceWykladow.end());
        
    }
    graniceWykladow = graniceWykladow2;
    for(int i = 1; i <= graniceWykladow.size(); i++) {
        graniceWykladow[i-1].granicaDo = graniceWykladow[i].indexWykladu;
    }
    if(graniceWykladow.size() > 0) graniceWykladow[graniceWykladow.size()-1].granicaDo = n+1;
    
    

    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    int a, b;
    std::cin >> n;

    for(int i = 1; i <= n; i++) {
        std::cin >> a >> b;
        wyklady.push_back(wyklad(a, b, i));
    }

    wyklady.push_back(wyklad(0, 0, 0, true));
    wyklady.push_back(wyklad(1000000006, 1000000006, 1000000006, true));

    std::sort(wyklady.begin(), wyklady.end(), sortujPoDrugim);

    //for(auto a: wyklady) std::cout << a.from << " " << a.to << "\n";

    znajdzWszystkieUnikatoweWyklady(0, 0, n);
    //for(auto a: graniceWykladow) std::cout << a.indexWykladu << " " << a.granicaOd << " " << a.granicaDo << "\n";
    //std::cout << "\n\n";
    unikatoweWyklady = graniceWykladow;

    int zapasowyWyklad;
    int ostatniWyklad = 0;
    while(graniceWykladow.size() >= 1) {
        zapasowyWyklad = sprawdzPrzedzial(graniceWykladow[0].granicaOd, graniceWykladow[0].granicaDo);
        for(auto a: graniceWykladow) std::cout << a.indexWykladu << " " << a.granicaOd << " " << a.granicaDo << "\n";
        
        if(zapasowyWyklad != -1) {
            std::cout << "znalazlo\n\n";
            paryWykladow.push_back(std::pair(graniceWykladow[0].indexWykladu, zapasowyWyklad));
            wyklady[zapasowyWyklad].checked = true;
            ostatniWyklad = graniceWykladow[0].indexWykladu;
            graniceWykladow.erase(graniceWykladow.begin());
            

        } else {
            if(graniceWykladow.size() != 1) {
                std::cout << "nie znalazlo\n\n";

                int i = 1;
                while(wyklady[graniceWykladow[0].indexWykladu+i].from < wyklady[ostatniWyklad].to) {
                    i++;
                    if(graniceWykladow[0].indexWykladu+i > n+1) goto koniec;
                }
                //std::cout << "I : " << ostatniWyklad << "\n";
                
                paryWykladow.push_back(std::pair(graniceWykladow[0].indexWykladu, graniceWykladow[0].indexWykladu+i));
                
                wyklady[graniceWykladow[0].indexWykladu+i].checked = true;
                znajdzWszystkieUnikatoweWyklady(wyklady[graniceWykladow[0].indexWykladu+i].to, graniceWykladow[0].indexWykladu, graniceWykladow[1].granicaDo);
                ostatniWyklad = graniceWykladow[0].indexWykladu;
            } else break;
            
        }
        
    }
    koniec:
    //for(auto a: wyklady) std::cout << a.from << " " << a.to << " " << a.checked << "\n";
    //std::cout << "\n\n";
    if(unikatoweWyklady.size()-1 >= paryWykladow.size()) {
        std::cout << unikatoweWyklady.size()-1 << "\n";
        // for(int i = 0; i < unikatoweWyklady.size()-1; i++) {
        //     std::cout << wyklady[unikatoweWyklady[i].indexWykladu].original_index << " " << wyklady[unikatoweWyklady[unikatoweWyklady.size()-1].indexWykladu].original_index << "\n";
        // }
    } else {
        std::cout << paryWykladow.size() << "\n";
        // for(auto a: paryWykladow) {
        //     std::cout << wyklady[a.first].original_index << " " << wyklady[a.second].original_index << "\n";
        // }
    }

    return 0;
}