// Why two scans?

// Because one direction cannot handle both situations.

// Left → Right handles cases where ) becomes greater than (.
// Right → Left handles cases where ( remains greater than ).

class Solution {
public:
    int longestValidParentheses(string s) {
       int left=0;
       int right=0;
       int maxlen=0;
       //from left to right;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            left++;
        }
        else right++;
        if(left==right){
            maxlen=max(maxlen,(2*left));
        }
        if(right>left){
            left=0;
            right=0;
        }
    } 
    left=0;
    right=0;
    
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='('){
            left++;
        }
        else right++;
        if(left==right){
            maxlen=max(maxlen,(2*left));
        }
        if(right<left){
            left=0;
            right=0;
        }
    }
    return maxlen;
    
    }
};