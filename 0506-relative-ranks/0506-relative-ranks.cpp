class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //max heap;
        priority_queue<int>pq; 
        for(int i=0;i<score.size();i++){
            pq.push(score[i]);
        }
        vector<string>ans;
        vector<int>ans1;
        //ans.push_back(-1);
       while(!pq.empty()) {
    ans1.push_back(pq.top());
    pq.pop();
}
        for(int i=0;i<score.size();i++){
            for(int j=0;j<score.size();j++){
                if(score[i]==ans1[j]){
                    if(j==0){
                        ans.push_back("Gold Medal");
                    }
                    else if(j==1){
                        ans.push_back("Silver Medal");
                    }
                    else if(j==2){
                        ans.push_back("Bronze Medal");
                    }
                    else{
                        ans.push_back(to_string(j+1));
                    }
                }
            }
        
        }
        return ans;
    }
};