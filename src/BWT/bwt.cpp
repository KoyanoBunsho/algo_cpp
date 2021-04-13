#include<bits/stdc++.h>
using namespace std;

string bwt_construction(string const &text){
    string bwt{};
    vector<uint64_t> sa(text.size()+1);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&text](uint64_t a, uint64_t b)->bool{
        while(a<text.size() && b<text.size() && text[a]==text[b])++a, ++b;
        if(b==text.size()) return false;
        if(a==text.size()) return true;
        return text[a]<text[b];
    });
    for(auto x: sa){
        if(!x) bwt += "$";
        else bwt += text[x-1];
    }
    return bwt;
}

size_t to_index(char const chr){
    switch(chr){
        case '$': return 0;
        case 'i': return 1;
        case 'm': return 2;
        case 'p': return 3;
        case 's': return 4;
        default: throw logic_error{"There is an illegal character in your text."};
    }
}

vector<uint16_t> compute_count_table(string const &bwt){
    vector<uint16_t>count_table(5);
    for(auto chr:bwt){
        for(size_t i=to_index(chr)+1; i<5; i++) ++count_table[i];
    }
    return count_table;
}

int main(){
    string text{"mississippi"};
    string bwt = bwt_construction(text);
    vector<uint16_t> count_table = compute_count_table(bwt);
    cout << "$ i m p s\n" << "---------\n";
    for(auto c: count_table) cout << c << " ";
    cout << '\n';
}