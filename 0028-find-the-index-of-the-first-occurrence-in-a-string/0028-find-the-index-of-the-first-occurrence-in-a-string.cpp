class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
        int j=0;
        int startindex=0;
        while(i<haystack.size()){
            if(haystack[i]==needle[j]){
                i++;
                j++;
                if(j==needle.size()) return startindex;
            }
            else{
                startindex++;
                i = startindex;
                j=0;
                
            }
            
        }
        return -1;

    }
};