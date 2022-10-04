//
// Created by 이경민 on 2022/08/17.
//
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int n,x;
stack<int> st;
queue<int> q;
int idx=1;
string answer;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;
    for(int i=0; i<n; i++){
        cin >> x;
        q.push(x);
    }

    st.push(idx);
    answer+="+\n";
    ++idx;

    while(idx<=n){
        if(!st.empty()){
            if(st.top() == q.front()){
                answer+="-\n";
                q.pop();
                st.pop();
                continue;
            }
        }
        st.push(idx);
        answer+="+\n";
        ++idx;
    }

    while(!q.empty()){
        if(st.top() == q.front()){
            answer+="-\n";
            q.pop();
            st.pop();
        }
        else{
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<answer;
}
