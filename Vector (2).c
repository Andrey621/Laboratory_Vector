#include "Vector.h"
#include <malloc.h>
#include <stdlib.h>

Vector* Vectorn()
{
    Vector* v = malloc(sizeof(Vector));
    v->Summ = &Summ;
    v->ScalarProduct = &ScalarProduct;
    v->Create = &Create;
    v->coordinates = NULL;
    v->size = 0;
    return v;
}

void Create(Vector* v, void* coordinates, size_t size, void (*CreateTypeArr)(Vector* v, void* coordinates, size_t size))
{
    CreateTypeArr(v, coordinates, size);
}
Vector* Summ(Vector* v1, Vector* v2, Vector* (*SummType)(Vector*, Vector*) )
{
    return SummType(v1, v2);
}
Vector* ScalarProduct(Vector* v1, Vector* v2, Vector* (*ScalarProductType)(Vector*, Vector*) )
{
    return ScalarProductType(v1, v2);
}
void CreateIntArr(Vector* v, int* coordinates, size_t size)
{
    v->coordinates = malloc(sizeof(int)*size);
    v->size = size;
    for (size_t i=0; i<size; ++i)
    {
        ((int*)v->coordinates)[i] = coordinates[i];
    }
}
void CreateComplexArr(Vector* v, double complex* coordinates, size_t size)
{
    v->coordinates = malloc(sizeof(double complex)*size);
    v->size = size;
    for (size_t i=0; i<size; ++i)
    {
        ((double complex*)v->coordinates)[i] = coordinates[i];
    }
}
Vector* SummInt(Vector* v1, Vector* v2)
{
    Vector* v = NULL;
    if (v1->size == v2->size && v1->size != 0)
    {
        v = Vectorn();
        v->coordinates = malloc(sizeof(int)*v1->size);
        v->size = v1->size;
        for (size_t i=0; i<v1->size; ++i)
        {
            int coordinat1 = ((int*)v1->coordinates)[i];
            int coordinat2 = ((int*)v2->coordinates)[i];
            ((int*)v->coordinates)[i] = coordinat1 + coordinat2;
        }
    }
    return v;
}
Vector* SummComplex(Vector* v1, Vector* v2)
{
    Vector* v = NULL;
    if (v1->size == v2->size && v1->size != 0)
    {
        v = Vectorn();
        v->coordinates = malloc(sizeof(double complex)*v1->size);
        v->size = v1->size;
        for (size_t i=0; i<v1->size; ++i)
        {
            double complex coord1 = ((double complex*)v1->coordinates)[i];
            double complex coord2 = ((double complex*)v2->coordinates)[i];
            ((double complex*)v->coordinates)[i] = coord1 + coord2;
        }
    }
    return v;
}
Vector* ScalarProductInt(Vector* v1, Vector* v2)
{
    Vector* v = NULL;
    if (v1->size == v2->size && v1->size != 0)
    {
        v = Vectorn();
        v->coordinates = malloc(sizeof(int)*v1->size);
        v->size = v1->size;
        for (size_t i=0; i<v1->size; ++i)
        {
            int coord1 = ((int*)v1->coordinates)[i];
            int coord2 = ((int*)v2->coordinates)[i];
            ((int*)v->coordinates)[i] = coord1 * coord2;
        }
    }
    return v;
}

Vector* ScalarProductComplex(Vector* v1, Vector* v2)
{
    Vector* v = NULL;
    if (v1->size == v2->size && v1->size != 0)
    {
        v = Vectorn();
        v->coordinates = malloc(sizeof(double complex)*v1->size);
        v->size = v1->size;
        for (size_t i=0; i<v1->size; ++i)
        {
            double complex coord1 = ((double complex*)v1->coordinates)[i];
            double complex coord2 = ((double complex*)v2->coordinates)[i];
            ((double complex*)v->coordinates)[i] = coord1 * coord2;
        }
    }
    return v;
}
