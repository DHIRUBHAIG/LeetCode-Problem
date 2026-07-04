class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<int,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        int count=mpp[s[0]];
        for(auto it:mpp){
            if(it.second!=count){
                return false;
            }
        }
        return true;
    }
};