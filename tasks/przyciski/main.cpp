#include <iostream>
#include <vector>

struct Przycisk {
    int x;
    int y;
};

int n;
std::vector<std::vector<bool>> przyciski;

bool sprawdzParzyste(const std::vector<Przycisk>& przyciskiVector) {
    for (const auto& p : przyciskiVector) {
        int x = p.x + 1;
        while (x <= n) {
            if (przyciski[p.y][x]) {
                int y = p.y + 1;
                while (y <= n) {
                    if (przyciski[y][x]) {
                        int x2 = x;
                        while (x2 >= 1) {
                            if (przyciski[y][x2] && x2 == p.x) {
                                return true;
                            }
                            x2--;
                        }
                    }
                    y++;
                }
            }
            x++;
        }
    }
    return false;
}

int main() {
    int m;
    std::cin >> n >> m;

    przyciski.resize(n + 1, std::vector<bool>(n + 1, false));
    std::vector<Przycisk> przyciskiVector;

    for (int i = 0; i < m; i++) {
        Przycisk temp;
        std::cin >> temp.y >> temp.x;
        przyciskiVector.push_back(temp);
        przyciski[temp.y][temp.x] = true;
    }

    if (sprawdzParzyste(przyciskiVector))
        std::cout << "TAK";
    else
        std::cout << "NIE";

    return 0;
}
