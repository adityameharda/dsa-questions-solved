class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        int n = s.length();
        queue<char>q;
        string res = "";
        for(int i = 0 ; i < n ; i++){
            if(s[i] == ')'){
                while(st.top() != '('){
                    q.push(st.top());
                    st.pop();
                }
                st.pop();
                while(!q.empty()){
                    st.push(q.front());
                    q.pop();
                }
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
         res +=st.top();
         st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};