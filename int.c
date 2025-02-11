#include <stdio.h>
#include <stdlib.h>
#include "int.h"
#include "field_info.h"

static FieldInfo* INT_FIELD_INFO = NULL;
FieldInfo* GetIntFieldInfo() {
    if (INT_FIELD_INFO == NULL)
    {
        INT_FIELD_INFO = (FieldInfo*)malloc(sizeof(FieldInfo));
        INT_FIELD_INFO->typeName = "int";
        INT_FIELD_INFO->elementSize = sizeof(int);
        INT_FIELD_INFO->sumElements = intSum;
        INT_FIELD_INFO->printElements = intPrint;
        INT_FIELD_INFO->multiplyElements = intMultiply;
        INT_FIELD_INFO->multiplyScalarElements  = intMultiplyByScalar;
        INT_FIELD_INFO->makeZeroElement = intZeroMake;
        INT_FIELD_INFO->compareElements = intCompareElements;
    }
    return INT_FIELD_INFO;

}

void intSum(void* result,  const void* a,  const void* b) {
        *(int*) result = *(int*) a + *(int*) b;
}

void intPrint(const void* coef) {

    printf("%d", (*(const int*)coef));
    
}

void intMultiply(void* result, const void* a,  const void* b) {
    *(int*) result = (*(int*) a) * (*(int*) b);
}

void intMultiplyByScalar(void *result, const void *a, const void *sc){
    *(int*) result = (*(int*) a) * (*(int*) sc); 
}

void intZeroMake(void *elem)
{
    *(int *)elem = 0;
}

void intCompareElements(void *a, void *b, int res)
{
    if ((*(int*)a) != (*(int*)b))
    {
        res = -1;
    }
}