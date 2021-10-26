# Operating Systems Programming Assignment 1
In this assignment we used semaphores and shared memory, to handle the producer-consumer problem

# Getting Started
In order to run this program, follow these these steps.

## Prerequisites 
  - Compiled on Ubuntu 20.04.3
  - g++
```bash
sudo apt-get install g++
```
## To Run the Code Yourself
  - 1. Clone the repo 
  ```bash
  URL: https://github.com/jfried16/Operating-Systems_Programming_assignment_1.git
  ```
  -2. Use g++ to Compile the Program
  ```bash
  g++ producer.cpp -pthread -lrt -o producer
  g++ consumer.cpp -pthread -lrt -o consumer
  ./producer & ./consumer &
  ```
  
