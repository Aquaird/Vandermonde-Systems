//
//  main.cpp
//  Vandermonde Systems
//
//  Created by Aquaird on 1/12/15.
//  Copyright (c) 2015 Aquaird. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define   CLOCKS_PER_SEC ((clock_t)1000)
#define MAX_SIZE 500;
// target Matrix
//double Matrix[1000][1000];
//target a value
double a[50000];
//solution b
double x[50000];
//b
double b[50000];
//c
double c[50000];
double half[50000];


void getVMatrix(int n, double *a);
void getInvVMatrix(int n, double *a);
void solveInv(int n);
void solvePri(int n);

int main(int argc, const char * argv[]) {
    
    int i,j;
    int n = 30000;
    clock_t start,end;
    

  
        srand((unsigned)time(0));
        
        for (i=0; i<n; i++) {
            a[i] = i+1;
        }

        
        for (i=0; i<n; i++) {
            b[i] = pow(a[1], i);
        }
        
//        getInvVMatrix(n, a);
        
//        solveInv(n-1);
//        printf("solution: ");
//        for (i=0; i<n; i++) {
//            printf("x[%d]: %3.2f\t", i, x[i]);
//        }
//        printf("\n\n");
//        
        
//        getVMatrix(n, a);
    start = clock();
    while (j<5){
                solvePri(n-1);
        //        printf("solution: ");
//        for (i=0; i<n; i++) {
//            printf("x[%d]: %3.2f\t", i, x[i]);
//        }
//        printf("\n\n");
        
        j++;
    }
    end = clock();
    std::cout<<(double)end-start<<std::endl;

    return 0;
}


//
//void getVMatrix(int n, double *a){
//    
//    int i,j;
//    for (i=0; i<n; i++) {
//        for (j=0; j<n; j++) {
//            Matrix[i][j] = pow(a[j], i);
//            printf("%3.2f\t", Matrix[i][j]);
//        }
//        printf("\n");
//    }
//    
//    
//    
//}
//
//void getInvVMatrix(int n, double *a){
//    
//    int i,j;
//    for (i=0; i<n; i++) {
//        for (j=0; j<n; j++) {
//            Matrix[i][j] = pow(a[i], j);
//            printf("%3.2f\t", Matrix[i][j]);
//        }
//        printf("\n");
//    }
//    
//}

void solveInv(int n){
    int i,j;
    
    //step 1
    for (i=0; i<=n; i++) {
        c[i] = b[i];
    }
    
    for (i=0; i<=n-1; i++) {
        
        for(j=n;j>=i+1;j--){
            c[j] = (c[j] - c[j-1]) / (a[j] - a[j-i-1]);
        }
        
    }
    
    //step 2
    for (i=0; i<=n; i++) {
        x[i] = c[i];
    }
    
    for (i=n-1; i>=0; i--) {
        for(j=i;j<=n-1;j++){
            x[j] = x[j] - a[i]*x[j+1];
        }
        
    }
    
}

void solvePri(int n){
    int i,j;
    
    //step 1
    for (i=0; i<=n; i++) {
        c[i] = b[i];
    }
    
    for(i=0;i<=n-1;i++){
        
        for (j=n; j>=i+1; j--) {
            c[j] = c[j] - a[i]*c[j-1];
        }
    }
    
    //step 2
    for (i=0; i<=n; i++) {
        x[i] = c[i];
    }
    
    for (i=n-1; i>=0; i--) {
        
        for (j=0; j<=n; j++) {
            
            if (j>=i+1) {
                half[j] = x[j] / (a[j] - a[j-i-1]);
            }
            else{
                half[j] = x[j];
            }
            
            if (j<=n-1 && j>=i) {
                x[j] = half[j] - half[j+1];
            }
            else{
                x[j] = half[j];
            }
        }
        

    }
    

    
    
}

