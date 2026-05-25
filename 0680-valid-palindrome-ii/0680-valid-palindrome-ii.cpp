class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.length();
        int low = 0 ; 
        int high = n-1 ;
        int count = 0 ;
        while(low < high)
        {
            if(s[low] == s[high])
            {
                low++;
                high--;
            }
            else
            {
                int i = low + 1;
                int j = high;
                while(i < j)
                {
                    if(s[i] != s[j])
                        break;

                    i++;
                    j--;
                }
                if(i >= j)
                    return true;
                i = low;
                j = high - 1;
                while(i < j)
                {
                    if(s[i] != s[j])
                        break;
                    i++;
                    j--;
                }
                if(i >= j) return true;
                   

                return false;
            }
        }
        return true;
    }
};