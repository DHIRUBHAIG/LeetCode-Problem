class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        int l=s[0]-'0';
        int sl=-1;
        for(int i=1;i<s.size();i++){
            int digit=s[i]-'0';
            if(digit>=l){
                sl=l;
                l=digit;
            }
            else if(sl<digit){
                sl=digit;
            }

        }
        int result= l*sl;
        return result; 
    }
};