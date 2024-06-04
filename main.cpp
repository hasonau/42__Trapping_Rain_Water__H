#include <iostream>
#include <vector>
using namespace  std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==1 || height.size()==2){
            return 0;
        }
        int L=0;
        int temp=0;
        int result=0;
        int R=L+1;
        int save=0;
        while(R!=height.size()){


            if(height[L]>height[R]){
                temp+=height[L]-height[R];
                R++;
                if(temp!=0 && R==height.size()){
                    temp=0;
                    save=L;
                    L=height.size()-1;
                    R=L-1;
                    while (R!=(save-1)){
//                        cout<<"came in inside while loop"<<endl;
                        if(height[L]>height[R]) {
                            temp += height[L] - height[R];
                            R--;
                        }
                        else if(height[R]>=height[L]) {
                            result += temp;
                            L = R;
                            R -= 1;
                            temp = 0;
                        }
                    }
                    return result;
                }
            }
            else if(height[R]>=height[L]){
                result+=temp;
                L=R;
                R+=1;
                temp=0;
                save=L;
            }
        }
        return result;
    }
};
//////////////////////////////////GPT COMMENTED  code with VARIABLES NAMES CHANGED////////////////////////


//class Solution {
//public:
//    int trap(vector<int>& height) {
//        // Early return if the input height array has less than 3 elements
//        if(height.size() == 1 || height.size() == 2) {
//            return 0;
//        }
//
//        // Initialize variables
//        int left = 0; // Left pointer
//        int tempWater = 0; // Temporary water storage between current left and right
//        int totalWater = 0; // Total trapped water
//        int right = left + 1; // Right pointer
//        int lastPeak = 0; // Last peak index
//
//        while(right != height.size()) {
//            if(height[left] > height[right]) {
//                // If left bar is higher than right bar, calculate the potential water trapped
//                tempWater += height[left] - height[right];
//                right++;
//
//                // If right pointer reaches the end and there is temporary water stored
//                if(tempWater != 0 && right == height.size()) {
//                    tempWater = 0; // Reset temporary water
//                    lastPeak = left; // Save the last peak position
//                    left = height.size() - 1; // Move left pointer to the end
//                    right = left - 1; // Move right pointer to the one before the end
//
//                    // Traverse from the end back to the last peak to recalculate trapped water
//                    while (right != (lastPeak - 1)) {
//                        if(height[left] > height[right]) {
//                            tempWater += height[left] - height[right];
//                            right--;
//                        } else if(height[right] >= height[left]) {
//                            totalWater += tempWater;
//                            left = right;
//                            right -= 1;
//                            tempWater = 0;
//                        }
//                    }
//                    return totalWater;
//                }
//            } else if(height[right] >= height[left]) {
//                // If right bar is higher or equal to left bar, add the temporary water to total water
//                totalWater += tempWater;
//                left = right;
//                right += 1;
//                tempWater = 0;
//                lastPeak = left;
//            }
//        }
//        return totalWater;
//    }
//};


int main() {
    Solution solution;

    std::vector<int> height1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "Test 1: " << solution.trap(height1) << std::endl;  // Expected output: 6

    std::vector<int> height2 = {0,2,0};
    std::cout << "Test 2: " << solution.trap(height2) << std::endl;  // Expected output: 9

    std::vector<int> height3 = {4,2,0,3,2,5};
    std::cout << "Test 2: " << solution.trap(height3) << std::endl;  // Expected output:

    std::vector<int> height4 = {1,2,3,4,5,6,7,8,9,10};
    std::cout << "Test 2: " << solution.trap(height4) << std::endl;  // Expected output:

    std::vector<int> height7 = {10,9,8,7,6,5,4,3,2,1};
    std::cout << "Test 2: " << solution.trap(height7) << std::endl;  // Expected output:

    std::vector<int> height5 = {1,0,2,0,3,0,4,0,5,0};
    std::cout << "Test 2: " << solution.trap(height5) << std::endl;  // Expected output:

    std::vector<int> height6 = {3,1,4,2,0,5,1,2,3,4};
    std::cout << "Test 2: " << solution.trap(height6) << std::endl;  // Expected output:

    std::vector<int> height8 = {3,2,1,2,3,4,5,4,3,2};
    std::cout << "Test 2: " << solution.trap(height8) << std::endl;  // Expected output:

    std::vector<int> height9 = {5,4,1,2};
    std::cout << "Test 2: " << solution.trap(height9) << std::endl;  // Expected output:

    return 0;
}