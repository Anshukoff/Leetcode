#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
public:
    int heightChecker(std::vector<int>& heights);
};

int Solution::heightChecker(std::vector<int>& heights){
    unsigned long long size = heights.size();
    std::vector<int> tempVec(heights);
    std::sort(tempVec.begin(), tempVec.end());
    int wrongPos = 0;
    for(unsigned long long i = 0; i < size; ++i){
        if(tempVec[i] != heights[i]){
            ++wrongPos;
        }
    }
    return wrongPos;
}


int main(void){
    std::vector<int> input = {1,1,4,2,1,3};
    Solution solution;
    std::cout << solution.heightChecker(input) << std::endl;
    return 0;
}
