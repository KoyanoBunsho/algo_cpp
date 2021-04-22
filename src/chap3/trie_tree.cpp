#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

const int ALPHABET_SIZE = 26;

struct TrieNode {
  struct TrieNode *children[ALPHABET_SIZE];
  bool isEndOfWord;
};

struct TrieNode *getNode(void) {
  struct TrieNode *pNode = new TrieNode;
  pNode->isEndOfWord = false;
  rep(i, ALPHABET_SIZE) { pNode->children[i] = NULL; }
  return pNode;
}

void insert(struct TrieNode *root, string key) {
  struct TrieNode *pCrawl = root;
  rep(i, key.length()) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index]) {
      pCrawl->children[index] = getNode();
    }
    pCrawl = pCrawl->children[index];
  }
  pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, string key) {
  struct TrieNode *pCrawl = root;
  rep(i, key.length()) {
    int index = key[i] - 'a';
    if (!pCrawl->children[index])
      return false;
    pCrawl = pCrawl->children[index];
  }
  return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main() {
  string keys[] = {"the", "a",   "there", "answer", "any",
                   "by",  "bye", "their", "hey",    "hello"};
  int n = sizeof(keys) / sizeof(keys[0]);
  struct TrieNode *root = getNode();
  rep(i, n) insert(root, keys[i]);
  search(root, "the") ? cout << "Yes\n" : cout << "No\n";
  search(root, "these") ? cout << "Yes\n" : cout << "No\n";
  search(root, "hello") ? cout << "Yes\n" : cout << "No\n";
  return 0;
}
