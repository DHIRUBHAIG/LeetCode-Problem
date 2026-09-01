// ""   → ignore
// "."  → ignore
// ".." → pop
// other → push

class Solution {
public:
    string simplifyPath(string path) {
        // stack<string>st;
        vector<string>st;
        string token="";
        stringstream ss(path);
        while(getline(ss,token,'/')){
            if(token==""||token==".") continue;
            else if(token==".." ){
                if( !st.empty())
                st.pop_back();
            } 
            else{
                st.push_back(token);
            }
        }
        if(st.empty()) return "/";
        string result="";
        int n=st.size();
        while(n--){
            result="/"+st.back()+result;
            st.pop_back();
        }
        return result;
    }
};