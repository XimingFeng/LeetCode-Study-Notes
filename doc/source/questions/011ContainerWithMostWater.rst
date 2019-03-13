11 Container With Most Water
==============================

######################
Brute Force
######################

When we look at the problem, I would think that this is a sliding window problem. The first idea of course is the brutal force way. Have a start index i and end index j. Iterating i and j like a sliding window on top of the vector. Everytime you will get the area value. The height of the container is going to be the min between height[i] and height[j]. The width is the j - i. The time complexity would be :math:`O(n^2)` and the storage complexity is O(1) because you will only need to store the maximum value in a variable.

.. code-block:: c
   :linenos:

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

