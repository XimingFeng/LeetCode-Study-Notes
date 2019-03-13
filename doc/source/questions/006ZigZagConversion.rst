6. ZigZag Conversion
========================

Let's write this example down. If we use the index of the string s instead of the characters. We can get the following example

+---+---+---+---+----+----+----+----+----+-----+
| 0 |   |   | 6 |    |    | 12 |    |    | ... |
+---+---+---+---+----+----+----+----+----+-----+
| 1 |   | 5 | 7 |    | 11 | 13 |    | 17 |     |
+---+---+---+---+----+----+----+----+----+-----+
| 2 | 4 |   | 8 | 10 |    | 14 | 16 |    |     |
+---+---+---+---+----+----+----+----+----+-----+
| 4 |   |   | 9 |    |    | 15 |    |    |     |
+---+---+---+---+----+----+----+----+----+-----+

The distances betwenn two horizontally adjacent node 

* 1st row: 6, 6, 6, 6 ....
* 2nd row: 4, 2, 4, 2, 4, 2 ...
* 3rd row: 2, 4, 2, 4, 2, 4 ...
* 4th row: 6, 6, 6, 6, 6, 6 ...

This example give me some idea but I am still not clear what the pattern is. So I want more rows, we can have examples like this

+---+---+---+---+----+----+----+----+----+
| 0 |   |   |   | 8  |    |    |    | 16 |
+---+---+---+---+----+----+----+----+----+
| 1 |   |   | 7 | 9  |    |    | 15 | 17 |
+---+---+---+---+----+----+----+----+----+
| 2 |   | 6 |   | 10 |    | 14 |    | 18 |
+---+---+---+---+----+----+----+----+----+
| 3 | 5 |   |   | 11 | 13 |    |    | 19 |
+---+---+---+---+----+----+----+----+----+
| 4 |   |   |   | 12 |    |    |    | 20 |
+---+---+---+---+----+----+----+----+----+

The distances betwenn two horizontally adjacent nodes are 

* 1st row: 8, 8, 8, 8 ....
* 2nd row: 6, 2, 6, 2 ....
* 3rd row: 4, 4, 4, 4 ....
* 4th row: 2, 6, 2, 6 ....
* 5th row: 8, 8, 8, 8 ....

Now we have some ideas of the patterns: 

1. for the first and the last row, the distance is a constant: :math:`RowNum * 2 - 2`. If total row number is fixed, this number is fixed. Lets call this DistanceSum. 
2. For the rows that are in between the first and last rows, the neighbor number has two different distances. Those two distances take turns to apply to the index horizontally. The first distance is :math:`DistanceSum - RowIndex * 2`. The second distance is :math:`RowIndex * 2`

Now if we generalize the two situations, we can get: every row uses two distances, one: :math:`DistanceSum - RowIndex * 2`, the other one: :math:`RowIndex * 2`. But if we encounter 0 as distance, we change it to DistanceSum. Or you can also say switch it to another oposite distance. 


Now we have the code: 

.. code-block:: c
   :linenos:

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







