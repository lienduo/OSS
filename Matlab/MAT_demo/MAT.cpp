// MAT.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "mat.h"
#include "matlab.h"

#pragma comment(lib, "libmat.lib")
#pragma comment(lib, "libmx.lib")
#pragma comment(lib, "libmatlb.lib")
#pragma comment(lib, "libmmfile.lib")

void main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("\nUsage: mat <matfile>\nwhere <matfile> is the name of "
			"the MAT-file to be read.\n");
		return;
	}
	
	MATFile *pmat;
	const char* name=NULL;
	mxArray *pa;
	
	/* open mat file and read it's content */
	pmat = matOpen(argv[1], "r");
	if (pmat == NULL) 
	{
		printf("Error Opening File: \"%s\"\n", argv[1]);
		return;
	}
	
	/* Read in each array. */
	pa = matGetNextVariable(pmat, &name);
	while (pa!=NULL)
	{
		/*
		* Diagnose array pa
		*/
		printf("\nArray %s has %d dimensions.", name, mxGetNumberOfDimensions(pa));
		
		//print matrix elements
		mlfPrintMatrix(pa);
		
		//get next variable
		pa = matGetNextVariable(pmat,&name);
				
		//destroy allocated matrix
		mxDestroyArray(pa);
	}
	
	matClose(pmat);

	//now create a new mat-file and save some variable/matrix in it
	double dbl1[]={1.1, 4.3, -1.6, -4, -2.75};
	double dbl2[]={-4.9, 2.3, -5};
	mxArray *AA, *BB, *CC;

	AA=mxCreateDoubleMatrix(1, 5, mxREAL);
	BB=mxCreateDoubleMatrix(1, 3, mxREAL);

	//copy an array to matrix A and B
	memcpy(mxGetPr(AA), dbl1, 5 * sizeof(double));
	memcpy(mxGetPr(BB), dbl2, 3 * sizeof(double));


	CC=mlfConv(AA, BB);		//convolution
	mlfPrintMatrix(AA);
	mlfPrintMatrix(BB);
	mlfPrintMatrix(CC);

	//opening TestVar.mat for writing new data
	pmat=matOpen("TestVar.mat", "w");
	matPutVariable(pmat, "AA", AA);
	matPutVariable(pmat, "BB", BB);
	matPutVariable(pmat, "CC", CC);
	matClose(pmat);
	
	mxDestroyArray(AA);
	mxDestroyArray(BB);
	mxDestroyArray(CC);
}
