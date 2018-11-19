# Single Thread Producer/Consumer
This assignment is a preliminary program to get you into using our remote Linux system and programming with both Linux and Windows.  The requirements for this program and ALL the programs up to the Linux-build assignment are:
1.	On Windows, you MUST use Visual Studio 2015 or later (free download) from http://Watson.onthehub.com .
2.	For Linux, you MUST use the either the TJW Linux virtual systems (ClefOS) with the pre-installed gcc or g++ OR the VMWare system (depending on which you were assigned.
3.	Your program MUST compile and run on BOTH of the above systems.
I.	The Assignment
A.	Create and run, a program (1 file), with multiple functions as follows: 
1	The main function will:
a	Open the input and output files (see notes below)
b	Start all timers with the "start_timing()" function.
c	Request the “mode” for the program to use. The input will be:
(1)	A “0” for the character-by-character mode (1st function below)
(2)	A “1” for the line-by-line mode (2nd function below)
(3)	call the function corresponding to the mode.
d	Stop timing using the "stop_timing() " function. 
e	Close the files.
f	Compute & display the times it took to read and write the total file.
(1)	wall clock difference (e.g.; double x=get_wall_clock_diff();   )
(2)	CPU clock difference (e.g.; int y= get_nanodiff();   ) 
You MUST use #include time_functions.h from my website to get platform independent functions for the values.
2	Function 1:
a	Reads a line of the file (one byte at a time), testing for "end of line" as it goes.
b	Write that line of the file to a NEW file on the same drive, one character at a time!
(Read a byte, then immediately write that byte – NO buffering of multiple bytes!)
c	Repeat the above to the end of the file.
3	Function 2 is similar to function 1, but instead of reading and writing character-by-character, it reads and writes a whole line of the file at a time, repeating this until the whole file has been processed.
B.	Compare the two results and explain the differences, if any.  If none, explain why.  
C.	Run both modes (UNCHANGED) on your Linux system.  Again, compare the times and explain the differences if any.  If none, explain why.  Use a word processing program to enter your answers and send them as a zipped file, with your source code and design, via FTP to the site specified in class.  
II.	The rules:
A.	No multi-threading or multi-processing functions allowed
B.	You will have to create the following directories and files using your own system facilities: 
1	Input:
a	For Windows: 	C:\temp\coursein\\p1-in.txt
b	For Linux: 	~/temp/coursein/p1-in.txt
2	Output:
a	For Windows: 	C:\temp\courseout\p1-out.txt
b	For Linux: 	~/temp/courseout/p1-out.txt
C.	Your program must use these names for the input and output files (they will be defined for you by the #include in the notes below):
1	infile
2	outfile
D.	You may use C-style (scanf()) functions or C++ (iostream) functions as long as they meet all requirements (must not ignore blanks or end-of-line characters).
E.	Use only the libraries available on both Windows and Linux (that is, do NOT use system-specific or vendor-specific interfaces such as those that have specifications for buffering or "read-ahead").
F.	No buffering defined in your program except the current character or line being processed.
G.	The input file must have AT LEAST 5000 lines of text, each being 80 characters wide (not including the line-end character(s)).  The file contains any of the printable characters (A-Z, a-z, 0-9, blank and punctuation symbols).  It may not contain any other data.  Each "line" of the file ends with a "system dependent" end of line signal.  Some systems use CR+LF, others use only LF, some use only CR, so you might need to know what your system uses.

Notes:

A.	My website contains 2 additional #include files: setpath_defs.h and setpath_fn.h for defining the paths noted above. The first of these belongs at the top of your file, following the normal #includes, such as "stdio.h". The 2nd one gets included at the very end of your program file. setpath_fn.h will add a function to your file that builds the path statements for you. All you have to do is invoke the function "setpath();" in "main" before you try to do any I/O and use the file names in setpath_defs.h.
B.	When compiling with Visual Studio on Windows, the VS program AUTOMATICALLY provides a 
#define WIN32 or _WIN32. Look inside my time_functions.h for more usage of the #ifdef.
C.	If you use iostream, you will need to use something other than >>  and << for the I/O.  If you check the definition, you'll find that >> ignores whitespace (blanks and linend symbols).  So, >> will read words and numbers into variables, but cannot read a "sentence" or “line”.  There are several functions that will do this in all of the acceptable languages. See this file: About linend.docx
D.	In the character mode version of the program, you must read ALL lines of the ENTIRE file.  The requirement is to read ONE character at a time, then write one character at a time. No strings or vectors holding them for writing.
E.	In the line-at-a-time version, you read an entire line (into a string or vector) and write the entire line at once, then read another whole line. Then repeat for the ENTIRE file, same as the other version. So you need to do a "fixed-length read" equal to the length of the line (not counting the line-end, unless your I/O method requires it).
F.	Don't start your timings until you start reading the file.  Your file must include spaces as part of the text, so it "looks" like words.  You may use any tools available to you to create the input file.  You should use another tool to verify that the output file is identical to the input.  On *X, you can use "cmp", "diff" or any other tool.  On Windows, you can use "comp" or “fc” in a command prompt window.

Remember that you must run the program UNCHANGED across platforms. 

What's the point of testing for end-of-line if the program writes character by character, including newline characters?

>> The instructions are worded to warn you that the linend information MUST be transferred as part of the data. This is critical if you are using certain C/C++ library functions that do not transfer spaces or linend data. Using a “binary” parameter or flag with some I/O functions that allow them, should prevent the problem. 

Also, be sure to properly handle the EOF or EOL conditions to prevent sending EXTRA “linend” or “EOF” characters, so the input and output will compare as equal. Be sure to test your output for this!!! 
