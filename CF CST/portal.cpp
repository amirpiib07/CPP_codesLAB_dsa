/*D. Portal
time limit per test2 seconds
memory limit per test256 megabytes
You are given a permutation∗
 p
 of length n
. There are also two portals located at positions x
 and y
 (x<y
).

A portal at position i
 is initially located between the i
-th and (i+1)
-th elements of the array. Specifically, if i=0
, then the portal is located before the first element of the array, and if i=n
, then the portal is located after the last element.

You may perform either of the following two operations as many times as you like:

Remove the element to the immediate left of one portal and insert it to the immediate right of the other portal.
Remove the element to the immediate right of one portal and insert it to the immediate left of the other portal.
Let O
 denote a portal. For example, if p
 is [3,O,2,4,O,1]
:

Using operation 1
 on the left and right portals respectively results in the arrays [O,2,4,O,3,1]
 and [3,O,4,2,O,1]
.
Using operation 2
 on the left and right portals respectively results in the arrays [3,O,4,2,O,1]
 and [3,1,O,2,4,O]
.
Find the lexicographically†
 smallest permutation you can obtain using these operations. Note that portals do not affect the lexicographical comparison of permutations.

∗
A permutation of length n
 is an array of length n
 containing each integer from 1
 to n
 exactly once.

†
A permutation a
 is lexicographically smaller than permutation b
 if there exists an index i
 such that aj=bj
 for all indices 1≤j<i
 and ai<bi
.

Input
The first line contains an integer t
 (1≤t≤2⋅104
) — the number of test cases.

For each test case, the first line contains three integers n
, x
, and y
 (1≤n≤2⋅105
, 0≤x<y≤n
).

The second line of each test case contains n
 integers p1,p2,…,pn
 — a permutation of length n
.

The sum of n
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a line with n
 integers — the lexicographically smallest permutation you can obtain.

Example
InputCopy
4
4 0 4
3 1 4 2
3 1 2
3 2 1
5 1 3
1 3 5 2 4
2 0 1
1 2
OutputCopy
1 4 2 3
2 3 1
1 2 3 5 4
1 2
Note
Let O
 denote a portal.

In the first test case, the array is [O,3,1,4,2,O]
. Using operation 2
 on the left portal results in [O,1,4,2,3,O]
, which is the lexicographically smallest possible permutation that can be obtained.

The operation described above.
In the second test case, the array is [3,O,2,O,1]
. Using operation 1
 on the left portal results in [O,2,O,3,1]
, which is the lexicographically smallest possible permutation that can be obtained.

In the fourth test case, it is optimal not to do any operations.*/