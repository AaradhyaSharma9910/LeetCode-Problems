#include<bits/stdc++.h>
using namespace std;
class Solution {
    struct TrieNode {
        int children[26];
        int bestLen;
        int bestIdx;
        
        TrieNode() {
            fill(begin(children), end(children), -1);
            bestLen = 1e9;
            bestIdx = 1e9;
        }
    };

public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<TrieNode> trie;
        trie.emplace_back();
        
        for (int i = 0; i < wordsContainer.size(); i++) {
            int len = wordsContainer[i].length();
            int curr = 0;
            
            if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
                trie[curr].bestLen = len;
                trie[curr].bestIdx = i;
            }
            
            for (int j = len - 1; j >= 0; j--) {
                int charIdx = wordsContainer[i][j] - 'a';
                
                if (trie[curr].children[charIdx] == -1) {
                    trie[curr].children[charIdx] = trie.size();
                    trie.emplace_back();
                }
                
                curr = trie[curr].children[charIdx];
                
                if (len < trie[curr].bestLen || (len == trie[curr].bestLen && i < trie[curr].bestIdx)) {
                    trie[curr].bestLen = len;
                    trie[curr].bestIdx = i;
                }
            }
        }
        
        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& query : wordsQuery) {
            int curr = 0;
            int len = query.length();
            
            for (int j = len - 1; j >= 0; j--) {
                int charIdx = query[j] - 'a';
                if (trie[curr].children[charIdx] == -1) {
                    break;
                }
                curr = trie[curr].children[charIdx];
            }
            ans.push_back(trie[curr].bestIdx);
        }
        
        return ans;
    }
}; 
/*
Approach
My strategy is to build a highly optimized Trie where every single node keeps track of the "best" container string index that passes through it.

First, I initialize a root node. This root node will keep track of the absolute best string in the entire container, which acts as our fallback answer if a query matches nothing at all.

Then, I loop through the container strings. For each string, I traverse it backwards character by character. If a character path does not exist in the tree, I create a new node. As I step into each node, I check if the current string is "better" (shorter length, or same length but earlier index) than the string that currently owns that node. If it is, I update the node's record.

Finally, I process the queries. For each query, I traverse it backwards. I walk down the Trie following the characters until I hit a dead end. The node where I stop already contains the pre-computed index of the best possible answer. I grab that index and move to the next query.
*/