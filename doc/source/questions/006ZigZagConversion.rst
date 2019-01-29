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

Now we have some ideas of the patterns: for the first and the last row, the distance is a constant: :math: `row_num * 2 - 2`.
