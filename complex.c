#include "complex.h"
#include <stdio.h>
#include <stdlib.h>
#include "field_info.h"

static FieldInfo* COMPLEX_FIELD_INFO = NULL;

FieldInfo* GetComplexFieldInfo()
{
    if (COMPLEX_FIELD_INFO == NULL)
    {
        COMPLEX_FIELD_INFO = (FieldInfo*)malloc(sizeof(FieldInfo));
        COMPLEX_FIELD_INFO->typeName = "Complex";
        COMPLEX_FIELD_INFO->elementSize = sizeof(Complex);
        COMPLEX_FIELD_INFO->sumElements = complexSum;
        COMPLEX_FIELD_INFO->printElements = complexPrint;
        COMPLEX_FIELD_INFO->multiplyElements = complexMultiply;
        COMPLEX_FIELD_INFO->multiplyScalarElements = complexMultiplyByScalar;
        COMPLEX_FIELD_INFO->makeZeroElement = complexZeroMake;
        COMPLEX_FIELD_INFO->compareElements = comlexCompareElements;
    
    }

    return COMPLEX_FIELD_INFO;
}


void complexSum(void* result, const void* a, const void* b) {
    ((Complex*)result)->real = ((Complex*)a)->real + ((Complex*)b)->real;
    ((Complex*)result)->imag = ((Complex*)a)->imag + ((Complex*)b)->imag;
}

void complexPrint(const void* coef) {
    const Complex* complexElem = (const Complex*)coef;
    printf("(%d + %di)", complexElem->real, complexElem->imag);
}

void complexMultiply(void* result,  const void* a, const void* b){
    ((Complex*)result)->real = ((Complex*)a)->real * ((Complex*)b)->real - ((Complex*)a)->imag * ((Complex*)b)->imag;
    ((Complex*)result)->imag = ((Complex*)a)->real * ((Complex*)b)->imag + ((Complex*)a)->imag * ((Complex*)b)->real;
}
void complexMultiplyByScalar(void *result, const void *a, const void* sc){
    ((Complex*)result)->real = ((Complex*)a)->real * (*(int*) sc);
    ((Complex*)result)->imag = ((Complex*)a)->imag * (*(int*) sc);
}
void complexZeroMake( void *elem){
    Complex* complexElem = (Complex *)elem;
    ((Complex*)complexElem)->real = 0;
    ((Complex*)complexElem)->imag = 0;
}
void comlexCompareElements(void *a, void *b, int res)
{
    if ((((Complex*)a)->real != ((Complex*)b)->real) && (((Complex*)a)->imag != ((Complex*)b)->imag))
    {
        res = -1;
    }   
}