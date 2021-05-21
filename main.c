#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <complex.h>
#include "Vector.h"

int main()
{
    Vector* vec1Int = Vectorn();
    Vector* vec2Int = Vectorn();
    Vector* vec1Complex = Vectorn();
    Vector* vec2Complex = Vectorn();
    int Int1[5] = {20, -9, 9, 9, 10};
    int Int2[5] = {10, 10, 0, 10, 12};
    double complex Complex1[2] = {19 + 3 * I, 7 + 9 * I};
    double complex Complex2[2] = {4.5 + 18 * I, 8 + 10.25 * I};
    vec1Int->Create(vec1Int, Int1, 4, &CreateIntArr);
    vec2Int->Create(vec2Int, Int2, 4, &CreateIntArr);
    vec1Complex->Create(vec1Complex, Complex1, 2, &CreateComplexArr);
    vec2Complex->Create(vec2Complex, Complex2, 2, &CreateComplexArr);

    //векторное сложение

    Vector* vecSumm = Vectorn();
    vecSumm = vecSumm->Summ(vec1Int, vec2Int, &SummInt);
    printf("\nВекторное сложение целочисленных векторов\nvec1 = {");
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", ((int*)vec1Int->coordinates)[i]);
    }
    printf("}\nvec2 = {");
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", ((int*)vec2Int->coordinates)[i]);
    }
    printf("}\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d + %d = %d\n", ((int*)vec1Int->coordinates)[i], ((int*)vec2Int->coordinates)[i], ((int*)vecSumm->coordinates)[i] );
    }
    printf("\nВекторное сложение комплексных векторов\n");
    printf("vec1complex = {");
    for (size_t i = 0; i < 2; i++)
    {
        printf("%g + ", creal(((double complex*)vec1Complex->coordinates)[i]));
        printf("%gi ", cimag(((double complex*)vec1Complex->coordinates)[i]));
    }
    printf("}\nvec2Complex = {");
    for (size_t i = 0; i < 2; i++)
    {
         printf("%g + ", creal(((double complex*)vec2Complex->coordinates)[i]));
        printf("%gi ", cimag(((double complex*)vec2Complex->coordinates)[i]));
    }
    printf("}\n");

    vecSumm = vecSumm->Summ(vec1Complex, vec2Complex, &SummComplex);
    for (int i = 0; i < 2; ++i)
    {
        printf("%g + ", creal(((double complex*)vecSumm->coordinates)[i]) );
        printf("%gi\n", cimag(((double complex*)vecSumm->coordinates)[i]) );

    }

    //скалярное произведение

    Vector* vecScalarProduct = Vectorn();
    printf("\nСкалярное произведение целочисленных векторов\n");
    vecScalarProduct = vecScalarProduct->ScalarProduct(vec1Int, vec2Int, &ScalarProductInt);
    printf("vec1 = {");
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", ((int*)vec1Int->coordinates)[i]);
    }
    printf("}\nvec2 = {");
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d ", ((int*)vec2Int->coordinates)[i]);
    }
    printf("}\n");
    for (int i = 0; i < 5; ++i)
    {
        printf("%d * %d = %d\n", ((int*)vec1Int->coordinates)[i], ((int*)vec2Int->coordinates)[i], ((int*)vecScalarProduct->coordinates)[i]);
    }

    printf("\nСкалярное произведение комплексных векторов\n");
    printf("vec1complex = {");
    for (size_t i = 0; i < 2; i++)
    {
        printf("%g + ", creal(((double complex*)vec1Complex->coordinates)[i]));
        printf("%gi ", cimag(((double complex*)vec1Complex->coordinates)[i]));
    }
    printf("}\nvec2Complex = {");
    for (size_t i = 0; i < 2; i++)
    {
         printf("%g + ", creal(((double complex*)vec2Complex->coordinates)[i]));
        printf("%gi ", cimag(((double complex*)vec2Complex->coordinates)[i]));
    }
    printf("}\n");
    vecScalarProduct = vecScalarProduct->ScalarProduct(vec1Complex, vec2Complex, &ScalarProductComplex);
    for (int i = 0; i < 2; ++i)
    {
        printf("%g + ", creal(((double complex*)vecScalarProduct->coordinates)[i]) );
        printf("%gi\n", cimag(((double complex*)vecScalarProduct->coordinates)[i]) );
    }
}
