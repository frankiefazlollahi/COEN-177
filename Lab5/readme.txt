Step 1) When I ran threadSync.c program the threads (0-9) entered and returned from the critical section in order,
and the main thread always returned last. Sometimes no threads would return after one entered the critical 
section, and sometimes 1-2 would return. This program also had a little delay between each time a thread entered the
critical region. This is different than the threadHello.c program because that program seemed to have
unnoticable delay and sometimes the Hello would come from the same thread. In both programs the threads would return
in order.

Step 2)
