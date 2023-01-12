//
// Created by 이경민 on 2023/01/11.
//
#include<iostream>
using namespace std;

int n,m,k;
int starting_index;
long long a,b,c;
long long arr[1000001];
long long tree[4000004];

int get_index(int x) {
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
    for(int i=0; i<n; i++) {
        tree[i+starting_index] = arr[i];
    }
    for(int i=starting_index-1; i>0; i--) {
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void update(int idx, long long number) {
    arr[idx] = number;
    idx += starting_index;
    long long gap = number - tree[idx];
    while(1) {
        if(idx<=0) {
            break;
        }
        tree[idx] += gap;
        idx /= 2;
    }
}

long long query(int start, int end) {
    long long sum = 0;
    start += starting_index;
    end += starting_index;
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
    cin>>n>>m>>k;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    starting_index = get_index(n);
}

void solution() {
    init();
    for(int i=0; i<m+k; i++) {
        cin>>a>>b>>c;
        if(a==1) {
            --b;
            update(b,c);
        } else {
            --b;
            --c;
            cout<<query(b,c)<<"\n";
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    input();
    solution();
}
