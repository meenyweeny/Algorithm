//
// Created by 이경민 on 2023/01/12.
//
#include<iostream>
#include<algorithm>
using namespace std;

int n,q;
int x,y,a,b;
int starting_index;
long long tree[300000];

int get_index() {
    int index = 2;
    while(1) {
        if(index>=n) {
            break;
        }
        index *= 2;
    }
    return index;
}

void init() {
    for(int i=starting_index-1; i>0; i--) {
        tree[i] = tree[i*2] + tree[i*2 + 1];
    }
}

void update(int index, int number) {
    index += starting_index;
    long long gap = number - tree[index];
    while(1) {
        if(index<=0) {
            break;
        }
        tree[index] += gap;
        index /= 2;
    }
}

long long query(int start, int end) {
    start += starting_index;
    end += starting_index;
    long long sum = 0;
    while(start<=end) {
        if(start%2 == 1) {
            sum += tree[start];
            ++start;
        }
        if(end%2 == 0) {
            sum += tree[end];
            --end;
        }
        start /= 2;
        end /= 2;
    }
    return sum;
}

void input() {
    cin>>n>>q;
    starting_index = get_index();
    for(int i=0; i<n; i++) {
        cin>>tree[i+starting_index];
    }
}

void solution() {
    init();
    while(q--) {
        cin>>x>>y>>a>>b;
        --x;
        --y;
        --a;
        if(x>y) {
            swap(x,y);
        }
        cout<<query(x,y)<<"\n";
        update(a,b);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
