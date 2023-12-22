#include <bits/stdc++.h>

struct point {
    int wierzcholek;
    long long x;
    long long y;
    point(int wierzcholek, int x, int y) {
        this->wierzcholek = wierzcholek;
        this->x = x;
        this->y = y;
    }
};

int n, p;
long long s;
double maxOdlegosc = 0;
std::vector<int> graf[1009];
std::vector<point> wierzcholki;

std::vector<int> odwiedzony(1009, 0);

void dfs(int v) {
    odwiedzony[v] = 1;
    for(auto a: graf[v]) {
        if(!odwiedzony[a]) {
            double odlegosc = std::sqrt(std::pow((wierzcholki[a].x - wierzcholki[p].x), 2) + std::pow((wierzcholki[a].y - wierzcholki[p].y), 2));
            if(maxOdlegosc < odlegosc) maxOdlegosc = odlegosc;
            dfs(a);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::cin >> n >> p >> s;
    wierzcholki.push_back(point(0, 0, 0));

    for(int i = 1; i <= n; i++) {
        int x, y;
        std::cin >> x >> y;
        wierzcholki.push_back(point(i, x, y));
    }

    for(auto a: wierzcholki) {
        for(auto b: wierzcholki) {
            if(a.wierzcholek != b.wierzcholek && std::sqrt(std::pow((b.x - a.x), 2) + std::pow((b.y - a.y), 2)) <= s) {
                graf[a.wierzcholek].push_back(b.wierzcholek);
                graf[b.wierzcholek].push_back(a.wierzcholek);
            }
        }
    }


    dfs(p);
    printf("%.3f", (maxOdlegosc+s));

    return 0;
}