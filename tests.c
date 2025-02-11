#include "tests.h"


int testBasicIntPolynomialLogic()
{
        int response = 0;
        PolynomialCollection collection = {NULL, 0};
        //add to collection
        polynomialAddToCollection(&collection, "pol", GetIntFieldInfo());

        if (collection.size != 1)
        {
                printf("polynomialAddToCollection does not work!");
                response = -1;
        }
        //find in collection
        Polynomial *pol = polynomialFindInCollection(&collection, "pol");

        if (pol)
        {
                
        }
        else
        {
                printf("polynomialFindInCollection does not work!");
                response = -1;
        }
        int coefficent = 2;
        //push back
        polynomialPushBack(pol, &coefficent);
        if (pol->coefficents == NULL)
        {
                printf("polynomialPushBack does not work!");
                response = -1;
        }
        //sum polynomial
        polynomialAddToCollection(&collection, "p1", GetIntFieldInfo());
        Polynomial *p1 = polynomialFindInCollection(&collection, "p1");
        int p1Coef1 = 1;
        int p1Coef2 = 3;
        polynomialPushBack(p1, &p1Coef1);
        polynomialPushBack(p1, &p1Coef2);
        
        polynomialAddToCollection(&collection, "p2", GetIntFieldInfo());
        Polynomial *p2 = polynomialFindInCollection(&collection, "p2");
        int p2Coef1 = 2;
        int p2Coef2 = 5;
        polynomialPushBack(p2, &p2Coef1);
        polynomialPushBack(p2, &p2Coef2);

        polynomialAddToCollection(&collection, "res", GetIntFieldInfo());
        Polynomial *res = polynomialFindInCollection(&collection, "res");

        polynomialSum(res, p1, p2);

        polynomialAddToCollection(&collection, "checkSum", GetIntFieldInfo());
        Polynomial *checkSum = polynomialFindInCollection(&collection, "checkSum");
        int checkSumCoef1 = 3;
        int checkSumCoef2 = 8;
        polynomialPushBack(checkSum, &checkSumCoef1);
        polynomialPushBack(checkSum, &checkSumCoef2);

        int checkCorrectSum = polynomialCompare(res, checkSum);
        if (checkCorrectSum != 0)
        {
                printf("polynomialSum does not work!");
                response = -1;
        }

        //polynomial multiply
        polynomialAddToCollection(&collection, "resM", GetIntFieldInfo());
        Polynomial *resM= polynomialFindInCollection(&collection, "resM");
        int nullCoef = 0;
        polynomialPushBack(resM, &nullCoef);
        polynomialPushBack(resM, &nullCoef);
        polynomialPushBack(resM, &nullCoef);

        polynomialMultiply(res, p1, p2);

        polynomialAddToCollection(&collection, "checkMult", GetIntFieldInfo());
        Polynomial *checkMult = polynomialFindInCollection(&collection, "checkMult");
        int checkMultCoef1 = 2;
        int checkMultCoef2 = 11;
        int checkMultCoef3 = 5;
        polynomialPushBack(checkMult, &checkMultCoef1);
        polynomialPushBack(checkMult, &checkMultCoef2);
        polynomialPushBack(checkMult, &checkMultCoef3);

        int checkCorrectMult = polynomialCompare(resM, checkMult);
        if (checkCorrectMult != 0)
        {
                printf("polynomialMultiply does not work!");
                response = -1;
        }
        //multiply by a scalar

        int scalar = 4;
        polynomialAddToCollection(&collection, "resSc", GetIntFieldInfo());
        Polynomial *resSc = polynomialFindInCollection(&collection, "resSc");
        polynomialMultiplyByScalar(resSc, p1, &scalar);

        polynomialAddToCollection(&collection, "checkSc", GetIntFieldInfo());
        Polynomial *checkSc = polynomialFindInCollection(&collection, "checkSc");
        int checkScCoef1 = 4;
        int checkScCoef2 = 12;
        polynomialPushBack(checkSc, &checkScCoef1);
        polynomialPushBack(checkSc, &checkScCoef2);

        int checkCorrectSc = polynomialCompare(resSc, checkSc);
        if (checkCorrectSc != 0)
        {
                printf("polynomialMultiplyByScalar does not work!");
                response = -1;
        }

        //get value
        polynomialAddToCollection(&collection, "resVl", GetIntFieldInfo());
        Polynomial *resVl = polynomialFindInCollection(&collection, "resVl");
        int x = 2;
        polynomialGetValue(resVl, p1, x);

        polynomialAddToCollection(&collection, "checkVl", GetIntFieldInfo());
        Polynomial *checkVl = polynomialFindInCollection(&collection, "checkVl");
        int value = 7;
        polynomialPushBack(checkVl, &value);

        int checkCorrectVl = polynomialCompare(resVl,  checkVl);
        if (checkCorrectVl != 0)
        {
                printf("polynomialGetValue does not work!");
                response = -1;
        }

        // Освобождение ресурсов
        for (size_t i = 0; i < collection.size; i++)
        {
                polynomialFree(collection.polynomials[i].polynomial);
        }
        free(collection.polynomials);
        return response;
}


