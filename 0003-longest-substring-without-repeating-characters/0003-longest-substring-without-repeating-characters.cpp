class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // slidind window with map;
        unordered_map<char,int>mpp;
        int maxlen=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            
            if( mpp.find(s[j])!=mpp.end() && mpp[s[j]]>=i){
                i=mpp[s[j]]+1;  
            }
            mpp[s[j]]=j;
            int len=j-i+1;
            maxlen=max(len,maxlen);
        }
        return maxlen;
    }
};


