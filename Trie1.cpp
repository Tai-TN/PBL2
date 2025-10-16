#include "Trie.h"

int GetIndex(char c){// hàm chuyển đổi với mỗi kí tự là 1 index
    if(islower(c)) return c - 'a';
    else if(isupper(c)) return c - 'A' + 26;
    else if(c == ' ') return 52;
    return -1;
}

string To_Lower(string s){// chuyển str sang lower
    for (char &x: s)
        if(isupper(x)) x = tolower(x);
    return s;
}

TrieNode::TrieNode(){
        isEnd = false;
        word = "";
        for (int i = 0 ; i < 53 ; i++)
            child[i] = NULL;
}



class Trie{
private:
    TrieNode* root;

    // Trả về true nếu node có thể bị xoá
    bool Delete(TrieNode* node, const string& word, int depth = 0){
        if (!node) return false;// nếu node hiện tại = null thì false

        if (depth == word.size()) {//duyệt đến kí tự cuối 
            if (!node->isEnd) return false; // nếu nó không phải từ thì ta không xóa
            // nếu phải thì ta xóa nội dung từ đó đi bằng cách cho isEnd = false và word =""
            node->isEnd = false;
            node->word = "";

            // xem no co thang con nao khong.
            for (int i = 0; i < 53; i++)
                if (node->child[i]) return false; //có con thì không xóa node đó
            return true; // nếu không thì cook
        }

        int index = GetIndex(tolower(word[depth]));// xét các kí tự từ trên xuống
        if (index == -1 || !node->child[index]) return false;

        bool shouldDeleteChild = Delete(node->child[index], word, depth + 1);// xét xem có nên xóa thằng con không

        if (shouldDeleteChild) {// nếu mà thằng con xóa được 
            delete node->child[index];// thì xóa thằng con
            node->child[index] = NULL;

            // Nếu node này không phải kết thúc từ và không còn con → xóa tiếp
            if (!node->isEnd) {
                for (int i = 0; i < 53; i++)
                    if (node->child[i]) return false;
                return true;
            }
        }

        return false;
    }

public:
    Trie(){
        root = new TrieNode();// node gốc
    }

    void Insert(const string& word){
        TrieNode* node = root;
        string tmp = To_Lower(word);// chuyển chuối sang thường
        for (char c: tmp){
            int index = GetIndex(c);// lấy chỉ số ứng với kí tự
            if (index == -1) continue;
            if (!node->child[index]) node->child[index] = new TrieNode();// nếu tại 1 kí tự chưa tạo node thì tạo
            node = node->child[index];// chuyển đến kí tự tiếp theo
        }
        node->isEnd = true;// nếu duyệt đến cuối ta đặt dấu hiệu kết thúc bằng isEnd và ghi lại từ đó( từ chưa chuyển sang lower full)
        node->word = word;
    }

    TrieNode* Find(const string& word){
        TrieNode* node = root;
        string tmp = To_Lower(word);
        for (char c: tmp){// duyệt hết từ nếu chưa đến cuối hoặc đến cuối mà nó không isEnd thì không phải là từ
            int index = GetIndex(c);
            if (index == -1 || !node->child[index]) return NULL;
            node = node->child[index];
        }
        return node->isEnd ? node : NULL;
    }

    void DFS(TrieNode* node, vector<string>& list){// tìm từ tại một từ có thể tạo nên nó (ab : abc)
        if (!node) return;
        if (node->isEnd) list.push_back(node->word);
        for (int i = 0; i < 53; i++)
            if (node->child[i]) DFS(node->child[i], list);
    }

    vector<string> Suggest(const string& prefix){
        vector<string> list;
        TrieNode* node = root;
        string tmp = To_Lower(prefix);
        for (char c: tmp){// duyệt đến node cuối của từ chưa hoàn chỉnh này sau đó DFS xem nó có thể tìm được từ nào từ word này không
            int index = GetIndex(c);
            if (index == -1 || !node->child[index]) return list;
            node = node->child[index];
        }
        DFS(node, list);
        return list;
    }

    bool DeleteWord(const string& word){
    	string temp = To_Lower(word);
        if (!Find(temp)) return false;  // kiểm tra có tồn tại không
        Delete(root, temp, 0);
        return true;
    }
};

int main(){
    Trie A;
    while(true){
        cout << "\n1. Insert\n";
        cout << "2. Find\n";
        cout << "3. Suggest\n";
        cout << "4. Delete\n";
        cout << "0. Exit\n";
        int choice;
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            cout << "Nhap tu can chen: ";
            string s; getline(cin, s);
            A.Insert(s);
        }
        else if(choice == 2){
            cout << "Nhap tu can tim: ";
            string s; getline(cin, s);
            cout << (A.Find(s) ? "Found\n" : "Not Found\n");
        }
        else if(choice == 3){
            cout << "Nhap tu goi y: ";
            string s; getline(cin, s);
            vector<string> v = A.Suggest(s);
            if (v.empty()) cout << "Khong co goi y nao.\n";
            else for (string x: v) cout << x << endl;
        }
        else if(choice == 4){
            cout << "Nhap tu can xoa: ";
            string s; getline(cin, s);
            if (A.DeleteWord(s)) cout << "Xoa thanh cong!\n";
            else cout << "Khong tim thay tu can xoa!\n";
        }
        else break;
    }
}
