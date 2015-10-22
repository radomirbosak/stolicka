Stolicka
========

A `C` and `python` implementation of a solution of a simple [inverse kinematics problem](https://en.wikipedia.org/wiki/Inverse_kinematics). The mechanical system considered is a robot arm consisting of 2 metal bars of fixed length, joined together with a free joint (with 2 degrees of freedom). The free end of the lower bar is rotated by a motor. The problem is to find the angle of the lower bar to the ground, when given the position of the upper bar's free end (position of the free end of the lower bar is assumed to be (0, 0, 0)).

More detailed decription of the problem and its solution is in the [pdf file](popis.pdf) (in slovak).

Uses: C (math.h), Python (built-in math functions)