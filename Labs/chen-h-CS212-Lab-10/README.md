==============================================================================
Project Title: CS212 – Lab 10 – infix expression calculator
	Note: files are separated (see included files for summary) and no files are "unnecessary"
=================================================================================
Included files: (I used 2 queues and 2 stacks)
	main.c: This contains the main() 
	
	Lab10Functions.c  : contains the inFixToPostFix / PostFix evaluation functions 
	queueFunctions.c  : contains functions for queue number 1
	queueFunctions2.c : contains functions for queue number 2
	stackFunctions.c  : contains functions for stack number 1
	stackFunctions2.c : contains functions for stack number 1

	Lab10Functions.h  : prototypes for Lab10Functions
	queue.h		  : struct definition for queue
	queueFunctions.h  : prototypes for queue number 1
	queueFunctions2.h : prototypes for queue number 2
	stack.h           : struct of type char for stacks
	stack2.h          : struct of type int for stacks(used for post fix evaluation)
	stackFunctions.h  : prototypes for stack number 1
	stackFunctions2.h : prototypes for stack number 2
=================================================================================
Running the program: 

	On linux system:
	------------------------------------------
	TO COMPILE: gcc -o main main.c Lab10Functions.c queueFunctions.c queueFunctions2.c stackFunctions.c stackFunctions2.c
	TO RUN:     ./main

	on windows:
	------------------------------------------
	TO COMPILE: cl main.c Lab10Functions.c queueFunctions.c queueFunctions2.c stackFunctions.c stackFunctions2.c
	TO RUN:     main

