#include <bits/stdc++.h>
using namespace std;
#define CHAR_SIZE 128
#define rep(i, n) for (int i = 0; i < n; i++)

class Trie {
public:
  bool isLeaf;
  Trie *character[CHAR_SIZE];
  Trie() {
    this->isLeaf = false;
    rep(i, CHAR_SIZE) { this->character[i] = nullptr; }
  }
  void insert(string);
  bool deletion(Trie *&, string);
  bool search(string);
  bool haveChildren(Trie const *);
};

void Trie::insert(string key) {
  Trie *curr = this;
  rep(i, key.length()) {
    if (curr->character[key[i]] == nullptr) {
      curr->character[key[i]] = new Trie();
    }
    curr = curr->character[key[i]];
  }
  curr->isLeaf = true;
}

bool Trie::search(string key) {
  if (this == nullptr)
    return false;
  Trie *curr = this;
  rep(i, key.length()) {
    curr = curr->character[key[i]];
    if (curr == nullptr) {
      return false;
    }
  }
  return curr->isLeaf;
}

bool Trie::haveChildren(Trie const *curr) {
  rep(i, CHAR_SIZE) {
    if (curr->character[i])
      return true;
  }
  return false;
}

bool Trie::deletion(Trie *&curr, string key) {
  if (curr == nullptr) {
    return false;
  }
  if (key.length()) {
    if (curr != nullptr && curr->character[key[0]] != nullptr &&
        deletion(curr->character[key[0]], key.substr(1)) &&
        curr->isLeaf == false) {
      if (!haveChildren(curr)) {
        delete curr;
        curr = nullptr;
        return true;
      } else {
        return false;
      }
    }
  }
  if (key.length() == 0 && curr->isLeaf) {
    if (!haveChildren(curr)) {
      delete curr;
      curr = nullptr;
      return true;
    } else {
      curr->isLeaf = false;
      return false;
    }
  }
  return false;
}

int main() {
  Trie *head = new Trie();
  head->insert("hello");
  cout << head->search("hello") << " ";
  head->insert("helloworld");
  cout << head->search("helloworld") << " ";
  cout << head->search("hell") << " ";
  head->insert("hell");
  cout << head->search("hell") << " ";
  head->insert("h");
  cout << head->search("h");
  cout << endl;
  head->deletion(head, "hello");
  cout << head->search("hello") << " ";
  return 0;
}
