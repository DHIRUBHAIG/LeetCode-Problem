class Solution {
public:
    int dayOfYear(string date) {
        vector<int>temp={0,31,28,31,30,31,30,31,31,30,31,30,31};
         int year=stoi(date.substr(0,4));
         if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)){
            temp[2]=29;
         }
        
        int month=stoi(date.substr(5,2));
        int day=stoi(date.substr(8,2));
        int sum=0;
        for(int i=0;i<month;i++){
            sum+=temp[i];
        }
        sum+=day;
        return sum;       
    }
}; 