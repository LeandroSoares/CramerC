//
//  MatrixUtils.h
//  CramerEq
//
//  Created by Leandro Silva Soares on 21/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#ifndef MatrixUtils_h
#define MatrixUtils_h

#include <stdio.h>

#endif /* MatrixUtils_h */

float * newVector(int size);
float * vectorClone(float *vector, int size);
int vectorIsEqual(float*vector1,float*vector2,int size);
void printVector(float * vector, int size);

float ** newMatrix(int row,int coll);
void printMatrix(float ** matriz, int rows,int colls);
float ** matrixClone(float ** matrix, int rows,int colls);
float sumPrimDiag(float ** matrix, int size);
float sumSecDiag(float ** matrix, int size);