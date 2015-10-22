#include <stdio.h>
#include <math.h>

// jediny riadok zmeneny po pridani uhlu beta bol vypocet E

int uhol(float A, float B, float C, float a, float b, float c,
	float R, float r, float alpha, float beta, float *result1, float *result2);

int main(int argc, char** argv) {
	float res1, res2;
	int pocet = uhol(0, 0, 4,
		0, 0, 0,
		4, 1,
		0, 0,
		&res1, &res2);

	// convert to degrees
	res1 = res1 * 180.0f / M_PI;
	res2 = res2 * 180.0f / M_PI;
	printf("pocet rieseni = %d\n", pocet);
	printf("uhol1 = %f\n", res1);
	printf("uhol2 = %f\n", res2);
	return 0;
}

int uhol(float A, float B, float C, float a, float b, float c,
	float R, float r, float alpha, float beta, float *result1, float *result2) {
	/*
	uhol

	Arguments:
		(A, B, C) - coordinates of the upper point
		(a, b, c) - coordinates of the motor axis
		R - length of the upper bar
		r - length of the lower bar
		alpha - rotation (in radians) of the plane perpendicular to the motor axis
		beta - rotation (in radians) of the motor in plane zy (from z to y)
	Returns:
		result1, result2 - angles in radians
		int uhol - number of solutions. can be 0, 1 or 2
	*/
	float da = a - A, db = b - B, dc = c - C;

	float G = R * R - r * r - da * da - db * db - dc * dc;

	
	float D = 2 * r * (cos(alpha) * da + sin(alpha) * db);

	//float E = 2 * r * dc;  // (pripad ak beta = 0)
	float E = 2 * r * (
		sin(beta) * sin(alpha) * da + 
		sin(beta) * cos(alpha) * db + 
		cos(beta) * dc);

	float DE_norm = sqrt(D*D + E*E);

	D = D / DE_norm;
	E = E / DE_norm;
	G = G / DE_norm;

	float omega = atan2(D, E);

	if (-1 <= G && G <= 1) {
		*result1 = -omega + asin(G);
		*result2 = -omega + M_PI - asin(G);
		if (G == 1 || G == -1)
			return 1;
		else
			return 2;
	} else {
		return 0;
	}
}