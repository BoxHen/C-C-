# Managing Turbine Supply

The US power grid consists of multiple inter-connected generators with different capacities for generating electricity. The overall output must be balanced to provide a steady supply. In reality, excess capacity is stored in batteries, shortage of power is balanced by taking it back from the batteries. We will manage this over/under-supply, by cutting back or increasing generation on demand. In these instructions, the terms generator and turbine are interchangeable.
Write a program simulating those n generators. Each generator will be a separate thread. You will be given a value for the initial power and the maximum power (watts) that each of your generators can produce. They are NOT allowed to attempt to produce output greater than the max value or less than 0! As time goes by, the total load (demand for power) for your whole grid system will change (as specified by an input file you will read). 
Be sure to add:
    • #include “turbine-defines.h” to your code. The file is in “OS-common\Project basics\includes” on my website. It contains 2 #define values for the size of the grid: ROWCOUNT & COLCOUNT and a #define for the interval in seconds (like .03) TFARM_CYCLE_TIME. The number is just text, so you have to use it in a declaration, such as: float delta=TFARM_CYCLE_TIME;
    • #define HAVE_STRUCT_TIMESPEC
which is needed because pthread.h and some windows headers disagree on who owns the timespec struct.
    • #include “setpath_defs.h” and #include “turbine_setpath_fn.h” 
which are in the OS_COMMON folder.
Your solution to the problem will be a program that follows these instructions:
The main function
    1. Read the startup values from turbine_setup.txt, which includes grid startup values. There is a SAMPLE version of this in OS-common\Project basics\About sample files. This file should be copied to your Temp\coursein folder.
    2. Create a 2D global array of type float for each element of the grid for the current power values. 
    3. Create a 2D global array of type float for each element of the grid for the max values.
    4. Create a 2D global array of type (struct of 2 integers, m and n) one struct as a parameter for each turbine when it is started, to know its own position. The values of m and n are determined as you build the array in a loop.
    5. Read the initial values and max values for each turbine and insert the values into the 2D arrays you created. NOTE: the initial and max values can be different for each turbine. These initial and max values are contiguous sets of integers that you must read from a file.
    6. Create a 4th 2D global array of type pthread_t so you can use it in a loop to call pthread_create which starts the threads running. You CANNOT reuse a single pthread_t variable for ALL your threads.
    7. Wait for T ms (T is the value of TFARM_CYCLE_TIME and is specified in full seconds – you have to convert to milliseconds). Remember that the value of TFARM_CYCLE_TIME must be used as the initial value of float T. Because of incompatibilities in Sleep() vs sleep() between Linux and Windows, use MY time functions - found via #include “time_functions.h” which you must copy from my website. You should be able to use either millisleep or nanosleep.
    8. Output the current grid power values to the output file, (1st time will be the initial values) in row and column order followed by a line of 10 asterisks, then read a new demand value from the input, put the value in a global variable. When there are no demand values left, exit.
    9. Send a pthread_cond_broadcast signal to the generators to make them adjust their outputs. 
    10. Return to step ‎7.
Each generator function: The initial output of each generator is pre-defined in the inputs. 
    1. Wait for your condition variable to be signaled. When your turbine wakes up, use the new value of current demand. Compute the average of your own output from the PREVIOUS cycle and that of your north, east, south and west neighbors (distance 1 array entry) inside the grid. BE CAREFUL: use the values of M and N (passed to your thread from main) for your position in the grid, to determine if your generator is on the edge or corner of the grid. You might have fewer than 4 neighbors to average. Set your new output to 
[(sum of neighbors’ last values + your last value)/(#neighbors+1)] PLUS or MINUS the following percentage of your last value as specified below (this will gently increase/decrease the total grid output):
        a. if the computed average is below the current demand increase your output by 30% of YOUR last value. If this is > your max, set it at your max.
        b. if the computed average is above the current demand, decrease your output by 30% of YOUR last value. If this is < 0, set it to 0.
        c. if the computed average is = current demand, your new output will be the same as your last value.
        d. Set the value of your output in the position of your own generator in the array of current values.
    2. Inform main that you are done or wait on a barrier (see NOTES below).
    3. Wait for the next cycle.
While your thread is waiting, the main thread will copy the array of current values into the array of previous values, read a new demand value then wake up all the threads.
Initialization: Read the input file. It consists of m rows by n columns and looks like the sample below (the actual numbers will be different, but you can use these for testing). 
SAMPLE Input file layout: Notes:
    • ALL of these values will be different when we test your code.
    • the comments below are also in the file, so you have to skip over them. They might not contain the same words.

"maxvals"
110 120 130 140 150 
110 120 130 140 150 
110 120 130 140 150 
"current_vals" 
100 90 80 75 110 
100 90 80 75 110 
100 90 80 75 110 
"cycle-target-values"
110 120 90 80 95 90

The text in quotes will be there as well, so you need to skip past them.
NOTES & questions to guide your design:
    1. A good tutorial on pthreads can be found here: https://randu.org/tutorials/threads/ 
    2. Be sure you explicitly initialize your semaphores/condition variables.
    3. When waiting on condition variables, the wait should be inside a loop, not in a simple if statement because of spurious wakeups. You are not guaranteed that if a thread wakes up, it is the result of a signal or a broadcast call. Both kinds of operations are permissible in the same program. Does this program have that problem?
    4. How does main know if ALL threads have updated their values before it starts the next cycle? A counting semaphore or a barrier may be needed for main to wait on. Each thread could signal that semaphore or wait on the barrier before it waits for the next broadcast. Does this complicate the program? What happens if main is also waiting on the barrier? 
    5. How does each thread know when to actually do a return to main? 

