//
// Created by 이경민 on 2022/08/17.
//
#include<iostream>
#include<vector>
using namespace std;

int n,x;
string cmd;

class Stack {
private:
    vector<int> arr;
public:
    bool empty() { return arr.empty(); }
    void push(int x) {
        arr.push_back(x);
    }
    int pop() {
        if(empty()) return -1;
        int ret = arr.back();
        arr.pop_back();
        return ret;
    }
    int size() { return arr.size(); }
    int top() {
        if(empty()) return -1;
        int ret = arr.back();
        return ret;
    }
};

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    Stack st;
    while(n--){
        cin>>cmd;
        if(cmd=="push"){
            cin>>x;
            st.push(x);
            continue;
        }
        else if(cmd=="pop"){ cout<<st.pop(); }
        else if(cmd=="size"){ cout<<st.size();}
        else if(cmd=="empty"){ cout<<st.empty(); }
        else if(cmd=="top"){ cout<<st.top(); }
        cout<<"\n";
    }
}
