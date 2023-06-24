#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

struct Node {
    bool endpoint = false;
    Node* child[10];

    Node() {
        memset(child,0,sizeof(child));
    }

    ~Node() {
        for(int i=0; i<10; i++) {
            if(child[i]) {
                delete child[i];
            }
        }
    }

    bool insert(int value, bool fin) {
        if(child[value]==NULL) {
            child[value] = new Node();
            child[value]->endpoint = fin;
            return true;
        } else {
            return false;
        }
    }
};

int n;
vector<string> tel;

bool comp(string a, string b) {
    return a.size() < b.size();
}

void solution() {
    sort(tel.begin(), tel.end(), comp);

    Node* root = new Node();
    Node* parent;

    int len,now;
    bool flag = true;
    for(auto str:tel) {
        len = str.size();
        parent = root;
        for(int i=0; i < len; i++) {
            now = str[i]-'0';

            if(parent->insert(now, (i==len-1))) {
                parent = parent->child[now];
            } else {
                if(parent->child[now]->endpoint) {
                    flag = false;
                    break;
                } else {
                    parent = parent->child[now];
                    continue;
                }
            }
        }
        if(!flag) {
            break;
        }
    }

    cout<< (flag ? "YES" : "NO") << '\n';
    delete root;
}

void solve() {
    int t;
    cin>>t;
    string s;
    while(t--) {
        cin>>n;
        tel.clear();
        for(int i=0; i<n; i++) {
            cin>>s;
            tel.push_back(s);
        }
        solution();
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
