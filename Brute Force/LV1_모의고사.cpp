//
//  LV1_모의고사.cpp
//  BOJ
//
//  Created by 이경민 on 2022/02/19.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<pair<int,int>> std;
    int score[3] = {0,0,0};
    vector<int> s1 = {1,2,3,4,5};
    vector<int> s2 = {2,1,2,3,2,4,2,5};
    vector<int> s3 = {3,3,1,1,2,2,4,4,5,5};
    
    for (int i=0; i<answers.size(); i++) {
        if(answers[i] == s1[i%5])
            ++score[0];
        if(answers[i] == s2[i%8])
            ++score[1];
        if(answers[i] == s3[i%10])
            ++score[2];
    }
    
    std.push_back({score[0],1});
    std.push_back({score[1],2});
    std.push_back({score[2],3});
    
    sort(std.begin(), std.end());
    reverse(std.begin(), std.end());
    
    if(std[0].first == 0){
    }
    else {
    answer.push_back(std[0].second);
    
    for(int i=1; i<3; i++) {
        if(std[i].first==std[i-1].first){
            answer.push_back(std[i].second);
        }
        else {
            break;
        }
    }
        
    sort(answer.begin(), answer.end());
    }
    return answer;
}
