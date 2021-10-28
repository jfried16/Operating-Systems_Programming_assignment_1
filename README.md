# Operating Systems Programming Assignment 1
In this assignment we used semaphores and shared memory, to handle the producer-consumer problem. The producer produces 20 items into a shared table, meanwhile the consumer is consuming items from that table. The table's maximum size is two. 

# Getting Started
In order to run this program, follow these these steps.

## Prerequisites 
  - Compiled on Ubuntu 20.04.3
  - g++
```bash
sudo apt-get install g++
```
## Installation
  - 1. Clone the repo 
  ```bash
  URL: https://github.com/jfried16/Operating-Systems_Programming_assignment_1.git
  ```
## To Run the Code for Yourself
  - 1. Use g++ to Compile the Program
  ```bash
  g++ producer.cpp -pthread -lrt -o producer
  g++ consumer.cpp -pthread -lrt -o consumer
  ```
  - 2. To Run the Program
  ```bash
  ./producer & ./consumer &
  ```
  - 3. When the program is done running
   ```bash
   ctrl + c
   ```
  ## Output
  The output should be similar to this (It will not exactly the same, due to randomness):
  ```bash
Producer ready to produce 20 items.
Consumer ready to recieve 20 items.

Item produced 
Items in table: 1
Items left to produce: 19

Item produced 
Items in table: 2
Items left to produce: 18

Item consumed 
Items in table: 1
Items left to consume: 19

Item consumed 
Items in table: 0
Items left to consume: 18

Item produced 
Items in table: 1
Items left to produce: 17

Item produced 
Items in table: 2
Items left to produce: 16

Item consumed 
Items in table: 1
Items left to consume: 17

Item produced 
Items in table: 2
Items left to produce: 15

Item consumed 
Items in table: 1
Items left to consume: 16

Item consumed 
Items in table: 0
Items left to consume: 15

Item produced 
Items in table: 1
Items left to produce: 14

Item produced 
Items in table: 2
Items left to produce: 13

Item consumed 
Items in table: 1
Items left to consume: 14

Item consumed 
Items in table: 0
Items left to consume: 13

Item produced 
Items in table: 1
Items left to produce: 12

Item consumed 
Items in table: 0
Items left to consume: 12

Item produced 
Items in table: 1
Items left to produce: 11

Item consumed 
Items in table: 0
Items left to consume: 11

Item produced 
Items in table: 1
Items left to produce: 10

Item produced 
Items in table: 2
Items left to produce: 9

Item consumed 
Items in table: 1
Items left to consume: 10

Item consumed 
Items in table: 0
Items left to consume: 9

Item produced 
Items in table: 1
Items left to produce: 8

Item produced 
Items in table: 2
Items left to produce: 7

Item consumed 
Items in table: 1
Items left to consume: 8

Item consumed 
Items in table: 0
Items left to consume: 7

Item produced 
Items in table: 1
Items left to produce: 6

Item consumed 
Items in table: 0
Items left to consume: 6

Item produced 
Items in table: 1
Items left to produce: 5

Item produced 
Items in table: 2
Items left to produce: 4

Item consumed 
Items in table: 1
Items left to consume: 5

Item consumed 
Items in table: 0
Items left to consume: 4

Item produced 
Items in table: 1
Items left to produce: 3

Item produced 
Items in table: 2
Items left to produce: 2

Item consumed 
Items in table: 1
Items left to consume: 3

Item consumed 
Items in table: 0
Items left to consume: 2

Item produced 
Items in table: 1
Items left to produce: 1

Item produced 
Items in table: 2
Items left to produce: 0

Producer cleaned up!

Item consumed 
Items in table: 1
Items left to consume: 1

Item consumed 
Items in table: 0
Items left to consume: 0

Consumer cleaned up!

^C
[1]-  Done                    ./producer
[2]+  Done                    ./consumer
```
## Code Written by
- Joshua Friedman
## Built Using
 - Visual Sutdio Code 1.61.2 - programming environment
 - g++ 9.3.0 - compilation
 - Ubuntu 20.04.3 - operating system
 ## Acknowledgements
 - Dr. Qiang Guan - My operating systems professor, seeing his code showed me the syntax required to open shared memory and use semaphores. 
 - URL: https://man7.org/linux/man-pages/dir_all_alphabetic.html - Used for reference
 - URL: https://www.youtube.com/watch?v=ukM_zzrIeXs - Used for reference
 
