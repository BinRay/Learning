class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int cur = m + n -1;
        m--;
        n--;
        while ( m >= 0 && n >= 0 ){
            if ( A[m] > B[n] ){
                A[cur] = A[m];
                cur--;
                m--;
            } else {
                A[cur] = B[n];
                cur--;
                n--;
            }
        }
        
        while ( n >= 0 ){
            A[cur] = B[n];
            cur--;
            n--;
        }
    }
};

