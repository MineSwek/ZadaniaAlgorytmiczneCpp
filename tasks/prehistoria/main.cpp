#include <bits/stdc++.h>

int n, m;
std::vector<int> graf[1000001];
std::vector<int> odwiedzony(1000001, 0);

void dfs(int v, int kolor) {
    odwiedzony[v] = kolor;
    for(auto x: graf[v]) {
        if(!odwiedzony[x]) {
            dfs(x, kolor);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    int kolor = 1;
    for(int i = 1; i <= n; i++) {
        if(!odwiedzony[i]) {
            dfs(i, kolor);
            kolor++;
        }
        
    }

    int q;
    std::cin >> q;

    for(int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        if(odwiedzony[a] == odwiedzony[b]) std::cout << "TAK\n";
        else std::cout << "NIE\n";
        
    }

    return 0;
}