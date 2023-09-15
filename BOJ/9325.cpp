#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t,n,s,p,q;
    cin>>t;
    while(t--) {
        cin>>s>>n;
        while(n--) {
            cin>>q>>p;
            s += (q*p);
        }
        cout<<s<<'\n';
    }
}
