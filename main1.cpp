#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Trie {
public:
    struct Node {
        bool flag = false;
        Node* links[26];
        Node* get(char ch) {
            return links[ch - 'a'];
        }
        void put(char ch, Node* temp) {
            links[ch - 'a'] = temp;
        }
        bool containsKey(char ch) {
            return links[ch - 'a'] != NULL;
        }
    };

    Node* root;
    Trie() {
        root = new Node();
    }

    void insert(string s) {
        Node* temp = root;
        for (int i = 0; i < s.length(); i++) {
            if (!temp->containsKey(s[i]))
                temp->put(s[i], new Node());
            temp = temp->get(s[i]);
        }
        temp->flag = true;
    }

    void search(vector<vector<char>>& board, Node* temp, int i, int j, vector<string>& ans, string s) {
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size() || !temp || board[i][j] == '*' || !temp->containsKey(board[i][j]))
            return;
        s += board[i][j];
        Node* t = temp->get(board[i][j]);
        if (t->flag) {
            ans.push_back(s);
            t->flag = false;
        }
        char ch = board[i][j];
        board[i][j] = '*';
        search(board, temp->get(ch), i + 1, j, ans, s);
        search(board, temp->get(ch), i, j + 1, ans, s);
        search(board, temp->get(ch), i - 1, j, ans, s);
        search(board, temp->get(ch), i, j - 1, ans, s);
        search(board, temp->get(ch), i - 1, j - 1, ans, s);
        search(board, temp->get(ch), i - 1, j + 1, ans, s);
        search(board, temp->get(ch), i + 1, j - 1, ans, s);
        search(board, temp->get(ch), i + 1, j + 1, ans, s);
        board[i][j] = ch;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (string s : words) trie.insert(s);
        vector<string> ans;
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[0].size(); j++)
                trie.search(board, trie.root, i, j, ans, "");
        return ans;
    }
};

int main() {
    srand(time(0)); // seed the random number generator

    int r, c;
    cout << "Enter no of rows: ";
    cin >> r;
    cout << "Enter no of cols: ";
    cin >> c;

    // generate a random board
    vector<vector<char>> board(r, vector<char>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            board[i][j] = 'a' + rand() % 26;

    // generate a random list of words
    vector<string> words = {"a", "about", "after", "all", "also", "an", "and", "another", "any", "are", "as", "at", "be", "because", "been", "before", "being", "between", "both", "but", "by", "came", "can", "come", "could", "did", "do", "each", "even", "for", "from", "further", "furthermore", "get", "got", "had", "has", "have", "he", "her", "here", "hi", "him", "himself", "his", "how", "however", "i", "if", "in", "indeed", "into", "is", "it", "its", "just", "like", "made", "many", "me", "might", "more", "moreover", "most", "much", "must", "my", "never", "not", "now", "of", "on", "only", "or", "other", "our", "out", "over", "said", "same", "see", "she"};
    vector<string> genre_1 = {"mouse", "system", "keyboard", "transformer", "adapter", "battery", "cpu", "harddisk", "hardware", "pendrive", "encode", "decode", "motherboard", "network", "modem", "bluetooth", "speaker", "printer", "cloud"};
    vector<string> genre_2 = {"intel", "input", "debug", "email", "excel", "complier", "proxy", "ascii", "click", "panel", "stack", "queue", "reset", "restart", "virus", "directory", "database", "output", "input", "server", "memory", "binary", "data"};
    vector<string> genre_3 = {"radio", "email", "telegram", "messenger", "facebook", "gmail", "contact", "telephone", "receive", "send", "news", "offline", "online", "connect", "channel", "visual", "media"};

    // display the board
    cout << "The generated board is:" << endl;
    for (const vector<char>& row : board) {
        cout << "\t\t| ";
        for (char cell : row) {
            cout << cell << " | ";
        }
        cout << endl;
    }

    // find words in the board
    Solution solution;
    vector<string> result;

    cout << "GENRE 1: Computer Components" << endl;
    result = solution.findWords(board, genre_1);
    cout << "The words found are:" << endl;
    if (result.empty())
        cout << "NO WORDS FOUND IN THIS GENRE" << endl;
    else {
        for (const string& word : result) {
            cout << "\t*" << word << endl;
        }
    }

    cout << "GENRE 2: Computer Terminology" << endl;
    result = solution.findWords(board, genre_2);
    cout << "The words found are:" << endl;
    if (result.empty())
        cout << "NO WORDS FOUND IN THIS GENRE" << endl;
    else {
        for (const string& word : result) {
            cout << "\t*" << word << endl;
        }
    }

    cout << "GENRE 3: Communication Terminology" << endl;
    result = solution.findWords(board, genre_3);
    cout << "The words found are:" << endl;
    if (result.empty())
        cout << "NO WORDS FOUND IN THIS GENRE" << endl;
    else {
        for (const string& word : result) {
            cout << "\t*" << word << endl;
        }
    }

    cout << "GENRE 4: Default-English Articles" << endl;
    result = solution.findWords(board, words);
    cout << "The words found are:" << endl;
    if (result.empty())
        cout << "NO WORDS FOUND IN THIS GENRE" << endl;
    else {
        for (const string& word : result) {
            cout << "\t*" << word << endl;
        }
    }

    return 0;
}
