#include <stdio.h>
#include <math.h>

int main() {
	double l;
	scanf("%lf", &l);

	printf("%.9lf\n", l * l * (sqrt(3) / 4));

	return 0;
}
