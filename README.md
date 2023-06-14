# Push_Swap

 ## About The Project
In this project I had to create an algorithm which would sort any list of random numbers using some predefined rules.

We have two stacks, in the first one, the stack A, we have a list of random numbers, whereas the second stack (stack B) is empty. We can use this instructions to sort any of the two stacks or to send the top number of the stack A to the top of Stack B and viceversa.

```
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
```


# Algorithm `Optimus Prime 🤖`

As you can tell from its name (inspired by the Transformer [Optimus Prime](https://es.wikipedia.org/wiki/Optimus_Prime)), this algorithm is designed to find which is the most optimus number to be sent to the other stack using the least amount of movements.



It starts dividing the numbers from stack A into 10 chunks from the minimum number to the maximum. The 10 smallest numbers will be on the first chunk, then on the second one the next 10, and so on and so forth.

Then it will start comparing where the numbers of the first chunk are and it will find the one that needs the least amount of movements to be at the top or at the bottom of the stack (using ra or rra). This optimus number will be sent to the stack B.

By doing this repeatidly, we will have the first 10 numbers on the stack B. The won't be sorted yet, but this will be done later.

We will do the same until we have every number from stack A into stack B.

Now it will be the time to send them back to stack A sorting them using rb and rrb just before doing pb. As we have divided the numbers into chunks, and the chunks have been effectively sorted, each number will be sent back to stack A using a maximum of 10 moves each.







The algorithm should be able to identify which of these instructions is the best one in order to do the least amount of moves and print it. 

It is able to sort 100 random moves in less than 900 instructions, and a list of 500 numbers in less than 8000
