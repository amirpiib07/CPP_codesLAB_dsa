#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<char>st;
        for (char ch: s) {
            if (!st.empty()&&st.top() == ch) {
                st.pop();
            }
            else st.push(ch);
        }
        cout<<(st.empty()?"YES":"NO")<<endl;
    }
    return 0;
}
/*C. Specialty String
time limit per test2 seconds
memory limit per test256 megabytes
AksLolCoding is playing a game on a string s
 of length n
. Initially, s
 contains only lowercase Latin characters.

In one turn, AksLolCoding can choose any pair of integers (i,j)
 such that:

1≤i<j≤n
;
si=sj≠∗
; and
sk=∗
 for all i<k<j
.
If no such i,j
 exists, then the game ends. Otherwise, AksLolCoding sets si:=∗
 and sj:=∗
.
Once the game ends, AksLolCoding wins if and only if every character in s
 is equal to ∗
. Determine if it is possible for AksLolCoding to win.

Note: ∗
 represents ASCII character 42.

Input
The first line contains an integer t
 (1≤t≤100
), the number of test cases.

The first line of each test case contains an integer n
 (1≤n≤5000
), the length of the string.

The second line of each test case contains a string s
 consisting of lowercase Latin characters.

The sum of n
 over all test cases does not exceed 5000
.

Output
Output the answer to each test case on its own line. If AksLolCoding can win, output "YES" (without quotes). Else, output "NO" (without quotes).

You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
InputCopy
6
1
a
6
llmllm
6
uwuuwu
6
byebye
6
oooioi
12
siixxsevvenn
OutputCopy
NO
YES
YES
NO
NO
YES
Note
In the first test case, it can be shown that it is impossible for AksLolCoding to win.

In the second test case, AksLolCoding can win by making the following moves: llmllm →
 llm**m →
 **m**m →
 ******

In the third test case, AksLolCoding can win by making the following moves: uwuuwu →
 uw**wu →
 u****u →
 ******


*/