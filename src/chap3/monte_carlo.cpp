#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
const int NUMBER_OF_SAMPLES = 1000;

int main(){
    srand((unsigned)time(NULL));
    int cnt = 0;
    rep(i, NUMBER_OF_SAMPLES){
        double px = 1.0 * (rand() % 32768+0.5)/32768.0;
        double py = 1.0 * (rand() % 32768+0.5)/32768.0;
        if(px * px + py * py<=1.0)cnt++;
    }
    printf("PI = %.5lf\n", 4.0 * cnt / NUMBER_OF_SAMPLES);
    return 0;
}