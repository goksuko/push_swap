## Push_swap

## Target

The project is a simple yet highly structured algorithmic challenge: to sort data.
A set of integer values to be sorted using only 2 stacks, and a set of instructions to manipulate both stacks.
Your goal? Write a C program called push_swap that calculates and displays the shortest sequence of Push_swap instructions needed to sort the given integers.

## Actions

The possible actions are:

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

## Algorithms vs Number of Actions
 
* Sorting 3 values: no more than 3 actions.
* Sorting 5 values: no more than 12 actions.
* Sorting 100 values: no more than 700 actions.
* Sorting 500 values: no more than 5700 actions.

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

The program can be checked with the provided checker, like this :

```shell
ARG="3 0 9 2 -1"; ./push_swap $ARG | ./checker $ARG
```

You can visualize this push_swap algorithm in action with [O-reo's push_swap visualizer](https://github.com/o-reo/push_swap_visualizer):

![Push_swap visualization by mcombeau](https://github.com/mcombeau/push_swap/blob/main/subject/push_swap_visualization.gif)
