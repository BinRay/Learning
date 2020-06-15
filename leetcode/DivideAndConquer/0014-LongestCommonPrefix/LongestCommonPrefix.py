# 此处用分支法只为练习，并非最优解
class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        return self.lcp(strs, 0, len(strs)-1)

    def lcp( self, strs, i, j ):
        if i == j :
            return strs[i]
        mid = ( i + j ) // 2
        left_lcp = self.lcp( strs, i, mid )
        right_lcp = self.lcp( strs, mid+1, j)

        return self.common_prefix( left_lcp, right_lcp ) 
    
    def common_prefix( self, l_lcp, r_lcp ):
        if not l_lcp or not r_lcp:
            return ""
        for i in range(min(len(l_lcp), len(r_lcp))):
            if l_lcp[i] != r_lcp[i]:
                if i == 0:
                    return ""
                else:
                    return l_lcp[:i]
        # 一个串是另一个串的子集，返回较短的
        return l_lcp if len(l_lcp) < len(r_lcp) else r_lcp

        
    
s = Solution()
strs = [ "ab", "abc", "abd" ]
print( s.longestCommonPrefix(strs) )