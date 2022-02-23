#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>


using namespace std;

bool isHappy(int number){
    unordered_map<int,bool> set_map;
    vector<int> holdDigits;
    int size = 0;
    while(1) {
        holdDigits.clear();
        while (number != 0) {
            int lastDigit = number % 10;
            holdDigits.push_back(lastDigit * lastDigit);
            number = number / 10;
            size++;
        }
        number = accumulate(holdDigits.begin(), holdDigits.end(), 0);
        if (number==1){
            return true;
        } else if (set_map.find(number) == set_map.end()) {
            set_map.insert(make_pair(number, true));
        } else {
            return false;
        }
    }
}


int main() {
     cout << isHappy(116)<<endl;
    return 0;
}

