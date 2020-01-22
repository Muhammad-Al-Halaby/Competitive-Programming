# PST Semi-Senior Training Camp

## Session 1:

- Graph Terminologies <details>
  - nodes
  - edges
  - directed/undirected
  - weighted/unweighted
  - connected/disconnected
  - cyclic/acyclic, adjacency
  - multigraph
  - self-loop
  - simple graph
  - implicit/explicit graph
  - regular/complete graph
  - sparse/dense graph (i.e. Dijkstra)
  - bipartite(even and odd cycles)
  - Tree
  - DAG
  - In/Out Degree.
</details>


- Graph Representation <details>
  1. Edge List.
  1. Adjacency Matrix.
  1. Adjacency List.
    1. Array of vectors implementation.
    1. Linked-List-like implementation.
</details>


- Stable Marriage Problem.
- Human and water grid Problem.
- 12 O'clock buttons Problem.


- Slides: https://docs.google.com/presentation/d/1XDN3L7tl5ecfoTs9L6H2hYwOrIpe9HjZ4O1vDVaZA2Q/edit#slide=id.p4

- Adjacency List (Linked-List-like implementation):
https://stackoverflow.com/questions/3002764/is-a-linked-list-implementation-without-using-pointers-possible-or-not

---

## Session 2:

- memset (1 byte).
- DFS.
- Tree Check.
- Directions Generation Trick.

- Problems: https://vjudge.net/contest/307789
  1. Is it a tree: https://ideone.com/GNXKtY
  1. Castle: https://ideone.com/T0TgFl
  1. Ordering Tasks: https://ideone.com/IAZjnH
  1. Pick up sticks
  1. Road Map
  1. Longest path in a tree
  1. VALIDATE THE MAZE

  ---

## Session 3:

- BFS (0/1 SSSP).
- Topological Order using In degree.
- Cycles detection using In degree.

- BFS from destination to all possible sources (Reversed Shortest Path).

- Multisource BFS.

- Problems: https://vjudge.net/contest/308019
  1. The Cats and the Mouse
  1. Tobo or not Tobo: https://ideone.com/tWcbIh
  1. Two Buttons
  1. The Seasonal War
  1. Party
  1. Escape from Jail Again
  1. Knight Moves
  1. The Dueling Philosophers Problem: https://ideone.com/eTkwKY
  1. Interesting number

---

## Session 4:

- Iterative Deepening Search (IDS)

