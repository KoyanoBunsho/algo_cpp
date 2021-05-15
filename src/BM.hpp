#pragma once
#include <algorithm>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < n; i++)

using namespace std;
vector<int> buildLastFunction(const string &pattern);

static int dummy_bmcomparisons;
int BMmatch(const string &text, const string &pattern,
            int &comparisons = dummy_bmcomparisons) {
  vector<int> last = buildLastFunction(pattern);
  int n = text.size();
  int m = pattern.size();
  int i = m - 1;
  if (i > n - 1)
    return -1;
  int j = m - 1;
  do {
    if (pattern[j] == text[i]) {
      if (j == 0)
        return i;
      else {
        i--;
        j--;
      }
      else {
        i = i + m - min(j, 1 + last[text[i]]);
        j = m - 1;
      }
      comparisons++;
    }
  } while (i <= n - 1);
  return -1;
}

vector<int> buildLastFunction(const string &pattern) {
  const int N_ASCII = 128;
  int i;
  vector<int> last(N_ASCII, -1);
  rep(i, pattern.size()) { last[pattern[i]] = i; }
  return last;
}
