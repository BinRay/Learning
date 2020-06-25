// 旋转矩阵
// (4ms, 55.87%) (7MB, 100%)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int N = matrix.size();
        // 1. 第一层循环代表从外层向里层走
        // 2. 第二层循环代表对其中每个相对应的元素操作旋转
        // 3. 重点在于找到上、右、下、左各个节点的位置
        
        for ( int layer = 0 ; layer < N/2; layer++ ){
            int border = N-1-layer;
            for ( int i = 0; layer + i < border; i++ ){
                int index = layer + i;
                
                int *top = &matrix[layer][index];
                int *right = &matrix[index][border];
                int *bottom = &matrix[border][border-i];
                int *left = &matrix[border-i][layer];
                
                int temp = *top;
                *top = *left;            
                *left = *bottom;    
                *bottom = *right;          
                *right = temp;
            }
            
        }
    }
};