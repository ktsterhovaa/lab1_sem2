#include <stdio.h>
#include "field_info.h"

void intSum(void* result, const void* a, const void* b);

void intPrint(const void* coef);

void intMultiply(void* result,  const void*a,  const void*b);

void intMultiplyByScalar(void *result, const void *a, const void *sc);

FieldInfo* GetIntFieldInfo();

void intZeroMake(void *elem);

void intCompareElements(void *a, void *b, int res);