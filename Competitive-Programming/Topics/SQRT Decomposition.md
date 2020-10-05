  # SQRT Decomposition

- split updates into buckets
- split input numbers into buckets (on certain property like min, mx, sum, freq, etc).



- Note: sqrt(1e5) = 316, sqrt(1e6) = 1e3
## Problems
1. [RMQSQ - Range Minimum Query (SPOJ)](https://www.spoj.com/problems/RMQSQ/)
1. [KQUERY - K-query (SPOJ)](https://www.spoj.com/problems/KQUERY/)
1. [RACETIME - Race Against Time (SPOJ)](https://www.spoj.com/problems/RACETIME/)
1. [Intro to SQRT-Decomposition Contest - ACM JCPC Training](https://codeforces.com/group/BDIXyZZHhT/contest/205512)
1. [Pair of Topics - CF-Div3-D](https://codeforces.com/contest/1324/problem/D)
1. [Xenia and Tree CF-Div2-E](https://codeforces.com/contest/342/problem/E)
1. [Holes - CF-Div2-E](https://codeforces.com/contest/13/problem/E)
1. Extendable Sorted Array - (2 Queries: 1: add a to array, 2: print count of numbers [l, r]) -> (segment tree on frequencies (offline)), (sqrt decomp with sorting buckets and merge like merge sort and answering queries with binary search), (numbers compression and split frequencies of values into sqrt buckets and update frequencies).
1. [New Year Tree - CF-Div2-E](https://codeforces.com/contest/620/problem/E) (SQRT-Decomposition with lazy propagation)


1. You have N different nodes in a graph and is responsible for 3 queries:

1) Connect 2 nodes by an edge 2) Delete edge between 2 nodes 3) Query whether or not 2 nodes are connected.

You can break the queries into O(sqrt(N)) chunks and process each individually using Union Find.

# Not Solved Yet
1. https://codeforces.com/contest/1199/problem/D
1. https://codeforces.com/contest/622/problem/C
1. https://codeforces.com/problemset/problem/551/E
1. https://codeforces.com/contest/455/problem/D
1. https://codeforces.com/contest/513/problem/F2
1. https://www.codechef.com/problems/CHEFEXQ
1. https://www.codechef.com/problems/FNCS
1. https://codeforces.com/contest/86/problem/D
1. https://www.hackerearth.com/problem/algorithm/final-question/description/
1. https://www.codechef.com/OCT16/problems/BGQRS

# Tutorials:
- SolverToBe
- https://cp-algorithms.com/data_structures/sqrt_decomposition.html
- http://acm.math.spbu.ru/~sk1/mm/lections/mipt2016-sqrt/mipt-2016-burunduk1-sqrt.en.pdf
- https://www.infoarena.ro/blog/square-root-trick
- http://ayurjain.blogspot.com/2016/08/square-root-decomposition.html?view=sidebar
- https://assets.hkoi.org/training2019/sqrt.pdf
