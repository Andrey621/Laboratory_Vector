#ifndef LAB_1_VECTOR_H
#define LAB_1_VECTOR_H

#include <stdio.h>
#include <complex.h>

typedef struct VectorN Vector;
struct VectorN
{
    size_t size;
    void* coordinates;

    void (*Create) (Vector* v, void* coordinates, size_t size, void (*AssignType)(Vector* v, void* coordinates, size_t size) );
    Vector* (*Summ)(Vector* v1, Vector* v2, Vector* (*SummType)(Vector*, Vector*) ); //векторное сложение
    Vector* (*ScalarProduct)(Vector* v1, Vector* v2, Vector* (*ScalarProductType)(Vector*, Vector*) ); //скалярное произведение
};

Vector* Vectorn();

void Create(Vector* v, void* coordinates, size_t size, void (*AssignType)(Vector* v, void* coordinates, size_t size));

Vector* Summ(Vector* v1, Vector* v2, Vector* (*SummType)(Vector*, Vector*) );
Vector* ScalarProduct(Vector* v1, Vector* v2, Vector* (*ScalarProductType)(Vector*, Vector*) );

void CreateIntArr(Vector* v, int* coordinates, size_t size);
void CreateComplexArr(Vector* v, double complex* coordinates, size_t size);

Vector* SummInt(Vector* v1, Vector* v2);
Vector* SummComplex(Vector* v1, Vector* v2);

Vector* ScalarProductInt(Vector* v1, Vector* v2);
Vector* ScalarProductComplex(Vector* v1, Vector* v2);

#endif //LAB_1_VECTOR_H
