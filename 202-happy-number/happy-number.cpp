class Solution {
public:
int numsDigitSum(int n) {
    int sum = 0;
    while(n > 0) {
        int digit = n%10;
        sum += pow(digit,2);
        n /= 10;
    }
    return sum;
}
    bool isHappy(int n) {
        int fast = n, slow = n;
        while (fast != 1) {
            slow = numsDigitSum(slow);
            fast = numsDigitSum(fast);
            fast = numsDigitSum(fast);

            if(fast == slow && fast !=1) return false;
        }

        return true;
    }
};