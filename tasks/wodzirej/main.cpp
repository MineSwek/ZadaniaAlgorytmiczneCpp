#include <bits/stdc++.h>

std::priority_queue<int, std::vector<int>, std::greater<int>> grupy_osob[10000];

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, m, u, v;
    std::cin >> n >> m;
    for(int i = 0; i < m; i++) {
        std::cin >> u >> v;
        grupy_osob[u].push(v);
        grupy_osob[v].push(u);
    }

    int maxIndexOsoby = 0;
    for(int i = 1; i <= n; i++) {
        if(grupy_osob[i].size() > grupy_osob[maxIndexOsoby].size()) {
            maxIndexOsoby = i;
        }
    }

    std::cout << maxIndexOsoby << "\n";
    while(grupy_osob[maxIndexOsoby].size() > 0) {
        std::cout << grupy_osob[maxIndexOsoby].top() << " ";
        grupy_osob[maxIndexOsoby].pop();
    }



    return 0;
}