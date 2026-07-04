class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()==1) return s;
        string lps="";
        //odd lenght palindrome;
        for(int i=1;i<s.size();i++){
            
            int low=i;
            int high=i;
            while(s[low]==s[high]){
                low--;
                high++;
                if(low==-1 || high==s.size()) break;

            }
            string palindrome=s.substr(low+1,high-low-1);
            if(palindrome.size()>lps.size()){
                lps=palindrome;
            }
        }
        // even lenght palindrome;
        for(int i=1;i<s.size();i++){
            
            int low=i-1;
            int high=i;
            while(s[low]==s[high]){
                low--;
                high++;
                if(low==-1 || high==s.size()) break;

            }
            string palindrome=s.substr(low+1,high-low-1);
            if(palindrome.size()>lps.size()){
                lps=palindrome;
            }
        }
        return lps;
    }
};