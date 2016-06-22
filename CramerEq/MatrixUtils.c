//
//  MatrixUtils.c
//  CramerEq
//
//  Created by Leandro Silva Soares on 21/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#include "MatrixUtils.h"
#include <stdlib.h>

float * newVector(int size){
    float * vector = (float *)malloc(sizeof(float)*size);
    return vector;
}

float * vectorClone(float *vector, int size){
    float *V = newVector(size);
    int i=0;
    for (;i < size ; i++) {
        V[i]=vector[i];
    }
    return V;
}

int vectorIsEqual(float*vector1,float*vector2,int size){
    int equal=1;
    int i=0;
    for (; i<size; i++) {
        if(vector1[i] != vector2[i]){
            equal=0;
            break;
        }
    }
    return equal;
}

void printVector(float * vector, int size){
    printf("[");
    int i=0;
    for (;i<size ; i++) {
        printf("%.2f", vector[i]);
        if (i!=size-1) {
            printf(",");
        }
    }
    printf("]\n");
}

float ** newMatrix(int row, int coll) {
    float **M = (float **)malloc(sizeof(float *) * row);
    int i=0;
    for (; i<row; i++) {
        M[i] = newVector(coll);
    }
    return M;
}

float ** matrixClone(float ** matrix, int rows,int colls) {
    float **M = newMatrix(rows, colls);
    int i=0;
    for (;i<rows ; i++) {
        M[i] = vectorClone(matrix[i], colls);
    }
    return M;
}

float sumPrimDiag(float ** matrix, int size) {
    float sum=1;
    int i=0;
    for (;i<size ; i++) {
        int j=0;
        for (; j<size; j++) {
            if(i-j==0) {
                sum+=matrix[i][j];
            }
        }
    }
    return  sum;
}

float sumSecDiag(float ** matrix, int size) {
    float sum=1;
    int i=0;
    for (;i<size ; i++) {
        int j=0;
        for (; j<size; j++) {
            if(i+j==size-1) {
                sum*=matrix[i][j];
            }
        }
    }
    return  sum;
}

int matrixIsEqual(float**matrix1, float**matrix2, int rows, int colls) {
    int equal=1;
    int i=0;
    for (; i<rows; i++) {
        if(vectorIsEqual(matrix1[i],matrix2[i],colls)){
            equal=0;
            break;
        }
    }
    return equal;
}

void printMatrix(float ** matriz, int rows,int colls){
    int i=0;
    for (;i<rows ; i++) {
        printVector(matriz[i], colls);
    }
    printf("\n");
}