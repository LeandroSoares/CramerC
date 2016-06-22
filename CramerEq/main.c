//
//  main.c
//  CramerEq
//
//  Created by Leandro Silva Soares on 20/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "MatrixUtils.h"
#include "MatrixFunctions.h"


int main(int argc, const char * argv[]) {
    /*
     |  x -2y -2z = -1
     |  x -y  +z  = -2
     | 2x +y  +3z =  1
     reposta:
     x = 1, y = 2 e z = –1.
     */

    float **matriz = newMatrix(3,3);
    
    matriz[0][0]=12;matriz[0][1]=643;matriz[0][2]=106;
    matriz[1][0]=643;matriz[1][1]=34.843;matriz[1][2]= 5.779;
    matriz[2][0]=106;matriz[2][1]= 5.77;matriz[2][2]= 976;

    float *coll4 = newVector(3);
    
    coll4[0]=753;
    coll4[1]=40830;
    coll4[2]= 6796;

    printf("Considerando:\n");
    printf("|ax +by +cz = j\n");
    printf("|dx +ey +fz = k\n");
    printf("|gx +hy +iz = l\n");
    
    printf("\nTemos para:\n");
    printf("|ax +by +cz|\n");
    printf("|dx +ey +fz|\n");
    printf("|gx +hy +iz|\n");
    
    printf("\na matriz:\n");
    printMatrix(matriz, 3, 3);
    
    printf("e para:\n");
    printf("|j|\n|k|\n|l|\n");
    
    printf("\no vetor:\n");
    printVector(coll4, 3);
    
    float * resposta; // = cramer3x3(1, -2, -2, 1, -1, 1, 2, 1, 3, -1, -2, 1);
    
    resposta = cramerMatrizTamanhoVector(matriz, 3, coll4);
    printf("\nA resposta deve ser: x = 1, y = 2 e z = –1\n");
    printf("E a resposta calculada é: x=%f, y:%f, z:%f\n\n", resposta[0], resposta[1], resposta[2]);
    
    return 0;
}
