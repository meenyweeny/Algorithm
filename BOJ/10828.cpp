//
// Created by 이경민 on 2023/01/09.
//
#include<iostream>
using namespace std;

class Stack {
public:
    int arr[10001];
    int top_index;

    Stack() {
        top_index = 0;
    }

    void push(int x) {
        arr[top_index] = x;
        ++top_index;
    }

    bool is_empty() {
        return top_index == 0;
    }

    int top() {
        return is_empty() ? -1 : arr[top_index-1];
    }

    int size() {
        return top_index;
    }

    int pop() {
        if(is_empty()) {
            return -1;
        } else {
            --top_index;
            return arr[top_index];
        }
    }
};

int n,k;
string cmd;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    Stack st;
    while(n--) {
        cin>>cmd;
        if(cmd=="push") {
            cin>>k;
            st.push(k);
        } else if(cmd=="top") {
            cout<<st.top()<<"\n";
        } else if(cmd=="size") {
            cout<<st.size()<<"\n";
        } else if(cmd=="pop") {
            cout<<st.pop()<<"\n";
        } else if(cmd=="empty") {
            cout<<st.is_empty()<<"\n";
        }
    }
}
