#include <stdio.h>
#include <stdlib.h>
#include "field_info.h"



typedef struct {
    void *coefficents; // указатель на элементы
    int size; // количество элементов на данный момент
    FieldInfo* typeInfo;
    

} Polynomial;

typedef struct {
    char name[20]; //имя полинома
    Polynomial *polynomial; // сам полином

} NamedPolynomial;

typedef struct{
    NamedPolynomial *polynomials; // динамический массив именованных полиномов
    size_t size; // количество полиномов

} PolynomialCollection;
Polynomial *polynomialInit(FieldInfo* typeInfo);

void polynomialPrintElements (const Polynomial *polynomial);

void polynomialAddToCollection(PolynomialCollection *collection, const char *name, FieldInfo* typeInfo);

Polynomial *polynomialFindInCollection(PolynomialCollection *collection, const char *name);

void polynomialFree(Polynomial *polynomial);

void polynomialPushBack(Polynomial *polynomial, const void *coefficent);

void polynomialSum(Polynomial *res, const Polynomial *p1, const Polynomial *p2);

void polynomialMultiply(Polynomial *res, const Polynomial *p1, const Polynomial *p2);

void polynomialMultiplyByScalar(Polynomial *res, const Polynomial *p, const void *scalar);

void *polynomialGetValue(Polynomial *res, const Polynomial *p, int x);

int polynomialCompare(Polynomial *p1, Polynomial *p2);