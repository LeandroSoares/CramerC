//
//  MatrixFunctions.c
//  CramerEq
//
//  Created by Leandro Silva Soares on 20/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#include "MatrixFunctions.h"


//reference
//http://www.vbforums.com/showthread.php?673571-RESOLVED-Solving-the-equation-with-three-unknowns

//ax + by + cz = j
//dx + ey + fz = k
//gx + hy + iz = l

//
//M = a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h
//x = (j*e*i + b*f*l + c*k*h - c*e*l - b*k*i - j*f*h) / M
//y = (a*k*i + j*f*g + c*d*l - c*k*g - j*d*i - a*f*l) / M
//z = (a*e*l + b*k*g + j*d*h - j*e*g - b*d*l - a*k*h) / M

float * cramer3x3(float a,float b,float c,float d,float e,float f,float g,float h,float i,float j,float k,float l){
    float M = a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
    float x = (j*e*i + b*f*l + c*k*h - c*e*l - b*k*i - j*f*h) / M;
    float y = (a*k*i + j*f*g + c*d*l - c*k*g - j*d*i - a*f*l) / M;
    float z = (a*e*l + b*k*g + j*d*h - j*e*g - b*d*l - a*k*h) / M;
    
    float * resposta = newVector(3);
    resposta[0]=x;
    resposta[1]=y;
    resposta[2]=z;
    return resposta;
}

float multDiagonalPrincipal(float ** matriz, int tamanho){
    float mult=1;
    int i=0;
    for (;i<tamanho ; i++) {
        int j=0;
        for (; j<tamanho; j++) {
            if(i-j==0) {
                mult*=matriz[i][j];
            }
        }
    }
    return  mult;
}

float multDiagonalSecundaria(float ** matriz,int tamanho){
    float mult=1;
    int i=0;
    for (;i<tamanho ; i++) {
        int j=0;
        for (; j<tamanho; j++) {
            if(i+j==tamanho-1) {
                mult*=matriz[i][j];
            }
        }
    }
    return  mult;
}

float * changeFirstToLast(float * vector,int size){
    float * V=newVector(size);
    int i=0;
    for (; i<size-1; i++) {
        V[i] = vector[i+1];
    }
    V[size-1]=vector[0];
    return V;
}

float ** changeFirstCollsToLast(float ** matriz, int tamanho) {
    float **result = newMatrix(tamanho, tamanho);
    int i=0;
    for (; i<tamanho; i++) {
        result[i]=changeFirstToLast(matriz[i],tamanho);
    }
    return result;
}

float determinante(float **matriz,int tamanho) {
    float D;
    float ** m = matrixClone(matriz, tamanho, tamanho);
    float *mults = newVector(2);
    
    mults[0]=0;
    mults[1]=0;
    int i=0;
    for (; i<tamanho; i++) {
        mults[0]+=multDiagonalPrincipal(m, tamanho);
        mults[1]+=multDiagonalSecundaria(m, tamanho);
        m = changeFirstCollsToLast(m, tamanho);
    }

    D = mults[0] - mults[1];
    free(mults);
    
    return D;
}

float ** matrizSubstituiColuna(float ** matriz, int coluna,float * substituta,int tamanho) {
    float **m = newMatrix(tamanho, tamanho);
    int i=0;
    for (;i<tamanho ; i++) {
        int j=0;
        for (; j<tamanho; j++) {
            if(j==coluna){
                m[i][j]=substituta[i];
            }
            else{
                m[i][j]=matriz[i][j];
            }
        }
    }
    return m;
}

float * cramerMatrizTamanhoVector(float ** matriz, int size, float * vr) {
    float D = determinante(matriz, size);
    float *Ds = newVector(size);
    int i = 0;
    for (; i < size; i++) {
        float ** mTemp = matrizSubstituiColuna(matriz, i, vr, size);
        Ds[i] = determinante(mTemp, size)/D;
        free(mTemp);
    }
    return Ds;
}

