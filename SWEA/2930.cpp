#include<iostream>
#include<vector>
using namespace std;

const int sz = 1e5 + 1;
const int root = 1;
int heap[sz];
int last;
vector<int> answer;

void init() {
    fill(heap,heap+sz,0);
    last = 0;
    answer.clear();
}

void upheap() {
    int index = last;
    while(index>root) {
        int parent = index>>1;
        if(heap[index] > heap[parent]) {
            swap(heap[index],heap[parent]);
        } else {
            break;
        }
        index = index>>1;
    }
}

void downheap() {
    int index = root;
    while(1) {
        int left = index << 1;
        int right = left + 1;
        if(right>last && left>last) {
            break;
        }
        if(right>last) {
            if(heap[index]<heap[left]) {
                swap(heap[index],heap[left]);
            }
            break;
        } else {
            if(heap[index]<heap[left] && heap[index]<heap[right]) {
                if(heap[left] > heap[right]) {
                    swap(heap[left],heap[index]);
                    index = left;
                } else {
                    swap(heap[right],heap[index]);
                    index = right;
                }
            } else {
                if(heap[index]<heap[left]) {
                    swap(heap[left],heap[index]);
                    index = left;
                } else if(heap[index]<heap[right]){
                    swap(heap[right],heap[index]);
                    index = right;
                } else {
                    break;
                }
            }
        }
    }
}

void solution() {
    int n;
    cin>>n;
    int a,b;
    while(n--) {
        cin>>a;
        if(a==1) {
            cin>>b;
            heap[++last] = b;
            upheap();
        } else {
            int par;
            if(!last) {
                par = -1;
            } else {
                par = heap[root];
                heap[root] = heap[last];
                heap[last--] = 0;
                downheap();
            }
            answer.push_back(par);
        }
    }
}

void print() {
    for(auto a:answer) {
        cout<<a<<' ';
    }
    cout<<'\n';
}

void solve() {
    int t;
    cin>>t;
    for(int tc=1; tc<=t; tc++) {
        init();
        solution();
        cout<<'#'<<tc<<' ';
        print();
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    solve();
}
