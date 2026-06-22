class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
         stack<int>st;
        for(int i=0;i<asteroids.size();i++){
             
             if(asteroids[i] < 0){
                 while(!st.empty() && st.top() < abs(asteroids[i]) && st.top() > 0) st.pop();

                 if(st.empty()) st.push(asteroids[i]);

                 else if(st.top() == abs(asteroids[i])) st.pop();
                 else if(st.top() < 0) st.push(asteroids[i]);
             }
             else{
                 st.push(asteroids[i]);
             }
        }
        vector<int>res(st.size());
        int ind = st.size()-1;
        while(!st.empty()) {
            res[ind--] = st.top();
            st.pop();
        }
        return res;
    }
};