class Solution {
public:
    int countMonobit(int n) {
        int count=1;
        int num=1;
        while(num <= n){
            num = num*2+1;
            count++;
        }
        return count;
    }
};