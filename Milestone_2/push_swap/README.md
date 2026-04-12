*This project has been as part of the 42 curriculum by lupetill*

## Description

Welcome to the **Push_swap** project!

The goal of this project is to create a program capable of sorting a set of integers provided as input through the command line.

To achieve this, the algorithm uses two stacks, **a** and **b**, along with a limited set of allowed operations to move elements between them in a specific way.

The program outputs the sequence of operations required to sort the given integers.

### Operations
sa (swap a): Swap the first 2 elements at the top of stack a.

sb (swap b): Swap the first 2 elements at the top of stack b.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.

pb (push b): Take the first element at the top of a and put it at the top of b.

ra (rotate a): Shift up all elements of stack a by 1.

rb (rotate b): Shift up all elements of stack b by 1.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.

The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.

rrr : rra and rrb at the same time.

## Instructions

### Compile
- `make`        - *builds the libftprintf.a*
- `make clean`  - *removes .o files only*
- `make fclean` - *removes .o plus libftprintf.a*
- `make re`     - *removes everything and rebuilds libft.a*

### Input
The input must be provided in a specific format: either as a single string **"3 2 5"** or as individual arguments **3 2 5**.

To run the program, use **./push_swap** followed by the set of integers, for example:
```bash
./push_swap 3 2 5 1 4
```
To display the amount of instructions used, you can pipe the output to **wc -l**
```bash
./push_swap 3 2 5 1 4 | wc -l
```

### Integers
To automaticly generate a set of integers you can use the following command:
```bash
seq 1 100 | sort -R > numbers.txt
./push_swap $(cat numbers.txt)
./push_swap $(cat numbers.txt) | wc -l
```

### Testing
To cheack if the numbers are sorted at the end of the program, our subjet supply a checher to run next to our program.
```bash
seq 1 100 | sort -R > numbers.txt
./push_swap $(cat numbers.txt) | ./checker $(cat numbers.txt)
```


## Resources

- AI tools were used to reseach diferent sorting algorithms, clarify technical concepts and test the program.

- Polylog and CS Dojo Youtube channels were consulted to better understanding the Radix method.
