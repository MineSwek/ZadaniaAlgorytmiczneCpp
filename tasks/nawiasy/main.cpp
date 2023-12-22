#include <bits/stdc++.h>

std::map<char, char> odpowiedniki = {
    {')', '('}, 
    {'}', '{'}, 
    {']', '['}, 
    {'>', '<'}, 
};

char checkIfCorrect(std::string wyrazenie) {
    std::vector<char> fifo;
    for(char a: wyrazenie) {
        if(a == '(' or a == '{' or a == '[' or a == '<') {
            fifo.push_back(a);
        } else if(!fifo.empty() and fifo.back() == odpowiedniki[a]) fifo.pop_back();
        else return 'N';
    }
    if(fifo.empty()) return 'T';
    else return 'N';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::string input;
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::cin >> input;
        std::cout << checkIfCorrect(input) << "\n";
    }

    return 0;
}