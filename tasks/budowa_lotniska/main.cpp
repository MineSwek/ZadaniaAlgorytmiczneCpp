#include <bits/stdc++.h>

std::string mapaPoziomo[1509];
std::string mapaPionowo[1509];
int n, m;

struct przedzial {
    std::string kierunek;
    int y;
    int from;

    przedzial(std::string kierunek, int y, int from) {
        this->kierunek = kierunek;
        this->y = y;
        this->from = from;
    }

};

void znajdzPrzedzial(std::string tempMapa[1509], std::vector<przedzial>* przedzialy, int y, int dlugoscPasa, std::string kierunek) {
    int i = 0;
    while(i <= n) {
        if(tempMapa[y][i+dlugoscPasa-1] == 'X') i += dlugoscPasa;
        else {
            if(tempMapa[y].substr(i, dlugoscPasa) == std::string(dlugoscPasa, '.')) {
                przedzialy->push_back(przedzial(kierunek, y, i+1));
                i++;
            } else i++;
        }
    }
}

bool sprawdzPrzedzialy(std::vector<przedzial> przedzialy, int dlugoscPasa) {
    for(auto a: przedzialy) {
        for(auto b: przedzialy) {
            if(a.kierunek == b.kierunek) {
                if((b.from > a.from+dlugoscPasa-1 || a.from > b.from+dlugoscPasa-1) || a.y != b.y) {
                    return true;
                }
            } else {
                if((a.y < b.from || a.y > b.from+dlugoscPasa-1) || (b.y < a.from || b.y > a.from+dlugoscPasa-1) ) {
                    return true;
                }
                    
            }
            
        }
    }
    return false;
}

int sprawdz1() {
    int dlugoscPasa, ip = 1, ik = n;
    while(ip <= ik) {
        
        std::vector<przedzial> przedzialy;
        
        dlugoscPasa = (ip+ik)/2;

        for(int y = 1; y <= n; y++) {
            znajdzPrzedzial(mapaPoziomo, &przedzialy, y, dlugoscPasa, "poziomo");
            znajdzPrzedzial(mapaPionowo, &przedzialy, y, dlugoscPasa, "pionowo");
            
        }

        if(!przedzialy.empty()) ip = dlugoscPasa+1;
        else {
            ik = dlugoscPasa-1;
            if(ip > 1) ip--;
        }

        if(ik == 0) return 0;
        
    }
    return dlugoscPasa;
}

int sprawdz2() {
    int dlugoscPasa, ip = 1, ik = n;
    while(ip <= ik) {
        
        std::vector<przedzial> przedzialy;
        
        dlugoscPasa = (ip+ik)/2;

        for(int y = 1; y <= n; y++) {
            znajdzPrzedzial(mapaPoziomo, &przedzialy, y, dlugoscPasa, "poziomo");
            znajdzPrzedzial(mapaPionowo, &przedzialy, y, dlugoscPasa, "pionowo");
            
        }

        bool found = sprawdzPrzedzialy(przedzialy, dlugoscPasa);

        if(found) ip = dlugoscPasa+1;
        else {
            ik = dlugoscPasa-1;
            if(ip > 1) ip--;
        }

        if(ik == 0) return 0;
        
    }
    return dlugoscPasa;
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    char c;
    std::cin >> n >> m;
    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            std::cin >> c;
            mapaPoziomo[y] += c; 
            mapaPionowo[x] += c;
        }
    }
    for(int y = 1; y <= n; y++) {
        for(int x = 1; x <= n; x++) {
            mapaPoziomo[y] += 'X'; 
            mapaPionowo[x] += 'X';
        }
    }

    if(m == 1) std::cout << sprawdz1();
    else std::cout << sprawdz2();
    
    return 0;
}