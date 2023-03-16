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