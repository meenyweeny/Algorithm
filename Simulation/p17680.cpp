#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

string convertLower(string city) {
    string lowerCity = "";
    for(auto i:city) lowerCity += tolower(i);
    return lowerCity;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    deque<string> cache;
    if(cacheSize == 0) return cities.size() * 5;
    
    string i = "";
    int idx = 0;
    bool hit = false;
    
    for(auto k:cities){
        i = convertLower(k);
        idx = 0;
        hit = false;
        for(idx=0; idx<cache.size(); idx++) {
            if(cache[idx]==i) {
                hit = true;
                break;
            }
        }
        if(!hit){ //miss
            answer+=5;
            cache.push_back(i);
            if(cache.size()>cacheSize) cache.pop_front();
        }
        else { //hit
            ++answer;
            cache.push_back(i);
            cache.erase(cache.begin() + idx);
        }
    }
    return answer;
}
