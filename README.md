# Production Systems Example

This repository contains an example from the university courses about Production Planning. This codebase is written during the practical courses by Kulcsár Gyula, and copied here by me.

## Other notes
https://mandarin.iit.uni-miskolc.hu/iitkgy/do/TFM_2023/

## Explanation

We have a central storage and a processing unit. We know the processing time for every unit.

P_i (i1, i2, ..., in)
t0 = 0

We do not modell the output time.

Secondly, the task is then extended by multiple processing units.

Thirdly, the task is also extended by series of processing units, where the units are chained together.

#### The first problem
A permutation problem |j1|j2|j3|j4|j5|. This is a special case of the flowshop problem.

INPUT -> MODEL loading -> SCHEDULER -> SIMULATION -> REPORT / RESULT

JAYA algorithm: mutation and recombination is done in the same operation
- Chooses the best and the worst from the population
- Takes the best, the worst and iterates through other candidates, and combines the three.

#### The third problem
Sequentially connected machines. The operation time can be different per job and per machine.

$J_i \rightarrow O_i,_1, O_i,_2, ... , O_i,_m$

The capacity of interoperation buffers are infinite.

The order of machines do not change.

We are looking for the order in which the $C_max$ is 
smallest

## Multipurpose optimization
Can be done by:
1. Linear combination of purposes. **Problem:** Value space could
be very different.
2. Hierarchic optimization. **Problem:** Algorithm sensitive.
3. Parallel optimization. Counts the purpose function results that
are better than the other. If more are better, than the result is 
better.

### Another way to do multi-purpose optimization
- Relative comparisons.
- K functions are given (optimization purpose / objective functions).

The functions' return values must not be negative numbers.

D:= 0, if f1(x) és f2(x) = 0, otherwise (f2(x) - f1(x)) / max(f1(x), f2(x))

D returns a relative difference between -1 and 1.

$D(a,b) = \frac{b-a}{max(a,b)} \in [-1;1]$

Sum of relative differences:\
$F(x,y) = \sum_{k=1}^{K} D(f_k(x),f_k(y))$

Weighted sum of relative differences:\
$F(x,y) = \sum_{k=1}^{K} w_k D(f_k(x),f_k(y))$

The weight values can be set by the user.

## Time constraints
Not all resources are always available. There are times, when we cannot 
use a resource for any operation.

The operations can be of two types.
1. Atomic.
2. Divisible.