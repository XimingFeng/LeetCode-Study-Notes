#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int maxArea(vector<int>& height) {
        int v_len = height.size();
        int max_volume = 0;
        for (int i = 0; i < v_len; i++)
        {
            for (int j = 0; j < i; j ++)
            {
                // cout << "========= j: " << j <<  ", i: " << i << "============" <<endl;
                int volume = get_volume(height, j, i);
                // cout << "volume: " << volume << endl;
                if (volume > max_volume) max_volume = volume;
            }
        }
        return max_volume;
    }
    
    int get_volume(vector<int>& height, int start_indx, int end_indx)
    {
        int distance = end_indx - start_indx;
        int start_height = height[start_indx];
        int end_height = height[end_indx];
        // cout << "Start height: " << start_height << "end height" << end_height << endl;
        return ((start_height >= end_height)?end_height:start_height) * distance;
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
