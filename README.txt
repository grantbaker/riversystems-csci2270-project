# Baker_CSCI2270_FinalProject

******************
Grant Baker
github.com/grantbaker
CSCI 2270 Final Project
Updated 27 April 2016

******************
Project Summary:

This project models a river system as the time of year changes, storms occur, or cities consume water. It contains a tree of nodes, staring with the ocean and working upstream. Each node represents a station at which the flow of the river is monitored, and has an assigned "flow" value that corresponds to the flow of the river in cubic feet per second (cfs). Storms add flow to a particular station for one week, and cities take out a set amount of flow at a particular station. At each station which does not have an upstream station, it is considered a "source" and automatically generates a flow based on the time of year. When time progresses, it is possible to model and visualize how a true river system would react to changing conditions.


******************
How to Run:

Within the /RiverSystem/ directory, there is a number of ways to run the River Systems program:

 - PREFERRED METHOD: There is a makefile in the directory. Run the makefile in a terminal by typing "make clean" and "make". Then, to run the program, type "./RiverSystem <input file>". There is a sample input file provided, called "ColoradoSimple.txt". So:

        make clean
	make
	./RiverSystem ColoradoSimple.txt

 - There is an executable called RiverSystem, which runs on Linux systems. To execute, in a terminal in the directory, type "./RiverSystem <input file>". This is the latest compiled code; however, it may not work on all systems. Recompiling is the safest bet.

- There is a Code::Blocks project file. Open the project file in Code::Blocks and click the "build and run" button at the top.

- Compile the C++ code in another way of your choice, as long as the three files 'main.cpp', 'RiverGraph.cpp', and 'RiverGraph.h' are all built.

******************
Dependencies:

Only on provided C++ libraries. GCC, G++, and all the standard C++ compilers should be sufficient.

******************
System Requirements:

The executable will only run on Linux. If the source is compiled on Mac or Windows, it MIGHT run, although this has not been tested. Use at your own risk!

******************
Group Members:

Grant Baker

******************
Contributors:

A modified version of the makefile written by Prof. Fabio Somezi was used for this project.

******************
Open issues/bugs:

The program will break if it is given input is not expecting.