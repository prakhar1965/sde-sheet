// Solution link: https://takeuforward.org/data-structure/implement-trie-ii/
// CodeStudio link: https://bit.ly/3I8Q9l7
// Leetcode link: https://bit.ly/3qwT4OL

class TrieNode{
    public:
     TrieNode() {
        cnt = 0;
     }
     char c;
     vector<TrieNode*> children;
     int cnt;

};

class Trie{
    TrieNode* head;
    int giveTotalCnt(TrieNode* curr) {
        
        int x = curr->cnt;
        for(auto node: curr->children) {
            x += giveTotalCnt(node);
        } 
        return x;
    }
    public:

    Trie(){
        head = new TrieNode();
        head->c = '$';
    }

    void insert(string &word){
        int n = word.length();
        TrieNode* curr = head;
        for(int i=0; i<n; i++) {
            bool found = 0;
            for(auto x: curr->children) {
                if(x->c == word[i]) {
                    curr = x;
                    found = 1;
                    break;
                }
            }
            if(!found) {
                TrieNode* newNode = new TrieNode();
                newNode->c = word[i];
                curr->children.push_back(newNode);
                curr = newNode;
            }
        }
        curr->cnt ++;
    }

    int countWordsEqualTo(string &word){
        int n = word.length();
        TrieNode* curr = head;
        
        for(int i=0; i<n; i++) {
            bool found = 0;
            for(auto x: curr->children) {
                if(x->c == word[i]) {
                    curr = x;
                    found = 1;
                    break;
                }
            }
            if(!found) return 0;
        }
        return curr->cnt > 0: curr->cnt: 0;
    }

    int countWordsStartingWith(string &word){
         int n = word.length();
        TrieNode* curr = head;
        for(int i=0; i<n; i++) {
            bool found = 0;
            for(auto x: curr->children) {
                if(x->c == word[i]) {
                    curr = x;
                    found = 1;
                    break;
                }
            }
            if(!found) return 0;
        }
        return giveTotalCnt(curr);
    }

    void erase(string &word){
        int n = word.length();
        TrieNode* curr = head;
        
        for(int i=0; i<n; i++) {
            bool found = 0;
            for(auto x: curr->children) {
                if(x->c == word[i]) {
                    curr = x;
                    found = 1;
                    break;
                }
            }
            if(!found) return;
        }
        curr->cnt--;
        if(curr->cnt <0) curr->cnt = 0;
    }
};
