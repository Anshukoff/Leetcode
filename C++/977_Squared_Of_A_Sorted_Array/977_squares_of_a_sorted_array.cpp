#include <iostream>
#include <vector>
#include <algorithm>

class Solution{
public:
    std::vector<int> sortedSquares(std::vector<int>& A);
};

//O(nlog(n)) solution
//std::vector<int>Solution::sortedSquares(std::vector<int>& A){
//    std::vector<int> resultVec;
//    for(auto a : A){
//        resultVec.push_back(a*a);
//    }
//    std::sort(resultVec.begin(), resultVec.end());
//    return resultVec;
//}

//O(n) solution
std::vector<int>Solution::sortedSquares(std::vector<int>& A){
    std::vector<int> hash(10001,0);
    for(auto a : A){
        ++hash[std::abs(a)];
    }
    std::vector<int> resVec;
    for(int i = 0; i <=10000; ++i){
        while(hash[i] != 0){
            resVec.push_back(i*i);
            --hash[i];
        }
    }
    return resVec;
}


int main(void){
    std::vector<int> vec = {-7, -3, 2, 3, 11};
    Solution solution;
    std::vector<int> resultVec = solution.sortedSquares(vec);
    for(auto a : resultVec){
        std::cout << a << " ";
    }
    std::cout << std::endl;
    return 0;
}

