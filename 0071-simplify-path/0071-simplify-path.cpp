// ""   → ignore
// "."  → ignore
// ".." → pop
// other → push

class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        string token="";
        stringstream ss(path);
        while(getline(ss,token,'/')){
            if(token==""||token==".") continue;
            else if(token==".." ){
                if( !st.empty())
                st.pop();
            } 
            else{
                st.push(token);
            }
        }
        if(st.empty()) return "/";
        string result="";
        while(!st.empty()){
            result="/"+st.top()+result;
            st.pop();
        }
        return result;
    }
};