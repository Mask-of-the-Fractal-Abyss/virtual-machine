# virtual-machine

This is a proof of concept assembly language in which the program counter has acceleration and velocity as well as a position, in 3D space.

Though I have not (and probably won't ever) written anything in the assembly language (beyond basic tests of functionality), there are some neat concepts that come packaged with this concept.

Firstly, the velocity of the program counter already acts as a conditional jump, so no explicit conditional jump instruction is nessecary to make this turing complete.
I'm not sure it is turing complete, but from a cursory overview, it looks like it probably is.

Secondly, a potential application of polymorphism in this language is very interesting.
Essentially, putting sections of code in specific locations based on the factors of the locations of other instructions.

This is easily accomplished using velocity (and potentially acceleration)
If the program counter's velocity is 10 (in some 1 dimensional equivalent language), then it will read every 10th instruction.

Essentially, some base, abstract class runs every Xth instruction, and anything that inherits from it, runs every Yth instruction, where Y is some number that evenly divides into (or maybe not quite! (in order to omit certain functionality)) X.

For a more concrete example:
The Animal class has functionality on lines 0, 10, 20, 30, and 40.
The Cat class sets the program counter's location to 0, and its velocity to 5.
For the Cat class, lines 0, 5, 10, 15, 20, 25, 30, 35, and 40 will be executed.  Any base functionality that applies to all animals would be written every 10th line, and functionality unique to the Cat would be written on 5, 15, 25, and 35.
A Dog class might have functionality every 2nd line.

It's clear this would be very efficient in terms of memory, because large gaps of memory that don't have useful factors would be less valuable.

Maybe something I will add in the future, is some form of "planetary body" which applies a constant acceleration or velocity in a certain direction, which could act like some sort of global register.