- Problems:
  1. [The Clocks](https://train.usaco.org/usacoprob2?S=clocks&a=feUKstPGiDJ)
    - Solutions:
      1. DFS: https://ideone.com/1tn0xJ
      1. BFS: https://ideone.com/sNNvU2

---

## Session 5:
- Dijkstra (Sparse/Dense)

- Problems: https://vjudge.net/contest/308781
  1. [Bessie Come Home](https://train.usaco.org/usacoprob2?S=comehome&a=feUKstPGiDJ): https://ideone.com/SL1rpk
  1. Cheapest way
  1. Exchange Rates
  1. Lift Hopping
  1. Highways
  1. A Node Too Far
  1. Number Maze

---

## Session 6:

- Floyd-Warshall (all pairs shortest paths, negative cycles, positive cycles).

- Bellman-Ford (shortest paths with negative weights, negative cycles, positive cycles).

- Stress test: https://ideone.com/BMQM6v

- Problems: https://vjudge.net/contest/309427‎
  1. [Highways](https://vjudge.net/contest/308781#problem/D): https://ideone.com/RSM46e
  1. [Bessie Come Home](https://train.usaco.org/usacoprob2?S=comehome&a=feUKstPGiDJ): https://ideone.com/MBIrlG
  1. Wormholes:
    - Solutions:
      1. Bellman: https://ideone.com/kwLaRV
      2. (Bellman + Optimizations): https://ideone.com/Heu1iD

---

## Session 7

- Minimum Spanning Trees.
- Prim (nlogn, n^2).
- DSU
- Kruskal (sort edges trick through 3rd array).

- Problems: https://vjudge.net/contest/309427
  1. (PrimNLOG): https://ideone.com/vgclbz
  1. (PrimN^2): https://ideone.com/5ftCT5
  1. Castle (DSU): https://ideone.com/rrahLF
  1. Kruskal: https://ideone.com/rwiJxK

---

## [Practice Contest #1](https://vjudge.net/contest/309827)

- Solutions:
  - A: https://ideone.com/85XDUx
  - B: https://ideone.com/1ptRmH
  - C: https://ideone.com/xCSfEc
  - D: https://ideone.com/4Mfjlp
  - E: https://ideone.com/87IMva
  - F: https://ideone.com/mjUgiS


---

## Session 8

- Eulerian Graph
  - Undirected graph: all even, all even 2 odd.
  - Directed graph: IN = OUT, IN = OUT exact 2 IN > OUT, OUT > IN

- Problems (last 3 problems): https://vjudge.net/contest/309427
  1. [Riding the Fences (Euler DFS)](https://train.usaco.org/usacoprob2?S=fence&a=feUKstPGiDJ): https://ideone.com/TAK0ku

---

## Session 9

- Dynamic Programming.

- Problems: https://vjudge.net/contest/311195
  1. Fibonacci (with/without memoization): https://ideone.com/nt5R4D
  1. Knapsack: https://ideone.com/nwffzG
  1. [Money Systems (Coin Change)](https://train.usaco.org/usacoprob2?S=money&a=feUKstPGiDJ): https://ideone.com/f7Ops1
  1. LIS: https://ideone.com/3zxaGj
  1. 	To Europe! To Europe!: https://ideone.com/HcIZpV
  1. Wachovia Bank
  1. Princess Farida
  1. Dollars
  1. Coin Change
  1. Wedding shopping
  1. Easy Longest Increasing Subsequence
  1. Candy
  1. Flowers
  1. Bubble Sort Graph
  1. Edit distance

---

## Session 10

- Problems: https://vjudge.net/contest/311195
  1. Matrix Chain Multiplication: https://ideone.com/LLPVMg
  1. Traveling Salesman Problem: https://ideone.com/7XkDmM
  1. Longest Common Sub-sequence + Path Printing: https://ideone.com/D8FImk
  1. MCM + Path Printing: https://ideone.com/4kBbOZ
  1. Red-Green Towers
  1. Kefa and Dishes
  1. Fence
  1. Painting Fence

---

## Session 11

- Iterative DP.

- Problems:
  1. Knapsack (Iterative): https://ideone.com/nENAb9
  1. Coin Change (Iterative): https://ideone.com/vkMjjQ
  1. LIS (Iterative): https://ideone.com/wyMywl

---

## [Practice Contest #2](https://vjudge.net/contest/312880)

- Kadane's Algorithm.
- [Gotta Catch 'Em All](https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&Itemid=99999999&category=722&page=show_problem&problem=6057).
- Solutions:
  - A: https://ideone.com/YS2UhQ
  - B: https://ideone.com/KYDSCg
  - C: https://ideone.com/9GxNup
  - D: https://ideone.com/rfyrrL
  - E: https://ideone.com/XeNHQ2
  - F: https://ideone.com/HnydH2

---

## [Practice Contest #3](https://vjudge.net/contest/313497)


---
## Session 12

- Sieve of Eratosthenes.
- Congruence Relation.
- Euclidean Algorithm.
- Extended Euclidean Algorithm.
- Solving Linear Diophantine. Equations.
- Bezout's Identity.

- Codes: https://ideone.com/fL3OPS

- Iterative fast power: https://ideone.com/5JtH4I


- Number Theory: https://github.com/Muhammad-Magdi/Problem-Solving/tree/master/Number%20Theory

<details>
<summary>Proof 1</summary>
a, b, a%b, ...... fa in general : anta equal aly 2blk b5tweten % aly 2blk
ax` + by` = g
r0 = a , r1 = b , ri = ri - 2 % ri - 1;
if(rk == 0) then r(k-1) is GCD
aXi + bYi = ri
aX0 + bY0 = r0 = a X0 = 1 , Y0 = 0 , X1 = 0 , Y1 =1
aX1 + bY1 = r1 = b

ri = r(i-2) mod r(i-1) = r(i-2) - qr(i-1) = r(i-2) - floor(ri-2 / ri-1) * ri-1
if we replace ri with :
aXi + bYi = [aX(i-2) + bY(i-2)] -floor(ri-2 - ri-1) * [aX(i-1) + bY(i-1)]
= a[X(i-2) - floor(r(i-2) / r(i-1)) * X(i-1)] + b [Y(i-2) - floor(r(i-2)/r(i-1)) * Y(i-1)]
Xi = X(i-2) - floor(r(i-2) / r(i-1)) * X(i-1)
Yi = Y(i-2) - floor(r(i-2) / r(i-1)) * Y(i-1)
</details>

<details>
<summary>Proof 2</summary>
gcd(a,b) = g means : g/a , g/b , no k>g that k /a , k/b
a = q2.g + 0 >> means remender = 0 , divisibale y3ny --------------------> 1
b = q1.g + 0 ~ ~ ~ --------------------> 2
gcd(a,b) = g hoa nfso gcd (b,a-b) hoa nfso gcd (b,c) hoa nfso gcd(b,a%b) ;

to prove : gcd (b,a-b)
from 1 & 2 > a - b = (q1 - q2)g + 0 that means divisibale by g , then g /(a-b)
k > g , k / b , k / a - b
b = q3.k + 0 -------------------->3
a-b = q4.k + 0 -------------------->4
from 3 & 4 a = (q3 + q4)k + 0
k/a contradiction

so gcd(a,b) = gcd(b,b-a)
= gcd (b, a-2b)
= gcd (b, a-3b)
= gcd (b, a-4b)
so gcd(a , b) = gcd(b,a%b)

a % b : if a > b then , a % b < (a/2)
if a < b then , a % b = a

hdek 3 integers a , b, c w arg3 kym x , y aly bt72a2 al mo3adla
aX + bY = c given that a , b , c integers
ax + by = mg : g = gcd (a , b)
</details>

---

## Session 13 & 14

- Geometry.

- Coach Library: https://drive.google.com/file/d/17xQVgYoJnaXVRlhVYvHmILejsIpyEv4w/view
- http://ideone.com/3jlFIf
- https://ideone.com/t224qh

---

## Session 15

- Problems
  1. Fun With Strings: https://ideone.com/6yp87r
  1. [Pair of Lines](https://codeforces.com/problemset/problem/961/D): https://ideone.com/svAGP3
  1. [Zen and his Crush](https://www.spoj.com/problems/ZCR/): https://ideone.com/gfRgPx

---

## [Practice Contest #4](https://vjudge.net/contest/317365)

- Solutions:
  - A: https://ideone.com/nlXMRk
  - B: https://ideone.com/joJANI
  - C: https://ideone.com/ANIGLU
  - D: https://ideone.com/KsER5G
  - E: https://ideone.com/3JKW7f - https://ideone.com/ricHbL
  - F: https://ideone.com/hWX62p

---

## Session 16

- Rabin-Karp Algorithm.

- Problems: https://vjudge.net/contest/320829
  1. Needle in the Haystack: https://ideone.com/jYymIr
  1. Extend to Palindrome: https://ideone.com/ogPUMD
  1. Ada and Spring Cleaning: https://ideone.com/3Wzo5q

---

## Session 17

- KMP.
- Trie.

- Problems: https://vjudge.net/contest/320829
  1. Needle in a Haystack (KMP): https://ideone.com/jhGH4I
  1. PERIOD (KMP): https://ideone.com/l7yra8
  1. [PhoneList](https://www.spoj.com/problems/PHONELST/) (Trie): https://ideone.com/cxxLgc

---

## Session 18

- Z-Algorithm: https://ideone.com/nZjA5B.
- Suffix Array: https://ideone.com/YqVvbK
- Longest Common Prefix.

- Problems:
  1. [Pattern Find](https://www.spoj.com/problems/NAJPF/) (Z-Algorithm): https://ideone.com/rw8nCn
  1. [I Love Strings!!](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1620) (Suffix Array): https://ideone.com/DRAQJi
  1. [Freedom of Choice](https://acm.timus.ru/problem.aspx?space=1&num=1517) (Suffix Array): https://ideone.com/GZfwvx
  1. [New Distinct Substrings](https://www.spoj.com/problems/SUBST1/) (Suffix Array): https://ideone.com/pWC9kn
