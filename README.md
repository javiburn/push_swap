# push_swap

A project in which I had to create an algorithm which would sort a list of numbers using some predefined rules.
We have two stacks, in the first one, the stack A, we have a list of random numbers, whereas the second stack (stack B) is empty. We can use this instructions to sort any of the two stacks or to send the top numbre of the. stack A to the top of Stack B and viceversa.
sa - swap the first two numbers at the top of the Stack A
sb - swap the first two numbers at the top of Stack B
ss - do sa and sb at the same time
ra - send the first number at the top of Stack A to the bottom
rb - send the first number at the top of Stack B to the bottom
rr - do ra and rb at the same time
rra - put the number at the bottom of Stack A into the top of it
rrb - put the number at the bottom of Stack B into the top of it
rrr - do rra and rrb at the same time
pa - push the first element at the top of Stack B to the top of Stack A
pb - push the first element at the top of Stack A to the top of Stack B

The algorithm should be able to identify which of these instructions is the best one in order to do the least amount of moves and print it. 

It is able to sort 100 random moves in less than 900 instructions, and a list of 500 numbers in less than 8000
