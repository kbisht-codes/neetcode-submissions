class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mapping = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };
        stack<char> st;
        for(char c: s) {
            if(c == '[' || c == '{' || c == '(')
                st.push(c);
            else{
                if(st.empty())
                    return false;
                if(st.top() == mapping[c])
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
