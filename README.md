This is a linked list made from C++, with a few inserting, editing, and sorting functions (please check Map.h to see a overview of all the functions and how they work)
Download files and run testMap. 

# You Spin Me Round Robin

This is a implementation of round robin scheduling for a given workload and quantum length, as if it was processes in kernel (but written in c). This implementation uses TAILQ doubly linked list as a wait queue for our processes. Given a process.txt file and quantum time, the program should be able to output waiting time and response time.

## Building

To build the rr.c file (where the implementation is written) run make
```shell
make
```

## Running

To run the program, run the command below with your preffered quantum time (replace '_replace_quantum_time_') and given processes.txt file
```shell
./rr processes.txt _replace_quantum_time_
```
For example you can input: ./rr processes.txt 3

The output should be a average waiting and average response time in a float format. 
```shell
Average waiting time: <time>
Average response time: <time>
```

For example, the example above should give the results:
```shell
Average waiting time: 7.00
Average response time: 2.75
```



## Cleaning up

Run make clean for removal of the executables rr.o and rr files
```shell
make clean
```
