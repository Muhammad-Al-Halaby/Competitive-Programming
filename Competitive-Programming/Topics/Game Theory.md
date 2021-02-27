# Game Theory

# Combinatorial Games

We can analyse these types of games with backward induction.

We call a state N-position if it is a winning state for the next player to
move, and P-position if it is a winning position for the previous player.
1. All terminal positions are P-positions.
1. If every reachable state from the current one is a N-position then
the current state is a P-position.
1. If at least one P-position can be reached from the current one, then
the current state is a N-position.
1. A position is a P-position if all reachable states form the current one
are N position.
1. It's helpful to define each position as N-Position or P-Position, where N-Position means a winning state for the next player to move and P-Position means a winning state for the previous player.

## Nim Game

Given n piles of stones, 2 players take turns, at each turn the player chooses one pile and removes a non-zero number of stones from that pile, the player who can't make a move loses.

Winning state: if the xor of sizes of all piles is non-zero, then it's a winning state, at can be proved that there is always a possible transition to a non-zero state to a zero state, and it's not possible to move from a zero state to a zero state.

- Proofs: [1](https://en.wikipedia.org/wiki/Nim#Proof_of_the_winning_formula), [2](https://cp-algorithms.com/game_theory/sprague-grundy-nim.html)

## Sprague-Grundy theorem
the Sprague–Grundy theorem states that every impartial game under the normal play convention is equivalent to a one-heap game of nim, or to an infinite generalization of nim.

We can assign to every state an equivalent number to the size of the piles in the nim-game, which is known as the Grundy value or nim-value.

The Grundy value of a state is equal to the mex of the set of all Grundy values of the reachable states.

Grundy value being equal to zero means a losing state.

## Tutorials:

- https://algo.is/aflv16/aflv_10_mathematics.pdf

- https://www.youtube.com/watch?v=gp2JrB92n1c&list=PLPSFnlxEu99HhuXoV64dhSxXbWOazgw1v&index=18

- https://www.topcoder.com/community/competitive-programming/tutorials/algorithm-games/

- https://cp-algorithms.com/game_theory/sprague-grundy-nim.html

- https://codeforces.com/blog/entry/66040

- https://letuskode.blogspot.com/2014/08/grundy-numbers.html

## Problems

- https://codeforces.com/gym/102780/problem/H

- https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=6053

- https://codeforces.com/group/gRkn7bDfsN/contest/210807/problem/E

- https://codeforces.com/gym/102780/problem/F

- https://codeforces.com/contest/850/problem/C

- https://codeforces.com/gym/101608/problem/M
