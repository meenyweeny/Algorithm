#include<iostream>
using namespace std;

int arr[10];

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>arr[0];
    int gap = abs(100-arr[0]);
    int answer = arr[0];
    for(int i=1; i<10; i++) {
        cin>>arr[i];
        arr[i] += arr[i-1];
        if(abs(100-arr[i])<=gap) {
            gap = abs(100-arr[i]);
            answer = arr[i];
        }
    }
    cout<<answer;
}
