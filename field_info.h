#include <stdio.h>
#include <stdlib.h>
#ifndef FIELD_INFO_H
#define FIELD_INFO_H
typedef void (*SumPolynomialElements) (void* , const void*, const void*);
typedef void (*PrintPolynomialElements) (const void* el);
typedef void (*MultiplyPolynomialElements) (void* , const void*, const void*);
typedef void (*MultiplyPolynomialByScalarElements)(void* , const void*, const void*);
typedef void (*MakeZero) (void* el);
typedef void (*CompareElements)(void *, void *, int);
typedef struct FieldInfo {
    const char* typeName;
    size_t elementSize;
    SumPolynomialElements sumElements;
    PrintPolynomialElements printElements;
    MultiplyPolynomialElements multiplyElements;
    MultiplyPolynomialByScalarElements multiplyScalarElements;
    MakeZero makeZeroElement;
    CompareElements compareElements;
} FieldInfo;


#endif