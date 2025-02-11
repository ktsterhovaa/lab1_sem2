#include <stdio.h>
#include <stdlib.h>
#include "field_info.h"
typedef struct{
    int real;
    int imag;

} Complex;

FieldInfo* GetComplexFieldInfo();

void complexSum(void* result,  const void* a, const void* b);

void complexPrint(const void* coef);

void complexMultiply(void* result, const void* a,  const void* b);

void complexMultiplyByScalar(void *result, const void *a, const void* sc);

void complexZeroMake( void *elem);

void comlexCompareElements(void *a, void *b, int res);