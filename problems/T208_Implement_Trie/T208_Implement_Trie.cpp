#include "headers.h"

static const int WORD_LEN = 26;
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        memset(this->next, 0, sizeof(this->next)); // 初始化为零
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie *node = this;
        for (char c: word) {
            int index = c - 'a';
            if (node->next[index] == nullptr) {
                node->next[index] = new Trie();
            }
            node = node->next[index];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie *node = this;
        for (char c: word) {
            int index = c - 'a';
            node = node->next[index];
            if (node == nullptr) {
                return false;
            }
        }
        return node->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *node = this;
        for (char c: prefix) {
            int index = c - 'a';
            node = node->next[index];
            if (node == nullptr) {
                return false;
            }
        }
        return true;
    }
private:
    bool isEnd;
    Trie *next[WORD_LEN];
};

TEST(T208_Implement_Trie, testcase1) {
    Trie trie;
    trie.insert("apple");
    int *p1 = (int *) std::calloc(4, sizeof(int));
    for (int i = 0; i < 4; i++) {
        cout << *(p1 + 1) << endl;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
