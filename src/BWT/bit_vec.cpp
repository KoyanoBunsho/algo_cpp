#include<bits/stdc++.h>
using namespace std;

struct Bitvector{
    vector<int> data;
    Bitvector(size_t const count){
        data.resize((count+63)/64);
    }
    bool read(size_t const i) const{
        return (data[i/64]>>(63-(i%64)))&1;
    }
    void write(size_t const i, bool const value){
        int mask = static_cast<int>(1) << (63-(i%64));
        if(value==true) data[i/64] |= mask;
        else data[i/64] &= ~mask;
    }
};

int main(){
    Bitvector B(10);
    cout << B.read(63) << endl;
    B.write(63, 1);
    cout << B.read(63) << endl;
    B.write(63, 0);
    cout << B.read(63) << endl;
}