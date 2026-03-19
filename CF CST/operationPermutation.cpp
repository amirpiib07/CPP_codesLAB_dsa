/*G. Operation Permutation
time limit per test2 seconds
memory limit per test256 megabytes
AksLolCoding has an integer x
 and a list of n
 operations. Each operation is a string starting with one of the symbols +,-,x, or / (representing addition, subtraction, multiplication, and real number division respectively), followed immediately by a positive integer y
 (1≤y≤109
). For example, the operation x3 represents multiplying x
 by 3
.

AksLolCoding will randomly permute the operations and then apply all operations sequentially to x
 in the permuted order. Help AksLolCoding compute the expected∗
 final value of x
 modulo 109+7
.

Formally, let M=109+7
. It can be shown that the answer can be expressed as an irreducible fraction pq
, where p
 and q
 are integers and q≢0(modM)
. Output the integer equal to p⋅q−1(modM)
. In other words, output such an integer a
 that 0≤a<M
 and a⋅q≡p(modM)
.

∗
The expected final value of x
 is the average of the final value of x
 over all n!
 permutations.

Input
The first line contains a single integer t
 (1≤t≤1000
), the number of test cases.

For each test case, the first line contains two integers n
 and x
 (1≤n≤3000
, 1≤x≤109
).

The second line of each test case contains n
 strings, each representing an operation in the format described above.

The sum of n2
 over all test cases does not exceed 30002
.

Note: x is used to represent multiplication, not *

Output
For each test case, output a single integer: the expected final value of x
 modulo 109+7
.

Example
InputCopy
4
2 10
x2 -10
4 2
+6 +7 /1 -13
8 1
+1 x2 x3 +4 +5 +6 -7 -8
9 864209753
-918273645 x564738291 /365107362 x734582911 -654321789 x998244353 +172519103 /482193765 /482091376
OutputCopy
5
2
166666677
601980218
Note
In the first test case, x
 can either be (10⋅2)−10=10
 or (10−10)⋅2=0
, resulting in an expected value of 5
.

In the second test case, all possible permutations result in x=2
.

In the third test case, the expected value of x
 is 556
.*/