int testBasicComplexPolynomialLogic()
{
        int response = 0;
        PolynomialCollection collection = {NULL, 0};
        //add to collection
        polynomialAddToCollection(&collection, "pol", GetComplexFieldInfo());

        if (collection.size != 1)
        {
                printf("polynomialAddToCollection does not work!");
                response = -1;
        }
        //find in collection
        Polynomial *pol = polynomialFindInCollection(&collection, "pol");

        if (pol)
        {
                
        }
        else
        {
                printf("polynomialFindInCollection does not work!");
                response = -1;
        }
        Complex coefficent = {1, 2};
        //push back
        polynomialPushBack(pol, &coefficent);
        if (pol->coefficents == NULL)
        {
                printf("polynomialPushBack does not work!");
                response = -1;
        }
        //sum polynomial
        polynomialAddToCollection(&collection, "p1", GetComplexFieldInfo());
        Polynomial *p1 = polynomialFindInCollection(&collection, "p1");
        Complex p1Coef1 = {1, 2};
        Complex p1Coef2 = {3, 4};
        polynomialPushBack(p1, &p1Coef1);
        polynomialPushBack(p1, &p1Coef2);
        
        polynomialAddToCollection(&collection, "p2", GetComplexFieldInfo());
        Polynomial *p2 = polynomialFindInCollection(&collection, "p2");
        Complex p2Coef1 = {2, 3};
        Complex p2Coef2 = {4, 5};
        polynomialPushBack(p2, &p2Coef1);
        polynomialPushBack(p2, &p2Coef2);

        polynomialAddToCollection(&collection, "res", GetComplexFieldInfo());
        Polynomial *res = polynomialFindInCollection(&collection, "res");

        polynomialSum(res, p1, p2);

        polynomialAddToCollection(&collection, "checkSum", GetComplexFieldInfo());
        Polynomial *checkSum = polynomialFindInCollection(&collection, "checkSum");
        Complex checkSumCoef1 = {3, 5};
        Complex checkSumCoef2 = {7, 9};
        polynomialPushBack(checkSum, &checkSumCoef1);
        polynomialPushBack(checkSum, &checkSumCoef2);

        int checkCorrectSum = polynomialCompare(res, checkSum);
        if (checkCorrectSum != 0)
        {
                printf("polynomialSum does not work!");
                response = -1;
        }

        //polynomial multiply
        polynomialAddToCollection(&collection, "resM", GetComplexFieldInfo());
        Polynomial *resM= polynomialFindInCollection(&collection, "resM");
        Complex nullCoef = {0, 0};
        polynomialPushBack(resM, &nullCoef);
        polynomialPushBack(resM, &nullCoef);
        polynomialPushBack(resM, &nullCoef);

        polynomialMultiply(res, p1, p2);

        polynomialAddToCollection(&collection, "checkMult", GetComplexFieldInfo());
        Polynomial *checkMult = polynomialFindInCollection(&collection, "checkMult");
        Complex checkMultCoef1 = {-4, 7};
        Complex checkMultCoef2 = {-12, 30};
        Complex checkMultCoef3 = {-8, 31};
        polynomialPushBack(checkMult, &checkMultCoef1);
        polynomialPushBack(checkMult, &checkMultCoef2);
        polynomialPushBack(checkMult, &checkMultCoef3);

        int checkCorrectMult = polynomialCompare(resM, checkMult);
        if (checkCorrectMult != 0)
        {
                printf("polynomialMultiply does not work!");
                response = -1;
        }
        //multiply by a scalar

        int scalar = 4;
        polynomialAddToCollection(&collection, "resSc", GetComplexFieldInfo());
        Polynomial *resSc = polynomialFindInCollection(&collection, "resSc");
        polynomialMultiplyByScalar(resSc, p1, &scalar);

        polynomialAddToCollection(&collection, "checkSc", GetComplexFieldInfo());
        Polynomial *checkSc = polynomialFindInCollection(&collection, "checkSc");
        Complex checkScCoef1 = {4, 8};
        Complex checkScCoef2 = {12, 16};
        polynomialPushBack(checkSc, &checkScCoef1);
        polynomialPushBack(checkSc, &checkScCoef2);

        int checkCorrectSc = polynomialCompare(resSc, checkSc);
        if (checkCorrectSc != 0)
        {
                printf("polynomialMultiplyByScalar does not work!");
                response = -1;
        }

        

        // Освобождение ресурсов
        for (size_t i = 0; i < collection.size; i++)
        {
                polynomialFree(collection.polynomials[i].polynomial);
        }
        free(collection.polynomials);
        return response;
}