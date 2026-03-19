#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int i=0;i<n;i++) {
            cin>>a[i];
        }
        set<int> winners;
        for (int start=0;start<n;start++) {
            vector<int> v(a);
            int sum=0;
            for (int ele:v) sum+=ele;
            int help=start;
            while (sum!=1) {
                if (v[help]>0) {
                    v[help]--;
                    sum--;
                }
                help=(help%n)+1;
            }
            for (int i=0;i<n;i++) {
                if (v[i]!=0) winners.insert(i+1);
            }
        }
        cout<<winners.size()<<endl;
    }
    return 0;
}
/*A. Eating Game
time limit per test1 second
memory limit per test256 megabytes
There are n
 players playing a game at a circular table. The i
-th player has ai
 dishes to eat. They take turns eating the food, and any player can go first.

During their turn, if player i
 has any dishes remaining, they must eat exactly one dish. Then, player (imodn)+1
 starts their turn. This continues until all dishes are finished.

The player who eats the last dish is considered the winner. Determine the number of players that can possibly be winners.

Input
The first line contains an integer t
 (1≤t≤5000
), the number of test cases.

The first line of each test case contains an integer n
 (1≤n≤10
).

The second line of each test case contains n
 integers, the elements of a
 (1≤ai≤10
).

Output
For each test case, output a line with the answer.

Example
InputCopy
3
1
10
2
6 7
4
1 4 3 4
OutputCopy
1
1
2
Note
In the first test case, player 1
 wins for every starting player.

In the second test case, player 2
 wins for every starting player.

In the third test case, players 2
 and 4
 can win.*/