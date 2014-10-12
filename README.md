simple-n-body
=============

A simple N-body solving program with different integrators to choose from.
testsystem.txt is a simple Sun-Earth-Moon system to test the program with. The program must be executed from a command line and produces a .txt file with positions of all the bodies in this format:

Name x y z Name x y z ...
Name x y z Name x y z ...
Name x y z Name x y z ...
...

where each new line is a new timestep.

e.g.
Sun 1.12455e-10 3.5116e-15 0 Earth 0.999963 0.00865021 0 Moon 1.00025 0.0112031 0 
Sun 1.01206e-09 7.81338e-12 0 Earth 0.999667 0.0259493 0 Moon 1.00052 0.028366 0 
Sun 2.81097e-09 3.89936e-11 0 Earth 0.999076 0.0432423 0 Moon 1.00044 0.0453928 0 
Sun 5.50863e-09 1.09096e-10 0 Earth 0.99819 0.0605239 0 Moon 1 0.0622909 0 

This file can then be plotted with e.g. gnuplot.
-----
Currently implemented integrators:
1st order Euler
Leap-frog
