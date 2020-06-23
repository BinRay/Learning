class Cmp {
public:
    bool operator() ( vector<int> i, vector<int> j ) {
        return i[0] == j[0] ? i[1] < j[1] : i[0] > j[0];
    }
};

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        Cmp cmp;
        sort ( people.begin(), people.end(), cmp );

        list<vector<int> > tmp;
        // 循环插入
        for(int i = 0; i < people.size(); ++i){
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        // 重建vector返回
        return vector<vector<int>>(tmp.begin(), tmp.end());

    }
};

