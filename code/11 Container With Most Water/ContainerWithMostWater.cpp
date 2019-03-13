#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    
    int maxArea(vector<int>& height) {
        int v_len = height.size();
        int i = 0;
        int j = v_len - 1;
        int max_volume = 0;
        while (i < j)
        {
            int h = min(height[i], height[j]);
            int volume = (j - i) * h;
            if (volume > max_volume) max_volume = volume;
            while(height[i] <= h && i < j) {i ++;}
            while(height[j] <= h && i < j) {j -- ;}
        }
        return max_volume;
    }
};

int main()
{
    int arr[] = {1,8,6,2,5,4,8,3,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> test_v(arr, arr + n);
    
    Solution sol = Solution();
    int max_volume = sol.maxArea(test_v);
    cout << max_volume << endl;
}

