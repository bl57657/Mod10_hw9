/*
 * =====================================================================================
 *
 *       Filename:  Buffalos_HW9_Task2.c
 *       	Usage:  ./Buffalos_HW9_Task2.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/2017 03:27:13 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Tysen Bair (), tysenbair@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>

#define FILEOPEN "zone1.txt"
/* Function Prototypes */

/* Main Program */
int main(int argc, char *argv[])
{
	int count = 0;
	double y, x, f, l, sx=0, sy=0, sx2=0, sxy=0, m, denomin, b;
	FILE *zone;

	zone = fopen(FILEOPEN,"r");
		if(zone == NULL)
		{
			printf(" Cannot Read file/ File Missing.\n");
		}
		else 
		{
			while((fscanf(zone,"%lf %lf",&x,&y)) == 2)
			{
				++count;
				if(count == 1) f=x;
				sx += x; sy += y; sx2 += x*x; sxy += x*y;
			}
			l = x;
		denomin = sx*sx - count*sx2;
		      m = (sx*sy - count*sxy)/denomin;
			  b = (sx*sxy - sx2*sy)/denomin;
			
		printf("Altitude range (km): \n");
		printf("%.2f to %.2f \n\n",f,l);
		printf("Linear Model: \n");
		printf("ozone mixture = %.2f altitude + %.2f \n",m,b);

		fclose(zone);

		}
	return 0;
}


/* Function Defenitions */


