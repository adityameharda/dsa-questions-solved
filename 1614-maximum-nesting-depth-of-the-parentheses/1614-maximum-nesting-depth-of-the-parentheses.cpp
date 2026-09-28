class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();
        int crdep = 0 ; 
        int mxi = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                crdep++;
            }
            if(s[i] == ')'){
                crdep--;
            }
            mxi = max(mxi,crdep);

        }
            return mxi;
    }
};