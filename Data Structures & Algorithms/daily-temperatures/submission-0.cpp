class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        stack<pair<int,int>> st;
         int  n = temps.size();
         vector<int>res(n,0);
         for(int i=0;i<n;i++){
             
              while(!st.empty() && st.top().first < temps[i]){
                    res[st.top().second] = i - st.top().second;
                    st.pop();
              }
              st.push({temps[i],i});
         }
         return res;
    }
};
