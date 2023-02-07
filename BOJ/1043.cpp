//
// Created by 이경민 on 2023/02/07.
//
#include<iostream>
#include<vector>
using namespace std;

int n,m;
const int root = 51;
int arr[52];
vector<int> party[51];

int find(int x) {
    if(arr[x]==x) {
        return x;
    } else {
        return arr[x] = find(arr[x]);
    }
}

void merge(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if(xroot!=yroot) {
        arr[yroot] = xroot;
    }
}

bool is_truth(int x) {
    int xroot = find(x);
    return xroot == root;
}

void input() {
    for(int i=1; i<=root; i++) {
        arr[i] = i;
    }
    cin>>n>>m;
    int x,y;
    cin>>x;
    for(int i=0; i<x; i++) {
        cin>>y;
        merge(root,y);
    }
    for(int j=0; j<m; j++) {
        cin>>x;
        for(int i=0; i<x; i++) {
            cin>>y;
            party[j].push_back(y);
        }
    }
}

void solution() {
    bool flag;
    for(int k=0; k<m; k++) {
        for(auto p:party) {
            flag = true;
            for(auto i:p) {
                if(is_truth(i)) {
                    flag = false;
                    break;
                }
            }
            if(!flag) {
                for(auto i:p) {
                    merge(root,i);
                }
            }
        }
    }

    int answer = 0;
    for(int i=0; i<m; i++) {
        vector<int> p=party[i];
        flag = true;
        for(auto i:p) {
            if(find(i)==root) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ++answer;
        }
    }

    cout<<answer;
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
