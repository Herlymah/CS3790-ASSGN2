**Name: Halimah Abdulrasheed**
**Instructor: Franco Carlacci**
**Course: CS3790 Assignment 2**
**Date: 10/17/2024**
 
**Assignemnt Overview**
This assignment demonstrates the boss-worker computing model using C++. The objective is to divide the task of finding prime numbers between multiple worker processes. The boss process creates several worker processes, each responsible for searching primes within a specific range. 

**Files in the folder**
boss.cpp: This is the main program responsible for creating and managing worker processes.
worker.cpp: A helper program that calculates and prints the prime numbers in the given range. It can also work as a standalone program.

**How the Program Works**
The boss process takes two command-line arguments:
a) Number of worker processes to be created.
b) Upper bound for the range of numbers to search for primes.

**Each worker process:**
i) Receives a sub-range of numbers to process.
ii) Searches for prime numbers in that sub-range.
iii) Prints the primes found and exits.

**The boss process:**
i) Uses the fork() system call to create child processes.
ii) Uses execl() to run the worker program from within each child process.
iii) Waits for each worker to complete and reports their exit status.

**To compile and run the programs**
Open a terminal, you can also use a Linux environment such as Ubuntu, and run the following commands (without the quotation marks):
"g++ boss.cpp -o boss"
"g++ worker.cpp -o worker"
"./boss <num_workers> <upper_bound>" 

e.g ./boss 4 100 : This will create 4 worker processes
Each worker will process a part of the range from 1 to 100:
Worker 1: 1–25
Worker 2: 26–50
Worker 3: 51–75
Worker 4: 76–100

**Error Handling**
a) If the user provides invalid input (e.g., non-positive numbers), the program will display an error message and exit.
b) If a fork() or execl() call fails, the appropriate error message will be printed to stderr.

