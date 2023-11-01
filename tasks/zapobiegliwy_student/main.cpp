#include <bits/stdc++.h>

struct wyklad {
    int from;
    int to;
    bool checked;

    wyklad();

    wyklad(int from, int to, bool checked = false) {
        this->from = from;
        this->to = to;
        this->checked = checked;
    }
};

std::vector<wyklad> wyklady;
std::vector<int> maxWykladowIndex;
int counter = 0;

bool sortujPoDrugim(const wyklad &a, const wyklad &b) {
    return (a.to < b.to);
}

std::pair<bool, int> sprawdzPrzedzial(int indexPoczatkowy, int indexKoncowy) {
    for(int i = indexPoczatkowy+1; i < indexKoncowy; i++) {
        if(wyklady[i].to <= wyklady[indexKoncowy].from && wyklady[i].from >= wyklady[indexPoczatkowy].to && !wyklady[i].checked) {
            //std::cout << "Index: " << i << " | Końcowy: " << indexKoncowy << " | " << wyklady[i].from << " " << wyklady[i].to << "\n";
            counter++;
            return std::pair(true, i);
        }
    }
    return std::pair(false, 0);
}


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, a, b;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d", &b);

        wyklady.push_back(wyklad(a, b));
    }

    wyklady.push_back(wyklad(0, 0, true));
    wyklady.push_back(wyklad(1000000006, 1000000006, true));

    std::sort(wyklady.begin(), wyklady.end(), sortujPoDrugim);

    wyklady[1].checked = true;
    wyklad selected = wyklady[1];
    for(int i = 2; i <= n; i++) {
        if(wyklady[i].from >= selected.to) {
            maxWykladowIndex.push_back(i);
            wyklady[i].checked = true;
            selected = wyklady[i];
        }
    }

    maxWykladowIndex.push_back(wyklady.size()-1);
    

    //for(auto x: maxWykladowIndex) std::cout << x << "\n";
    
    int przedzialOd = 0;
    int przedzialDo = 0;
    for(int i = 0; i < maxWykladowIndex.size(); i++) {
        auto temp = sprawdzPrzedzial(przedzialOd, maxWykladowIndex[przedzialDo]);
        if(temp.first) przedzialOd = temp.second;
        else wyklady[maxWykladowIndex[przedzialDo]].checked = false;
        
        przedzialDo++;
    }
    //std::cout << counter << " | " << maxWykladowIndex.size()-1 << "\n";
    std::cout << std::max<int unsigned long long>(counter, maxWykladowIndex.size()-1);

    return 0;
}