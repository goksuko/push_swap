## Push_swap

The project is a simple highly structured algorithmic challenge: to sort data.
A set of integer values to be sorted is given to the C program called push_swap. The program sorts using only 2 stacks and a set of instructions to manipulate both stacks.
The program calculates and displays the shortest sequence of instructions needed to sort stack a with the smallest number at the top.

## Actions

The possible instructions are:

* ```pa``` (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
* ```pb``` (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
* ```sa``` (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
* ```sb``` (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
* ```ss```: ```sa``` and ```sb``` at the same time.
* ```ra``` (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
* ```rb``` (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
* ```rr```: ```ra``` and ```rb``` at the same time.
* ```rra``` (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
* ```rrb``` (reverse rotate B): Shift all elements of stack b down by 1. The last element becomes the first one.
* ```rrr``` : ```rra``` and ```rrb``` at the same time.

## Algorithm Efficiency
 
* Sorting 3 values: on average 2 instructions.
* Sorting 4 values: on average 7 instructions.
* Sorting 5 values: on average 9 instructions, no more than 10 instructions.
* Sorting 10 values: on average 25 instructions, no more than 30 instructions.
* Sorting 100 values: on average 610 instructions, no more than 720 instructions.
* Sorting 500 values: on average 5485 instructions, no more than 6500 instructions.
* Sorting 1000 values: on average 14618 instructions, no more than 14913 instructions.

Best known algorithm for big number of values is Radix Sort. In this sort, the values will have an index of their order and the values will be sorted by this indexes. 
The results for that algorithm:
* Sorting 3 values: on average 4 instructions.
* Sorting 4 values: on average 10 instructions.
* Sorting 5 values: on average 17 instructions.
* Sorting 10 values: on average 51 instructions.
* Sorting 100 values: on average 1028 instructions. 
* Sorting 500 values: on average 6760 instructions.
* Sorting 1000 values: on average 15018 instructions.

## Usage

In the cloned directory ```make``` command compiles the program.

```shell
git clone https://github.com/goksuko/push_swap
cd push_swap
make
```

The sample implentation:

```shell
./push_swap <numbers>
```

The numbers provided can be positive or negative unique integers. Any duplicates or non valid inputs will return Error.

```shell
./push_swap 9 0 -217 2147483647 -2147483648
```

If the arguments are valid, the program will output the most efficient list of actions to sort the list.

The program can be checked with the checker. Checker code is provided in the Bonus foder.

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

In addition to the generated algorithm, Radix Sort is also implemented. If the string "radix" typed just after the program name, the program will generate the results with radix sort.

```shell
./push_swap radix <numbers>
```

The program can also be checked with the test document. The numbers that are used in the test will be written to a tested_numbers.txt document. The test generates a random set of numbers (between -2000 and 2000) with the size of random size (between 1 and 1000) and tests the push_swap program with them. It also checks the output of the program with a checker program.

```shell
bash test.sh
```

In addition to a random test, the tests below can also be used:

**10 random numbers:**
```shell
ARG=$(seq 10 | sort -R | tr '\n' ' ') && ./push_swap $ARG
```
**100 random numbers:**
```shell
ARG=$(seq 100 | sort -R | tr '\n' ' ') && ./push_swap $ARG
```
**Number of instructions with 100 random numbers:**
```shell
ARG=$(seq 100 | sort -R | tr '\n' ' ') && ./push_swap $ARG | wc -l
```
**500 random numbers:**
```shell
ARG=$(seq 500 | sort -R | tr '\n' ' ') && ./push_swap $ARG
```
**Number of instructions with 500 random numbers:**
```shell
ARG=$(seq 500 | sort -R | tr '\n' ' ') && ./push_swap $ARG | wc -l
```


