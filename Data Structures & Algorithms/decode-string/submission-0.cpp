class Solution {
public:
    string decodeString(string s) {
         vector<string> str;
        vector<int> cnt;
        int val = 0;
        string curr = "";
        for(auto c : s){

            if(isdigit(c)){
                val = val * 10 + (c - '0');
            }
            else if(c == '['){
                str.push_back(curr);
                cnt.push_back(val);
                curr = "";
                val = 0;
            }
            else if(c == ']'){
                 int count = cnt.back();
                 string temp = curr;
                 curr = str.back();
                 for(int i=0;i<count;i++) curr += temp;
                 str.pop_back();
                 cnt.pop_back();
            }
            else curr += c;
        }
        return curr;
    }
};