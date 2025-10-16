#pragma once
#include <iostream>
#include <QString>
#include <vector>

class TrieNode {
public:
    static const int CHAR_SET_SIZE = 256;
    TrieNode* child[CHAR_SET_SIZE];
    bool isEnd;
    QString word;

    TrieNode();
};

class Trie {
private:
    TrieNode* root;
    bool Delete(TrieNode* node, const QString& word, int depth = 0);
    int GetIndex(QChar c);
    QString To_Lower(QString s);
    void DFS(TrieNode* node, std::vector<QString>& list);
    QString normalizeVietnamese(const QString& text);
public:
    Trie();
    ~Trie();
    Trie(const Trie& other);
    Trie& operator=(const Trie& other);
    void Insert(const QString& word);
    bool Find(const QString& word);
    std::vector<QString> Suggest(const QString& prefix);
    bool DeleteWord(const QString& word);
    void Clear();
};
