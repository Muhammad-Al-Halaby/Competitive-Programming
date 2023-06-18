# Trie (Prefix Tree)

Trie or Prefix Tree is a tree-like data structure that represents a set of strings in the form of a tree.

## Structure

- Building a Trie starts from the root node (a dummy node), and each node represents a character in the string.

- The depth of a node in the tree represents the position of that character in the string.

- Each node has a flag/counter to tell if it represents an end of a string.

- Each node can have at most 26 different neighbors (if strings consist only of Latin letters).

- Each node can store more information than just end of string flag to answer certain queries.

## Time Complexity

- Building a Trie can be done in `O(N * L)` where `N` is the number of strings and `L` is the length of each string.

- Look up a certain string in `O(L)` where `L` is the length of the string.

- Look up a certain prefix in `O(L)` where `L` is the length of the prefix.

- Count the number of occurrences of a certain prefix in `O(L)` where `L` is the length of the prefix.

- Check if strings have common prefixes in `O(N * L)` where `N` is the number of strings and `L` is the length of each string.

## Implementation

```CPP
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;  // Maximum number of nodes.

int child[N][128];  // Stores neighbor nodes numbers.
int childNum[N];  // Stores number of neighbors.
int isEnd[N]; // Stores End of Strings counter for each node.
char childChars[N][128];  // Stores the neighboring characters of each node as a traversal optimization (vector can be used for a better memory).
int nodes;  // Stores the number of nodes in a Trie so far and the index of the next node to be created.


int addNode(){
    memset(child[nodes], -1, sizeof child[nodes]);
    childNum[nodes] = 0;
    isEnd[nodes] = 0;
    return nodes++;
}

void initTrie(){
    nodes = 0;
    addNode();
}

void insert(char* str){
    int cur;
    for(cur = 0 ; *str ; ++str){
        int& nxt = child[cur][*str];
        if(nxt == -1){
            nxt = addNode();
            childChars[cur][childNum[cur]++] =  *str;
        }
        cur = nxt;
    }
    isEnd[cur]++;
}

int n;
char s[N];

int main(){
    initTrie();
    scanf("%d", &n);
    while(n--){
        scanf("%s", s);
        insert(s);
    }
}
```



## Different Implementation

```cpp
class TrieNode{
    public:
        TrieNode* children[26];
        bool isWord;
        TrieNode(){
            isWord = false;
            for(auto & c : children)
                c = nullptr;
        }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* current = root;
        for(auto &character : word){
            int c = character - 'a';
            if(current->children[c] == nullptr){
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
        }
        current->isWord = true;
    }

    bool search(string word, bool prefix = false) {
        TrieNode *current = root;
        for(auto &character : word){
            int c = character - 'a';
            if(current->children[c] == nullptr)
                return false;
            current = current->children[c];
        }
        return (prefix == true || current->isWord);
    }

    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
```

## Problems

1. [PHONELST - Phone List (SPOJ)](https://www.spoj.com/problems/PHONELST/)
1. [A Lot of Games - CF-Div2-D](https://codeforces.com/contest/456/problem/D)
1. [Vasiliy's Multiset - CF-Div2-D](https://codeforces.com/problemset/problem/706/D)
