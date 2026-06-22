class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;

        for(auto s: tokens){

            if(s == "+" && st.size() >= 2){
               
                    int val = st.top();
                    st.pop();
                    val += st.top();
                    st.pop();
                    st.push(val);
            }
            else if(s == "-" && st.size() >= 2){
                 int val = st.top();
                    st.pop();
                    val = st.top() - val;
                    st.pop();
                    st.push(val);
            }
            else if(s == "*" && st.size() >= 2){
                 int val = st.top();
                    st.pop();
                    val *= st.top();
                    st.pop();
                    st.push(val);
            }
            else if(s == "/" && st.size() >= 2){
                 int val = st.top();
                    st.pop();
                   
                    val = st.top() / val;
                    
                    st.pop();
                    st.push(val);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};
