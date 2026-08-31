 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int i=0;
         int j=0;
         int maxlen=0;
         unordered_map<char,int>mpp;
         for(int j=0;j<s.size();j++){
            if(mpp.find(s[j])!=mpp.end() && i<=mpp[s[j]]){
                i=mpp[s[j]]+1;

            }
            mpp[s[j]]=j;
            maxlen=max(maxlen,j-i+1);
         }
         return maxlen;
    }
};