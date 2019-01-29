3. Longest Substring Without Repeating Characters
====================================================

.. _Question3:

#################################
Sliding window with hash table
#################################
When I see substring problems what I would usually try is called sliding window. 
It uses two indexes representing the start and the end of a subtring. When they iterate through the target string, it is like a window sliding through the target string and the string inside of the window is what we are interested in.The contraint of the indexes are starting index should not be greater than of ending index. 

Let's assume that the starting index is j and ending index is i. The goal is to find the longest substring with unique characters. So, if we can not find any character in the window the same as the character indexed by i, we should expand the window include the character indexed by i. What if we find a character in the window the same as the character indexed by i, that means we have find the longest substring with current starting index j. If it is the longest substring we have ever seen, we update the result. After the comparison, we need to move j to duplicated character and go one step further, because if j is on or before the character, the subtring would be two same characters and it would be invalide. 

In order to make the look up in substring fast, we can use a hash table to store the characters as keys and their locations or index as values. With hashtable, the lookup would be decreased to O(1) a constant.

Here is the code:

.. code-block:: c
   :linenos:

   class Solution {
     public:
         int lengthOfLongestSubstring(string s) {
             
             int i = 0, j = 0, max_length = 0;
             unordered_map<char, int> prev_char_map;
             while (i < s.length())
             {
                 
                 if (prev_char_map.find(s[i]) != prev_char_map.end())
                 {
                     j = max(prev_char_map[s[i]] + 1, j) ;
                 }
                 max_length = max(max_length, i - j + 1);
                 prev_char_map[s[i]] = i;
                 i ++;
             }
             return max_length;
         }
     };


Here is what I found during implementing the code. We don't need to delete the entry in the table hash table so that it always reflect the current substring, if we find an entry in the hash table, that means we have seen this character but if the value of the character in less than j, that means that character is not in the current substring anymore so that we can just ignore it and updated its value to the new index, which is i. 

With that algorithm implemented, i would iterate through the string s one time and j, worst case senario would also iterate through the string s one time. The worst case is 
'aaaaaaaaaaaaa'. So the time complexity would be O(n).
As for the space complexity, we need a hash table to store the character we have seen so far so that it wounl be O(min(len(s), m). m is the length of all possible characters.



#################################
Sliding window with array
#################################
If we can have the assumption on the characters such as that they are ASCII characters, we don't need a hash table, instead we just need to use array with the size of 256.






