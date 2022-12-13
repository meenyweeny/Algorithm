#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

int arr[100001];
int n,s,sum;
int front, back;
int answer = INT_MAX;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>s;
    cin>>arr[0];
    for(int i=1; i<n; i++) {
        cin>>back;
        arr[i] = arr[i-1] + back;
    }
    front=back=0;
    while(front<=n-1 && back<=n-1) {
        if(front>0) {
            sum = arr[back] - arr[front-1];
        } else {
            sum = arr[back];
        }

        if(sum>=s) {
            answer = min(answer, back-front+1);
            ++front;
        } else {
            ++back;
        }
    }

    if(answer != INT_MAX) {
        cout<<answer;
    } else {
        cout<<0;
    }
}
