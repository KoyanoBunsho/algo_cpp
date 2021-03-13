#include <bits/stdc++.h> 
using namespace std; 
#define rep(i, n) for(int i=0; i<n; i++)
#define NO_OF_CHARS 256  
  
void badCharHeuristic(string str, int size, int badchar[NO_OF_CHARS]){  
    int i;
    rep(i, NO_OF_CHARS)
        badchar[i] = -1;
    rep(i, size)
        badchar[(int) str[i]] = i;  
}
  
void search(string txt, string pat){  
    int m = pat.size();
    int n = txt.size();
    int badchar[NO_OF_CHARS];
    badCharHeuristic(pat, m, badchar);
    int s = 0;
    while(s <= (n - m)){  
        int j = m - 1;  
        while(j >= 0 && pat[j] == txt[s + j])  
            j--;
        if (j < 0){  
            cout << "pattern occurs at shift = " <<  s << endl;  
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;
        }else
            s += max(1, j - badchar[txt[s + j]]);
    }
}
  
int main(){  
    string txt= "ABAAABCD";  
    string pat = "ABC";  
    search(txt, pat);  
    return 0;  
}