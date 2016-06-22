//
//  MatrixFunctions.h
//  CramerEq
//
//  Created by Leandro Silva Soares on 20/06/16.
//  Copyright © 2016 Leandro Silva Soares. All rights reserved.
//

#ifndef MatrixFunctions_h
#define MatrixFunctions_h

#include <stdio.h>
#include <stdlib.h>
#include "MatrixUtils.h"
#endif /* MatrixFunctions_h */


float * cramer3x3(float a,float b,float c,float d,float e,float f,float g,float h,float i,float j,float k,float l);

/*
 float * cramerMatrizTamanho(float ** matriz,int size,float * vr);
 */
float * cramerMatrizTamanhoVector(float ** matriz,int size,float * vr);