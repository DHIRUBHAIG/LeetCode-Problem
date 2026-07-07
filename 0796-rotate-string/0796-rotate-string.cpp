class Solution {
public:
    bool rotateString(string s, string goal) {
        string temp=s+s;
        if(s.length()!=goal.length()){
            return false;
        }

        if(temp.find(goal)!=string::npos){//Checks whether the substring goal exists anywhere in the string.
            return true;
        }

        return false;
    }
};