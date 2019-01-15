#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string prev_substring = "";
        int i = 0, j = 0, max_length = 0;
        while (i < s.length())
        {
            cout << "*********** i = " << i << "************" << endl;
            
            if(prev_substring.find(s[i]) != string::npos)
            {
                while (prev_substring.find(s[i]) != string::npos)
                {
                    j ++;
                    prev_substring = s.substr(j, i - j);
                }
                cout << "shift j to " << j << endl;
            }
            else
            {
                if (max_length < prev_substring.length() + 1)
                {
                    max_length = prev_substring.length() + 1;
                }
            }
            prev_substring = s.substr(j, i - j + 1);
            cout << "new substring: " << prev_substring << endl;
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
