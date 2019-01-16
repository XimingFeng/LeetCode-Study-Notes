#include <iostream>
#include <string>
#include <unordered_map>
#include<algorithm>

using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, max_length = 0;
        unordered_map<char, int> prev_char_map;

        while (i < s.length())
        {
            cout << "*********** i = " << i << "************" << endl;
            if (prev_char_map.find(s[i]) != prev_char_map.end())
            {
                j = max(prev_char_map[s[i]] + 1, j) ;
                cout << "Found duplicated character, move j to " << j << endl;
            }
            max_length = max(max_length, i - j + 1);
            prev_char_map[s[i]] = i;
            i ++;
        }
        return max_length;
    }
};

int main()
{
    Solution sol;
    int max_length = sol.lengthOfLongestSubstring("pwwkew");
    cout << "The longest substring is: "  << max_length << endl;
}