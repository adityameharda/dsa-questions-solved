class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }
            if(st.empty())return false;
            if(st.top() == '(' && ch == ')' || st.top() == '[' && ch == ']' ||st.top() == '{' && ch == '}')st.pop();
            else if(ch == '}' || ch == ']' || ch == ')')return false;

        }
        return st.size() == 0;
    }
};