class Solution {
public:
int digitproduct(int n){
    int product=1;
    while(n>0){
        int rem=n%10;
     product*=rem;
    n=n/10;

    }
    return product;
   
}

    int smallestNumber(int n, int t) {
        while((digitproduct(n)%t)!=0){
            n++;
        }
        return n;
    }
};