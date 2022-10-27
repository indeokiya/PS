class Solution {

public:
    string longestPalindrome(string s) {
        int len = s.length();
        string ans;
        int max = 0;
       
        for (int i=0; i<len; i++) {
            int tmp = findLength(s, i-1, i+1);
            if (tmp>max) {
                max = tmp;
                ans = s.substr(i-tmp/2, tmp);
            }
        }
        
        for (int i=1; i<len; i++) {
            if (s[i]!=s[i-1]) continue;
            int tmp = findLength(s, i-2, i+1);
            if (tmp>max) {
                max = tmp;
                ans = s.substr(i-tmp/2, tmp);
            }
        }
        
        return ans;
    }
    
private:
    int findLength(string s, int left, int right) {
        int len = s.length();
        
        while (left>=0 && right<len && s[left]==s[right]) {
            left--;
            right++;
        }
        
        return right-left-1;
    }
};