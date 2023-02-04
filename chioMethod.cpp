#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;

int** generateSquareMatrix(int size){
    int** matris = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matris[i] = new int[size];
    }
    return matris;
}

int** randomMatrix(int size){
    
    int** matris = generateSquareMatrix(size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            matris[i][j] = rand()%10+1;
        }
    }
    return matris;
}

void printMatrix(int** matris, int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout<<matris[i][j]<<" ";
        }
        cout<<endl;
    }
}

float determinant(int** matris, int size, float* carpim){
    int** indirgenmisMatris = generateSquareMatrix(size-1);
    float static det;
    (*carpim) = (*carpim)*(1/pow(matris[0][0],size-2));
    if(size == 2){
        det = (*carpim)*(matris[0][0]*matris[1][1]-matris[1][0]*matris[0][1]);
        return det;
    }
    for (int i = 0; i < size-1; i++){
        for (int j = 0; j < size-1; j++){
            indirgenmisMatris[i][j] = matris[0][0]*matris[i+1][j+1]-matris[0][j+1]*matris[i+1][0];
        }
    }
    return determinant(indirgenmisMatris,size-1,carpim);  
}

int main(){

    srand(time(NULL));
    float *carpim=new float(1.0f);
    int size;
    cout<<"Boyut giriniz: "; cin>>size;
    int** matris = randomMatrix(size);
    printMatrix(matris,size);
    double det = determinant(matris,size,carpim);
    cout<<"det: "<<det<<endl;
    

    

    for (int i = 0; i < size; i++)
    {
        delete [] matris[i];
    }
    delete [] matris;
    delete carpim;
    return 0;
}