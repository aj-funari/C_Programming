1. single-threaded version: main thread = 6.37 seconds
   multi-thread version: main thread = 3.74 seconds, thread 1 = 2.63 seconds, thread2 = 3.74 seconds

2. In multithread, main thread time != thread 1 time + thread 2 thread. Main thread takes less time to complete when being compared to both threads combined. 

3. Multi-thread results in a faster execution because each thread is counting from a substring concurrently. Single-thread has to count for a substring in a file once and then do it again right after completion. Multi-thread is faster because the threads can count for the substring at the same time. 

4. There are two possible outputs for the same code because we do not know which thread is going to exit first. When creating threads, the threads are created at the same time; however, it is undetermined which thread will complete first. 
