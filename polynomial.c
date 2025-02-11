#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polynomial.h"
#include <string.h>
#include "field_info.h"
Polynomial* polynomialInit(FieldInfo* typeInfo)
{
    Polynomial* polynomial = (Polynomial*)malloc(sizeof(Polynomial));
    polynomial->typeInfo = typeInfo;
    polynomial->coefficents = NULL;
    polynomial->size = 0;
    
    return polynomial;
}

void polynomialPrintElements(const Polynomial *polynomial)
{
    for (int i = 0; i < polynomial->size; i++)
    {
        if (i==polynomial->size-1)
        {
            polynomial->typeInfo->printElements((const char *)polynomial->coefficents + i * polynomial->typeInfo->elementSize);
            printf("x^%d", i);
        }
        else
        {
            polynomial->typeInfo->printElements((const char *)polynomial->coefficents + i * polynomial->typeInfo->elementSize);
            printf("x^%d + ", i);
        }
        
    }


}

void polynomialAddToCollection(PolynomialCollection *collection, const char *name, FieldInfo* typeInfo)
{
    collection->polynomials = realloc(collection->polynomials, (collection->size + 1) * sizeof(NamedPolynomial));
    NamedPolynomial *newPolynomial = &collection->polynomials[collection->size];
    strncpy(newPolynomial->name, name, sizeof(newPolynomial->name));

    newPolynomial->polynomial = polynomialInit(typeInfo);
    collection->size++;


}
Polynomial *polynomialFindInCollection(PolynomialCollection *collection, const char *name)
{
    for (size_t i = 0; i < collection->size; i++)
    {
        if (strcmp(collection->polynomials[i].name, name) == 0)
        {
            return collection->polynomials[i].polynomial;
        }
    }
    
    return NULL;
}

void polynomialFree(Polynomial *polynomial)
{
    free(polynomial->coefficents);
    polynomial->coefficents = NULL;
    polynomial->size = 0;
    polynomial->typeInfo->elementSize = 0;
}
void polynomialPushBack(Polynomial *polynomial, const void *coefficent)
{
    
    polynomial->coefficents = realloc(polynomial->coefficents, (polynomial->size + 1) * polynomial->typeInfo->elementSize);
    memcpy((char *)polynomial->coefficents + polynomial->size * polynomial->typeInfo->elementSize, coefficent, polynomial->typeInfo->elementSize);
    polynomial->size++;
    

}
void polynomialSum(Polynomial *res, const Polynomial *p1, const Polynomial *p2)
{
    void *tempResult = malloc(p1->typeInfo->elementSize);
    if (tempResult == NULL){
        printf("memory allocation error");
        return;
    }
    int i;
    if (p1->size == p2->size)
    {
        for (i = 0; i < p1->size; i++)
        {
            void *coef1 =  (char *)p1->coefficents + i * p1->typeInfo->elementSize;
            void *coef2 =  (char *)p2->coefficents + i * p2->typeInfo->elementSize;

            p1->typeInfo->sumElements(tempResult, coef1, coef2);

            polynomialPushBack(res, tempResult);
        
        }
    }
    else if (p1->size < p2->size)
    {
        for (i = 0; i < p1->size; i++)
        {
            void *coef1 =  (char *)p1->coefficents + i * p1->typeInfo->elementSize;
            void *coef2 =  (char *)p2->coefficents + i * p2->typeInfo->elementSize;

            p1->typeInfo->sumElements(tempResult, coef1, coef2);

            polynomialPushBack(res, tempResult);
        }
        for (i = p1->size; i < p2->size; i++)
        {
            polynomialPushBack(res, (char *)p2->coefficents + i * p2->typeInfo->elementSize);
        }
    }
    else
    {
        for (i = 0; i < p2->size; i++)
        {
            void *coef1 =  (char *)p1->coefficents + i * p1->typeInfo->elementSize;
            void *coef2 =  (char *)p2->coefficents + i * p2->typeInfo->elementSize;

            p1->typeInfo->sumElements(tempResult, coef1, coef2);

            polynomialPushBack(res, tempResult);
        }
        for (i = p2->size; i < p1->size; i++)
        {
            polynomialPushBack(res, (char *)p1->coefficents + i * p1->typeInfo->elementSize);
        }
    }
    
    free(tempResult);

}

void polynomialMultiply(Polynomial *res, const Polynomial *p1, const Polynomial *p2)
{
    
    for (int i = 0; i < p1->size; i++)
    {
        for(int j = 0; j < p2->size; j++)
        {
            
            void *coef1 = (char *)p1->coefficents + i * p1->typeInfo->elementSize;
            void *coef2 = (char *)p2->coefficents + j * p2->typeInfo->elementSize;
            
            void *tempResult = malloc(p1->typeInfo->elementSize);
            if (tempResult == NULL)
            {
            printf("memory allocation error");
            return;
            }

            p1->typeInfo->multiplyElements(tempResult, coef1, coef2);

            int power = i + j;
            
            
            void *resCoef = (char *)res->coefficents + (power * res->typeInfo->elementSize);
            res->typeInfo->sumElements(resCoef, resCoef, tempResult);
            
            free(tempResult);
        }

    }
   
}

void polynomialMultiplyByScalar(Polynomial *res, const Polynomial *p, const void *scalar)
{
    void *tempResult = malloc(p->typeInfo->elementSize);
    if (tempResult == NULL)
    {
        printf("memory allocation error");
        return;
    }
    for (int i = 0; i < p->size; i++)
    {
        void *coef = (char *)p->coefficents + i * p->typeInfo->elementSize;
        p->typeInfo->multiplyScalarElements(tempResult, coef, scalar);
        polynomialPushBack(res, tempResult);
    }
    free(tempResult);
}
void *polynomialGetValue(Polynomial *res, const Polynomial *p, int x)
{
    
    void *value = malloc(p->typeInfo->elementSize);
    
    p->typeInfo->makeZeroElement(value);
   
    for (int i = 0; i < p->size; i++)
    {
        void *coef = (char *)p->coefficents + i * p->typeInfo->elementSize;
        void *tempResult = malloc(p->typeInfo->elementSize);
        int xPower = pow(x, i);
        p->typeInfo->multiplyScalarElements(tempResult, coef, &xPower);
        p->typeInfo->sumElements(value, value, tempResult);
       
    }
    p->typeInfo->printElements(value);
    polynomialPushBack(res, value);
    return value;
}
int polynomialCompare(Polynomial *p1, Polynomial *p2)
{
    
    for (int i = 0; i < p1->size; i++)
    {
        void *coef1 = (char *)p1->coefficents + i * p1->typeInfo->elementSize;
        void *coef2 = (char *)p2->coefficents + i * p2->typeInfo->elementSize;
        int res = 0;
        p1->typeInfo->compareElements(coef1, coef2, res);
        if (res != 0)
        {
            return -1;
        }

    }
    return 0;
    
}
