Step 1) The program prints "Hello from thread i...", and also prints "Thread i returned". The Hello statement printing is in some random order 
and sometimes the same i repeats. The Thread i returned statement prints in order from 0 to 19. When running multiple times the order and 
iterations of the Hello statement changes, but the Thread i returned statement is always in order from 0 to 19, with sometimes one of the 
Hello statements printing in between the Thread i returned statement.

The parameter arg passed into go() that is a local variable is per-thread. The compiler stores these states into their thread control
blocks, so they have their own variables and instruction set.

The local variable i in main() is a shared state between threads. i is saved with the main global variables, but each one gets passed into threads
at different times.

Step 2) With the 2nd for loop removed, the outputs are only "Hello from thread i..." with i being 1-20. Sometimes i is repeated and the outputs are
not in order.
