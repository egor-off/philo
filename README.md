# philo
In this project, I will learn the basics of threading a process. I will learn how to make threads and processes. I will discover the mutex and semaphore.

We can start this program with 4 or 5 arguments.
  The first argument is the number of philosophers.
  The second - is time_to_die in ms.
  Third - is time_to_eat in ms.
  Forth - is time_to_sleep in ms.
  Fifth - is the number of times each philosopher must eat.
  
In the mandatory part, each philosopher is a thread and each fork is a mutex.
In the bonus part, each philosopher is a process and forks represented by semaphores.
There is one fork per one philosopher.
If we would start the program with arguments 5 800 200 200, the simulation would never end.
Otherwise, if we would start the program with arguments 4 310 200 100, the simulation would stop at 315 ±5 ms after the start.
