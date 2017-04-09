/*
 * =====================================================================================
 *
 *       Filename:  Buffalos_HW9_Task1.c
 *       	Usage:  ./Buffalos_HW9_Task1.c
 *    Description: Task 1 read input file, create output file
 *
 *        Version:  1.0
 *        Created:  04/06/2017 03:27:00 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Tysen Bair (), tysenbair@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>
#include <string.h>
#define FSIZE 12
/* Function Prototypes */
void Usage(char**info);
void ReadFile(char dataFile, float num[]);
//void OpenCheckFile(char dataFile);
//void WriteFile(FILE sourceFile, float num[]);
/* Main Program */
int main(int argc, char *argv[])
{
	char returnF[FSIZE];
	//float num[];

	if(argc != 3)
	{
		Usage(argv);
	}
	else if(argc > 1 && strcmp(argv[2], "--help") == 0)
	{
		Usage(argv); 
	}
	strcpy(returnF, argv[1]);
	
	return 0;
}
/* Function Defenitions */
void Usage(char**info)
{
	printf("Usage %s <dataFile> <outFileName>\n", *info);
	exit(1);
}
ReadFile(char dataFile, float num[])
{
	FILE *gayfile;
	gayfile =fopen(dataFile);
	// fscanf ( file name, type your transfer ex. %f, were)
	fscanf(gayfile, "%f", &num[]);

	fclose(gayfile);
	return;
}

