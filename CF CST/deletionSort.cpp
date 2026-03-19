#include<bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int >a(n);
        for (int i=0;i<n;i++) {
            cin>>a[i];
        }

        int found=0;
        for (int i=1;i<n;i++) {
            if (a[i]>=a[i-1]) found=1;
            else {
                found=0;
                break;
            }
        }
        if (found==1) cout<<n<<endl;
        else cout<<1<<endl;

    }
    return 0;
}
/* B. Deletion Sort
time limit per test1 second
memory limit per test256 megabytes
AksLolCoding is playing a game on an array a
 of n
 positive integers. During each turn:

If a
 is non-decreasing∗
, the game ends.
Otherwise, AksLolCoding can choose any single element and remove it from the array.
Determine the minimum possible number of elements that can be remaining in the array after the game ends.

∗
a
 is non-decreasing if ai≤ai+1
 for all 1≤i≤m−1
, where m
 is the length of a
.

Input
The first line contains an integer t
 (1≤t≤1000
), the number of test cases.

The first line of each test case contains an integer n
 (1≤n≤10
).

The second line of each test case contains n
 integers, the elements of a
 (1≤ai≤100
).

Output
For each test case, output an integer: the minimum possible number of elements left once the array is sorted.

Example
InputCopy
3
4
1 4 2 3
1
100
2
6 7
OutputCopy
1
1
2
Note
In the first test case, the minimum of 1
 element can be achieved by removing 1
, 2
, and 3
 in that order.

In the second and third test cases, no elements can be removed.*/
