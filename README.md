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
 
* Sorting 3 values: no more than 2 instructions.
* Sorting 4 values: no more than 7 instructions.
* Sorting 5 values: no more than 10 instructions with 9 average.
* Sorting 100 values: no more than 720 instructions with 610 average.
* Sorting 500 values: no more than 6500 instructions with 5485 average.

Best known algorithm for big number of values is Radix Sort. In this sort, the values will have an index of their order and the values will be sorted by this indexes. 
The results for that algorithm:
* Sorting 100 values with 1084 instructions (if not sorted, always the same number). 
* Sorting 500 values with 6785 instructions (if not sorted, always the same number).
Solution is not provided but can be found [in this address](https://github.com/42YerevanProjects/push_swap).

## Usage

Git clone the repository and cd into it. Then use ```make``` to compile.

Then run it with :

```shell
./push_swap <numbers>
```

The numbers provided can be positive or negative integers. There must not be any duplicates. For example :

```shell
./push_swap 9 0 -217 2147483647 -2147483648
```

If the arguments are valid, the program will output the most efficient list of actions to sort the list.

The program can be checked with the checker.

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

The program can be also be checked with the test document. The numbers that are used in the test will be written to a tested_numbers.txt document. The test generates a random set of numbers (between -2000 and 2000) with the size of random size (between 1 and 1000) and tests the push_swap program with them. It also checks the output of the program with a checker program.

```shell
bash test.sh
```

