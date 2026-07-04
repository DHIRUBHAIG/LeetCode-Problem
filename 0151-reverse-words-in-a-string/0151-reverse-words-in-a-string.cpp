class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        reverse(s.begin(),s.end());

        string sub= "";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') sub+=s[i];
            else{
               if(!sub.empty()){
                 reverse(sub.begin(),sub.end());
                 if(!ans.empty()) ans+=" ";
                ans+=sub;
                

                sub="";
               }
            }
        }
        if(!sub.empty()){
            reverse(sub.begin(),sub.end());
        if(!ans.empty()) ans+=" ";
        ans+=sub;
        }
        return ans;
    }
};