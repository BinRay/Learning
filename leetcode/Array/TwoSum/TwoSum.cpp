//
// Created by lbinr on 2020/5/11.
//
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> hash;

        for (int i = 0; i < nums.size(); i++){
            int another_num = target - nums[i];
            if (hash.find(another_num) != hash.end()){
                result.push_back(hash[another_num]);
                result.push_back(i);
                return result;
            }
            else{
                hash[nums[i]] = i;
            }
        }

        return result;
    }
};

int main(int argc, char** argv){
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);

    int target = 13;

    Solution s;
    vector<int> result = s.twoSum(nums, target);

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }

}