## Introduction
From [Wikipedia](https://en.wikipedia.org/wiki/Collatz_conjecture):

Take any positive integer n. If n is even, divide it by 2 to get n / 2. If n is odd, multiply it by 3 and add 1 to obtain 3n + 1. The conjecture is that no matter what number you start with, you will always eventually reach 1.

This package calculates the stoping time, aka how many steps it takes to get  to one.

## Installation:
```{r}
if(!require(devtools)) install.packages("devtools")
devtools::install_github("johnwilshire/collatz")
```

## Example:

```{r}
> collatz(1:10)
   number stopping_time
1       1             0
2       2             1
3       3             7
4       4             2
5       5             5
6       6             8
7       7            16
8       8             3
9       9            19
10     10             6
```
## Implementation details:
This package was built with Rcpp, and uses a map to speed up computation.

