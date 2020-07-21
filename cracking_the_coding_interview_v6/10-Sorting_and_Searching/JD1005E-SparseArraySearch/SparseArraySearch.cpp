class Solution {
public:
    int findString(vector<string>& words, string s) {
        int first = 0;
        int last = words.size() - 1;

        while ( first <= last ){
            int mid = ( first + last ) / 2;
            if ( words[mid] == "" ){
                int midl = mid - 1;
                int midr = mid + 1;
                while ( midl >=first && words[midl] == "" ){
                    midl--;
                }
                if ( midl >= first ){
                    if ( words[midl] == s ){
                        return midl;
                    } else if ( words[midl] > s){
                        last = midl - 1;
                        continue;
                    }
                }

                while ( midr <= last && words[midr] == "" ){
                    midr++;
                }
                if ( midr <= last ){
                    if ( words[midr] == s ){
                        return midr;
                    } else if ( words[midr] < s ){
                        first = midr + 1;
                        continue;
                    }
                }

                return -1;

            }else {
                if ( words[mid] == s ){
                    return mid;
                } else {
                    if ( words[mid] > s ){
                        last = mid - 1;
                    } else {
                        first = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};
