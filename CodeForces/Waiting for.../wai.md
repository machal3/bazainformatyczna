Waiting for...
time limit per test2 seconds
memory limit per test512 megabytes
Monocarp is waiting for a bus at the bus stop. Unfortunately, there are many people who want to ride a bus too.

You are given a list of events of two types:

B bi
 — a bus with bi
 free seats arrives at the stop;
P pi
 — pi
 people arrive at the stop.
These events are listed in a chronological order.

When a bus arrives, the following happens. All people at the bus stop (except for Monocarp) try to enter the bus. If there are enough free seats for all of them, then they all enter the bus. Otherwise, some people remain at the bus stop (the number of people who enter the bus is equal to the number of free seats).

If there is still at least one free seat after all people (except for Monocarp) enter the bus, then Monocarp can decide to enter this bus as well (but he might choose to wait for another bus). For each bus, you have to determine if it is possible for Monocarp to take that bus.

## Input
The first line contains one integer $n$ $(1 \leq n \leq 10^3) — the number of events.

Then, $n$ lines follow. The $i$-th of them contains the description of the $i$-th event in one of the two following formats:

- **B** $b_{i}$ $(1 \leq b_{i} \leq 10^{6)$ — a bus with $b_{i}$ free seats arrives at the stop;
- **P** $p_{i}$ $(1 \leq {_{i}≤10^{6})$ — $p_{i}$ people arrive at the stop.

Additional constraint on the input: there is at least one event of type **B**.

Output
For each event of type **B**, print `YES` if it is possible for Monocarp to take the corresponding bus, or `NO` otherwise (case-insensitive).

## Example
Input
```
10
P 2
P 5
B 8
P 14
B 5
B 9
B 3
P 2
B 1
B 2
```
Output
```
YES
NO
NO
YES
NO
YES
```
