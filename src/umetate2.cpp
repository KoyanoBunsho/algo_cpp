#include <iostream>
using namespace std;
string s[10];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
void c(int i, int j, bool used[][10]) {
  used[i][j] = true;
  for (int r = 0; r < 4; r++) {
    int tx = i + dx[r], ty = j + dy[r];
    if (tx < 0 || ty < 0 || tx >= 10 || ty >= 10 || s[tx][ty] == 'x' ||
        used[tx][ty])
      continue;
    c(tx, ty, used);
  }
}
int main() {
  bool f = true;
  for (int i = 0; i < 10; f &= s[i++] == "oooooooooo")
    cin >> s[i];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (s[i][j] == 'o')
        continue;
      bool used[10][10] = {}, ff = true;
      c(i, j, used);
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          ff &= s[k][l] == 'x' || used[k][l];
        }
      }
      if (ff) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
