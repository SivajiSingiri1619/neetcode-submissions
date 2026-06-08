class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>> res;

        map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());

            mp[temp].push_back(strs[i]);
        }
        for(auto &[key,vec]:mp){
            vector<string>temp;
            for(int i=0;i<vec.size();i++) temp.push_back(vec[i]);
            res.push_back(temp);
        }
        return res;
    }
};
