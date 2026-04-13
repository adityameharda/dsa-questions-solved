#include<stack>
class Solution {
public:
    bool isValid(string s) {
        stack<char>st ;
        char top ; 
        for( char ch : s)
        {
            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch) ;
            }
            if(st.empty())
                return false ;
            top = st.top() ;
            if(ch == ')' && st.top() == '(' || ch == '}' && st.top() == '{' || ch == ']' && st.top() == '[' )
            {
                st.pop() ;
            }
            else if(ch == ']' || ch == '}' || ch == ')')
                return false ;
        }
        if(st.empty())
            return true ;
        else
        return false;
    }
};