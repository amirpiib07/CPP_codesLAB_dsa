/*E. Divisive Battle
time limit per test3 seconds
memory limit per test256 megabytes
Alice and Bob are playing game on array a
 initially containing n
 positive integers, with Alice going first.

On each player's turn, if a
 is non-decreasing∗
, the game immediately ends. Otherwise, the player can choose an element x
 from the array and positive integers 1<y,z<x
 such that x=yz
 and replace x
 in the array with two elements y
 and z
 (in any order). If no such move is possible, the game ends.

Once the game ends, if a
 is non-decreasing, then Bob wins. Otherwise, Alice wins. Determine who will win the game if both players play optimally.

∗
a
 is non-decreasing if ai≤ai+1
 for all 1≤i≤m−1
, where m
 is the length of a
.

Input
The first line contains an integer t
 (1≤t≤104
), the number of test cases.

The first line of each test case contains an integer n
 (1≤n≤105
).

The second line of each test case contains n
 integers a1,a2,…,an
 (1≤ai≤106
).

The sum of n
 over all test cases does not exceed 105
.

Output
For each test case, output a line containing "Alice" if Alice wins or "Bob" if Bob wins. The grader is case-sensitive.

Example
InputCopy
4
10
10 9 8 7 6 5 4 3 2 1
3
1 8192 677
2
6 5
2
6 7
OutputCopy
Alice
Bob
Alice
Bob
Note
In the first test case, Alice will win if both players play optimally.

In the second test case, Bob can always win no matter what moves Alice makes.

In the third test case, Alice can win by replacing 6
 with 3
 and 2
.

In the fourth test case, the game ends immediately and Bob wins.*/