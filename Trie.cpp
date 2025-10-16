#include "Trie.h"
#include <cctype>
#include <QMessageBox>
#include <utility>

TrieNode::TrieNode() {
    isEnd = false;
    word = "";
    for (int i = 0; i < CHAR_SET_SIZE; i++)
        child[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

Trie::~Trie() {
    if (root){
        Clear();
        root = nullptr;
    }
    
}

void Trie::Clear() {
    // Giải phóng bộ nhớ (đệ quy)
    if (!root) return;
    
    std::vector<TrieNode*> stack = {root};
    while (!stack.empty()) {
        TrieNode* node = stack.back();
        stack.pop_back();
        
        // Lưu tất cả children trước khi xóa node
        for (int i = 0; i < TrieNode::CHAR_SET_SIZE; ++i) {
            if (node->child[i]) {
                stack.push_back(node->child[i]);
                //node->child[i] = nullptr; // Quan trọng: set thành null
            }
        }
        delete node;
    }
    root = nullptr;
}

int Trie::GetIndex(QChar c) {
    if (c.isLetter() || c.isSpace()){
        QChar lowerChar = c.toLower();
        ushort code = lowerChar.unicode();

    if (code < TrieNode::CHAR_SET_SIZE){
        return code;
    }
}
    return -1;
}


QString Trie::To_Lower(QString s) {
    return s.toLower();
}

void Trie::Insert(const QString& word) {
    
    if (root == nullptr){
        root = new TrieNode();
        qDebug() << "Loi : node is null";
    }
    
    TrieNode* node = root;

    QString tmp = To_Lower(word);
    QString normalized = normalizeVietnamese(tmp);

    
    for (QChar c : normalized) {
        int index = GetIndex(c);
        if (index == -1) continue;
        if (root == nullptr){
        qDebug() << "Loi : node is null";
        return; 
    }
        if (!node->child[index]){
            node->child[index] = new TrieNode();
        }
        node = node->child[index];
    }

    node->isEnd = true;
    node->word = word;
}

bool Trie::Find(const QString& word) {
    TrieNode* node = root;
    QString tmp = To_Lower(word);
    for (QChar c : tmp) {
        int index = GetIndex(c);
        if (index == -1 || !node->child[index]) return false;
        node = node->child[index];
    }
    return node->isEnd;
}

void Trie::DFS(TrieNode* node, std::vector<QString>& list) {
    if (!node) return;
    if (node->isEnd) list.push_back(node->word);
    for (int i = 0; i < TrieNode::CHAR_SET_SIZE; i++)
        if (node->child[i]) DFS(node->child[i], list);
}

std::vector<QString> Trie::Suggest(const QString& prefix) {
    std::vector<QString> list;
    if (!root) return list;

    TrieNode* node = root;
    QString tmp = To_Lower(prefix);
    QString normalizedPrefix = normalizeVietnamese(tmp);

    for (QChar c : normalizedPrefix) {
        int index = GetIndex(c);
        if (index == -1 || !node->child[index]) return list;
        node = node->child[index];
    }
    DFS(node, list);
    return list;
}

bool Trie::Delete(TrieNode* node, const QString& word, int depth) {
    if (!node) return false;

    if (depth == word.size()) {
        if (!node->isEnd) return false;
        node->isEnd = false;
        node->word = "";
        for (int i = 0; i < TrieNode::CHAR_SET_SIZE; i++)
            if (node->child[i]) return false;
        return true;
    }

    int index = GetIndex(word[depth]);
    if (index == -1 || !node->child[index]) return false;

    bool shouldDelete = Delete(node->child[index], word, depth + 1);

    if (shouldDelete) {
        delete node->child[index];
        node->child[index] = nullptr;
        if (!node->isEnd) {
            for (int i = 0; i < TrieNode::CHAR_SET_SIZE; i++)
                if (node->child[i]) return false;
            return true;
        }
    }
    return false;
}

bool Trie::DeleteWord(const QString& word) {
    QString tmp = To_Lower(word);
    if (!Find(tmp)) return false;
    Delete(root, tmp, 0);
    return true;
}


Trie::Trie(const Trie& other){
    if (other.root == nullptr){
        root = nullptr;
        return;
    }
    root = new TrieNode();
    *this = other;
}


Trie& Trie::operator=(const Trie& other){
    if (this == &other) return *this;

    Clear();

    if (other.root == nullptr){
        root = nullptr;
        return *this;
    }

    root = new TrieNode();
     std::vector<std::pair<TrieNode*, TrieNode*>> stack;
    stack.push_back({root, other.root});
    
    while (!stack.empty()) {
        auto [current, otherCurrent] = stack.back();
        stack.pop_back();
        
        current->isEnd = otherCurrent->isEnd;
        current->word = otherCurrent->word;
        
        for (int i = 0; i < TrieNode::CHAR_SET_SIZE; i++) {
            if (otherCurrent->child[i]) {
                current->child[i] = new TrieNode();
                stack.push_back({current->child[i], otherCurrent->child[i]});
            }
        }
    }
    

    return *this;
}

QString Trie::normalizeVietnamese(const QString& text){
    QString result = text;

    result = result.replace("á", "a").replace("à", "a").replace("ả", "a").replace("ã", "a").replace("ạ", "a")
                   .replace("ă", "a").replace("ắ", "a").replace("ằ", "a").replace("ẳ", "a").replace("ẵ", "a").replace("ặ", "a")
                   .replace("â", "a").replace("ấ", "a").replace("ầ", "a").replace("ẩ", "a").replace("ẫ", "a").replace("ậ", "a")
                   .replace("é", "e").replace("è", "e").replace("ẻ", "e").replace("ẽ", "e").replace("ẹ", "e")
                   .replace("ê", "e").replace("ế", "e").replace("ề", "e").replace("ể", "e").replace("ễ", "e").replace("ệ", "e")
                   .replace("í", "i").replace("ì", "i").replace("ỉ", "i").replace("ĩ", "i").replace("ị", "i")
                   .replace("ó", "o").replace("ò", "o").replace("ỏ", "o").replace("õ", "o").replace("ọ", "o")
                   .replace("ô", "o").replace("ố", "o").replace("ồ", "o").replace("ổ", "o").replace("ỗ", "o").replace("ộ", "o")
                   .replace("ơ", "o").replace("ớ", "o").replace("ờ", "o").replace("ở", "o").replace("ỡ", "o").replace("ợ", "o")
                   .replace("ú", "u").replace("ù", "u").replace("ủ", "u").replace("ũ", "u").replace("ụ", "u")
                   .replace("ư", "u").replace("ứ", "u").replace("ừ", "u").replace("ử", "u").replace("ữ", "u").replace("ự", "u")
                   .replace("ý", "y").replace("ỳ", "y").replace("ỷ", "y").replace("ỹ", "y").replace("ỵ", "y")
                   .replace("đ", "d")
                   .replace("Á", "a").replace("À", "a").replace("Ả", "a").replace("Ã", "a").replace("Ạ", "a")
                   .replace("Ă", "a").replace("Ắ", "a").replace("Ằ", "a").replace("Ẳ", "a").replace("Ẵ", "a").replace("Ặ", "a")
                   .replace("Â", "a").replace("Ấ", "a").replace("Ầ", "a").replace("Ẩ", "a").replace("Ẫ", "a").replace("Ậ", "a")
                   .replace("É", "e").replace("È", "e").replace("Ẻ", "e").replace("Ẽ", "e").replace("Ẹ", "e")
                   .replace("Ê", "e").replace("Ế", "e").replace("Ề", "e").replace("Ể", "e").replace("Ễ", "e").replace("Ệ", "e")
                   .replace("Í", "i").replace("Ì", "i").replace("Ỉ", "i").replace("Ĩ", "i").replace("Ị", "i")
                   .replace("Ó", "o").replace("Ò", "o").replace("Ỏ", "o").replace("Õ", "o").replace("Ọ", "o")
                   .replace("Ô", "o").replace("Ố", "o").replace("Ồ", "o").replace("Ổ", "o").replace("Ỗ", "o").replace("Ộ", "o")
                   .replace("Ơ", "o").replace("Ớ", "o").replace("Ờ", "o").replace("Ở", "o").replace("Ỡ", "o").replace("Ợ", "o")
                   .replace("Ú", "u").replace("Ù", "u").replace("Ủ", "u").replace("Ũ", "u").replace("Ụ", "u")
                   .replace("Ư", "u").replace("Ứ", "u").replace("Ừ", "u").replace("Ử", "u").replace("Ữ", "u").replace("Ự", "u")
                   .replace("Ý", "y").replace("Ỳ", "y").replace("Ỷ", "y").replace("Ỹ", "y").replace("Ỵ", "y")
                   .replace("Đ", "d");
    return result;
}