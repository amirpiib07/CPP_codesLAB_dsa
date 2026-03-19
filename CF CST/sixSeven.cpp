//
// Created by AMIT KUMAR SINGH on 27-02-2026.
//

/*H. Six Seven
time limit per test2 seconds
memory limit per test256 megabytes
For positive integers i
 and j
, define fi(j)
 as the maximum integer k
 such that ik
 divides j
. A number j
 is considered special if f6(j)>f7(j)
. For example, 6
 is special, but 67
 and 7
 are not.

You are given an array a
 of n
 positive integers. In one operation, you must increase every element in the array by 1
.

Your task is to find the minimum number of operations needed to make all elements in a
 special at the same time, or determine that it is impossible.

Input
The first line contains an integer t
 (1≤t≤104
), the number of test cases.

For each test case, the first line contains an integer n
 (1≤n≤2⋅105
).

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤109
).

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer: the minimum number of operations to make all elements special at the same time, or −1
 if it is impossible.

Example
InputCopy
4
3
1 2 3
2
25 67
8
6 6 12 18 24 36 42 84
1
9557351
OutputCopy
-1
5
12
7
Note
In the first test case, all elements cannot be made special at the same time.

In the second test case, performing 5
 operations results in the array [30,72]
, whose elements are all special.

In the fourth test case, the array becomes [9557358]
 after 7
 operations.


*/