#include <iostream>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int s_length = s.length();
        if (s_length == 0) return "";
        string result;
        int i = 0;
        int distance_sum = numRows * 2 - 2;
        if (distance_sum == 0) return s;
        for (int row = 0; row < numRows; row ++)
        {
            int distance = row * 2;
            cout << "------------row #: " << row << "-----------" << endl;
            int location = row;
            int i = 0;
            while(location < s_length)
            {
                cout << "Found valid index: " << location << ". ";
                result += s[location];
                distance = distance_sum - distance;
                if (distance == 0) distance = distance_sum;
                cout << "Add distance: " << distance << endl;
                location += distance;
                
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string str = sol.convert("0123456789", 4);
    cout << "The result is " << str << endl;
    return 0;
}



