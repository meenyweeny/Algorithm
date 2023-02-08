//
// Created by 이경민 on 2023/02/08.
//
#include<iostream>
using namespace std;

const int sz = 1000001;
int n,m;
unsigned long long tree[sz*4];
int indexpoint;

void get_indexpoint() {
    indexpoint = 2;
    while(indexpoint<=n) {
        indexpoint*=2;
    }
}

void update(int index, int number) {
    index += indexpoint;
    --index;
    tree[index] = number;
    index/=2;
    while(index>0) {
        tree[index] = tree[index*2] + tree[(index*2)+1];
        index/=2;
    }
}

unsigned long long query(int start, int end) {
    start += indexpoint;
    end += indexpoint;
    --start;
    --end;
    unsigned long long sum = 0;
    while(start<=end) {
        if(start%2==1) {
            sum += tree[start];
            ++start;
        }
        if(end%2==0) {
            sum += tree[end];
            --end;
        }
        start/=2;
        end/=2;
    }
    return sum;
}

void solution() {
    cin>>n>>m;
    get_indexpoint();
    int cmd,a,b;
    while(m--) {
        cin>>cmd;
        cin>>a>>b;
        if(cmd==1) {
            update(a,b);
        } else {
            if(a>b) {
                swap(a,b);
            }
            cout<<query(a,b)<<'\n';
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solution();
}
