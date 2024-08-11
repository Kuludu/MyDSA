#include <string>

namespace Trie {
    using std::string;

    class Trie {
        struct TrieNode {
            TrieNode* child[26];
            bool isEnd;
        };
        TrieNode* root;

        public:
            Trie() {
                root = new TrieNode();
            }   

            void insert(string word) {
                TrieNode* cur = root;
                for (auto& ch : word) {
                    if (cur->child[ch - 'a'] == nullptr) {
                        cur->child[ch - 'a'] = new TrieNode();
                    }
                    cur = cur->child[ch - 'a'];
                }
                cur->isEnd = true;
            }

            bool search(string word) {
                TrieNode* cur = root;
                for (auto& ch : word) {
                    if (cur->child[ch - 'a'] == nullptr) {
                        return false;
                    }
                    cur = cur->child[ch - 'a'];
                }
                return cur->isEnd;
            }

            bool startsWith(string prefix) {
                TrieNode* cur = root;
                for (auto& ch : prefix) {
                    if (cur->child[ch - 'a'] == nullptr) {
                        return false;
                    }
                    cur = cur->child[ch - 'a'];
                }
                return true;
            }
    };
}