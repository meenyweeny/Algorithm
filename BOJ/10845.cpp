//
// Created by 이경민 on 2023/01/09.
//
#include<iostream>
using namespace std;

class Queue {
public:
    int arr[10001];
    int front_index;
    int back_index;

    Queue() {
        front_index = back_index = 0;
    }

    void push(int x) {
        arr[back_index] = x;
        ++back_index;
    }

    bool is_empty() {
        return front_index == back_index;
    }

    int pop() {
        if(is_empty()) {
            return -1;
        } else {
            ++front_index;
            return arr[front_index-1];
        }
    }

    int size() {
        return back_index-front_index;
    }

    int front() {
        return is_empty() ? -1 : arr[front_index];
    }

    int back() {
        return is_empty() ? -1 : arr[back_index-1];
    }
};

int n,k;
string cmd;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    Queue q;
    while(n--) {
        cin>>cmd;
        if(cmd=="push") {
            cin>>k;
            q.push(k);
        } else if(cmd=="front") {
            cout<<q.front()<<"\n";
        } else if(cmd=="pop") {
            cout<<q.pop()<<"\n";
        } else if(cmd=="back") {
            cout<<q.back()<<"\n";
        } else if(cmd=="size") {
            cout<<q.size()<<"\n";
        } else if(cmd=="empty") {
            cout<<q.is_empty()<<"\n";
        }
    }
}
