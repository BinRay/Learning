class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto it = nums.begin();
        int single = 0;
        while ( it != nums.end() ){
            single ^= *it;
            it++;
        }
        return single;
    }
};