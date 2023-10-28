#include <bits/stdc++.h>

struct node {
    node* lewo;
    node* prawo;
    int value;
};

void pre(node* w) {
    if(w) {
        std::cout << w->value << " ";
        pre(w->lewo);
        pre(w->prawo);
    }
} 

void in(node* w) {
    if(w) {
        in(w->lewo);
        std::cout << w->value << " ";
        in(w->prawo);
    }
} 

void post(node* w) {
    if(w) {
        post(w->lewo);
        post(w->prawo);
        std::cout << w->value << " ";
    }
}

std::vector<node*> doPrzejscia;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::string przejscie;
    std::cin >> n >> przejscie;

    node root = {NULL, NULL, 1};
    doPrzejscia.push_back(&root);
    int index = 2;

    for(int i = 1; i < n; i++) {
        int lvl = doPrzejscia.size();
        for(int j = 0; j < lvl; j++) {
            node* poczatek = doPrzejscia.front();
            doPrzejscia.erase(doPrzejscia.begin());

            node* l = new node{NULL, NULL, index};
            node* p = new node{NULL, NULL, index+1};
            index+=2;

            poczatek->lewo = l;
            poczatek->prawo = p;
            
            doPrzejscia.push_back(l);
            doPrzejscia.push_back(p);
            
        } 
    }

    if(przejscie == "PRE") pre(&root);
    else if(przejscie == "IN") in(&root);
    else post(&root);


    return 0;
}