#include <iostream>

class Solution{
public:
    int climbStairs(int n);
};

int Solution::climbStairs(int n){
        if (n == 1) {
            return 1;
        }
        int first = 1;
        int second = 2;
        for (int i = 3; i <= n; i++){
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
}

int main(void)
{
    Solution solution;
    std::cout << solution.climbStairs(4) << std::endl;
    return 0;
}
