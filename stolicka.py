#!/usr/bin/env python3
# -*- coding: utf-8 -*-

from math import pi, atan2, degrees, radians, sin, cos, asin, acos, sqrt

# suradnice na stolicke
A, B, C = 0, 0, 5

# suradnice osi motora
a, b, c = 0, 0, 0

# dlzka hornej tyce
R = 4

# dlzka dolnej tyce
r = 3

# natocenie motora na podlahe (rovnica xy)
alpha = radians(0)

# vypocet
da, db, dc = a - A, b - B, c - C

G = R*R - r*r - da*da - db*db - dc*dc
D = 2 * r * (cos(alpha) * da + sin(alpha) * db)
E = 2 * r * (sin(beta) * sin(alpha) * da + sin(beta) * cos(alpha) * db + cos(beta) * dc)

# teraz riesime $$ cos(phi) * D + sin(phi) * E = G $$

DE_norm = sqrt(D*D + E*E)

D = D / DE_norm
E = E / DE_norm
G = G / DE_norm

omega = atan2(D, E)

#assert(sin(omega) == D)
#assert(cos(omega) == E)

if -1 <= G <= 1:
	phi_1 = degrees(-omega + asin(G))
	phi_2 = degrees(-omega + pi - asin(G))

	print(phi_1, phi_2)
else:
	print("nemá riešenie")