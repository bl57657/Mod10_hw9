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
#define FSIZE 81
/* Function Prototypes */
void Usage(char**info);
void ReadFile(char *dataFile, float num[]);
FILE *OpenCheckFile(char *dataFile2);
void WriteFile(FILE *dataFile3, float num2[]);
	FILE *OutF;
/* Main Program */
int main(int argc, char *argv[])
{
	float digits[FSIZE];  // declare variables
	char In[FSIZE];
	char Out[FSIZE]; 
	strcpy(In, argv[1]);
	strcpy(Out, argv[2]);
	if(argc != 3 || (strcmp(*(argv + 1), "--help") == 0))
	{
		Usage(argv); // call usage when 2 strings arent there or --help is the first string. 
	}
	ReadFile(In, digits);//store info, pass input file name & array
	OutF = OpenCheckFile(*(argv + 2));
	WriteFile(OutF, digits);
	return 0;
}
/* Function Defenitions */
void Usage(char**info)
{
	printf("Usage %s <dataFile> <outFileName>\n", *info);
	exit(1);
}
void ReadFile(char *dataFile1, float num[])
{
	FILE *InF;
	InF = fopen(dataFile1, "r");//opening file stream at position argv[1]
	if(InF != NULL)
	{
		printf("Not able to read file[%s]", dataFile1);
		printf("Check for errors!\n");
		exit(1);
	}
	int i = 0;
	printf("File read successful\n");
	while((fscanf(InF, "%f", &num[i++])) != EOF);
	fclose(InF);
	return;
}
FILE *OpenCheckFile(char *dataFile2)
{
	char ReturnF;
	FILE *OutF2;
	if((OutF2 = fopen(dataFile2, "r")) != NULL)
	{
		printf("[%s] File exits currently\n", dataFile2);
		printf("Do you wish to overwrite? (y/n)\n");
		scanf("%c", &ReturnF);
		if(ReturnF == 'n' || ReturnF == 'N')
		{
			exit(1);
		}
	}
	OutF2 = fopen(dataFile2, "w");
	if(OutF2 == NULL)
	{
		printf("Failed opening [%s]\n", dataFile2);
	}
	else
	{
		printf("[%s] has been written.\n", dataFile2);
	}
	return OutF2;
}	
void WriteFile(FILE *dataFile3, float num2[])
{
	char answer = 0;
	float avgnum, sumnum;
	if(answer == 'n' || answer == 'N')
	{
		printf("File will be preserved.\n");
		exit(1);
	}
	if(answer == 'y' || answer == 'Y')
	{
		for(int i = 0; i < FSIZE; i++)
		{
			fprintf(dataFile3, "%.4f\n", num2[i]);
			sumnum += num2[i];
		}
	avgnum = sumnum/FSIZE;
	fprintf(dataFile3, "----------\n");
	fprintf(dataFile3, "Total: %6.4f\n", sumnum);
	fprintf(dataFile3, "Average: %6.4f\n", avgnum);
//	printf("File written [%s]\n", OutF);
	}
	fclose(OutF);
	return;
}
