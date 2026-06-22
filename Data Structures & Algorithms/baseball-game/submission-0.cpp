class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        
        for(auto s:operations){
             
              if(!st.empty() && s == "C") st.pop();

              else if(s == "D") {
                 if(!st.empty()) st.push(st.top() * 2);
              }
              else if(s == "+"){
                  if(st.size() >= 2){
                     int prev = st.top();
                     st.pop();
                     int tot = prev + st.top();
                     st.push(prev);
                     st.push(tot);
                  }
              }
              else st.push(stoi(s));
        }

        int res = 0;
        while(!st.empty()){
             res += st.top();
             st.pop();
        }
        return res;
    }
};