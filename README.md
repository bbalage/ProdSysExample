# Production Systems Example

This repository contains an example from the university courses about Production Planning. This codebase is written during the practical courses by Kulcsár Gyula, and copied here by me.

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