#include <string>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

pair<int,int> in_fee_amount[10000];
pair<int,int> out_fee_amount[10000];
int basicTime, unitTime, basicFee, unitFee;

int calculateFee(int time_amount) {
    if(time_amount<=basicTime) return basicFee;
    else {
        int amountFee = basicFee;
        time_amount -= basicTime;
        amountFee += (ceil((double)((double)time_amount/(double)unitTime)))*unitFee;
        return amountFee;
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    basicTime = fees[0]; unitTime = fees[2];
    basicFee = fees[1]; unitFee = fees[3];
    int carNumber = 0;
    int amount = 0;
    for(auto i:records) {
        carNumber = stoi(i.substr(6,4));
        
        amount = stoi(i.substr(0,2)) * 60;
        amount += stoi(i.substr(3,2));
        
        if(i[11]=='I') { //in
            ++in_fee_amount[carNumber].first;
            in_fee_amount[carNumber].second += amount;
        }
        else { //out
            ++out_fee_amount[carNumber].first;
            out_fee_amount[carNumber].second += amount;
        }
    }
    
    int time;
    for(int i=0; i<10000; i++) {
        if(in_fee_amount[i].first == 0) continue;
        
        if(in_fee_amount[i].first>out_fee_amount[i].first) {
            out_fee_amount[i].second += 1439;
        }
        time = out_fee_amount[i].second - in_fee_amount[i].second;
        answer.push_back(calculateFee(time));
    }
    
    return answer;
}
