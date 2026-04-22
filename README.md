_This project has been created as part of the 42 curriculum by pkongkha_

# Description
The goal of this project is to sort numbers in stack with a limited instructions and achieve the lowest number of actions. Which leads to discovery of numberous of algorithms and metrics like time complexity and space complexity, but space complexity is not considered in this project.

These are the operations which is allowed to be used.

| Operations | What it does                              |
| ---------- | ----------------------------------------- |
| sa         | Swap first two elements on top of stack a |
| sb         | Swap first two elements on top of stack b |
| ss         | Do sa and sb at the same time             |
| pa         | Move top element of stack b to stack a    |
| pb         | Move top element of stack a to stack b    |
| ra         | Move top element of stack a to bottom     |
| rb         | Move top element of stack b to bottom     |
| rr         | Do ra and rb at the same time             |
| rra        | Move bottom element of stack a to top     |
| rrb        | Move bottom element of stack b to top     |
| rrr        | Do rra and rrb at the same time           |

My implementation is to use [three-way quick sort](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0) as algorithm, the stack is implemented by using customized [circular buffer](https://en.wikipedia.org/wiki/Circular_buffer) which I called it circular stack.
# Instructions
## Compilation
To compile the main sorter program
```sh
make all
```
For bonus part which is checker
```sh
make bonus
```
## Execution
To use this program, input a number you want to sort, then run

`./push_swap 1 5 4 2 3`
or
`./push_swap "1 5 4 2 3"`

Then it should yields the lowest possible of operations to sort the number
```
pb
rra
rra
pb
rra
sa
pa
pa
```
# Resources
- [WikiPedia | Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Ulysse Gerkens | Push Swap in less than 4200 operations](https://medium.com/@ulysse.gks/push-swap-in-less-than-4200-operations-c292f034f6c0)

## AI Usage
GitHub Copilot (GPT-5 mini backend) is used for
- Is used to analyze other's people code sample, comprehend the code logic.
- Is used to help with debugging where logic errors occured.
- Discussed about logic, but is not usable enough.
- Used for finding information about micro-optimization, techniques, coding convention.
  - Circular stack implementation, what's the best practice to implement.
- How to craft a proper makefile

Claude Sonnet 4.6 is used for producing malloc() failure test