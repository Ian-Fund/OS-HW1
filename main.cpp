#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>
#include <fstream>

using namespace std;
void fillArray(int rows, int cols,double** &matrix);
void printArray(int rows, int cols, double** &matrix);
void addArray(int row1, int col1, int row2, int col2, double**array1, double** array2);
void subArray(int row1, int col1, int row2, int col2, double**array1, double** array2);
void mulArray(int row1, int col1, int row2, int col2, double**array1, double** array2);
void* addMatrix(void * addMatrix);
void* sMatrix(void * subMatrix);
void mulMatrix(struct addSub &x);
struct addSub{
    int row;
    int col;
    double** matrix1;
    double** matrix2;
    double** resultMatrix;
    struct timer;
    int col2;
};
struct timer{
    int n;
    double runningTime;
};
struct mul{
    int row;
    int col;

};

int main() {
    int row1, col1;
    fstream readFromFile;
    string inputFile = "/home/mathbot/CLionProjects/Operating Systems/hw1/input1";
    readFromFile.open(inputFile);
    if (readFromFile.fail()) {
        cout << "Cannot open file\n";
        exit;
    }
    readFromFile  >> row1 >> col1; // get size of matrix
    double **matrix1 = new double* [row1]; //create  2dmatrix
    for (int i = 0; i < row1; ++i) {
        matrix1[i] = new double[col1];
    }
    for (int k = 0; k < row1; ++k) {
        for (int i = 0; i < col1; ++i) {
            readFromFile>>matrix1[k][i]; //fill matrix from file
        }
    }

    printArray(row1,col1,matrix1);

    int row2, col2;
    readFromFile >>row2>>col2;   //get size of matrix2
    double **matrix2 = new double* [row1];  //create 2d matrix
    for (int i = 0; i < row2; ++i) {
        matrix2[i] = new double[col2];
    }
    for (int k = 0; k < row2; ++k) {
        for (int i = 0; i < col2; ++i) {
            readFromFile>>matrix2[k][i]; //fill matrix from file
        }
    }

    printArray(row2,col2,matrix2);

    double **resultMatrix = new double* [row1];
    for (int i = 0; i < row1; ++i) {
        resultMatrix[i] = new double[col1];
    }
// make array of monster
    addSub monster[100];
    /*{
            monster.row = row1,
            monster.col = col1,
            monster.matrix1 = matrix1,
            monster.matrix2 = matrix2,
            monster.resultMatrix = resultMatrix,
            monster.col2 = col2
    };*/
    string input;

    do{
        if(input == "1"){
            if (row1 != row2 || col1 != col2){
                cout<<"Cannot add these matricies!\n";

            }
           else {
                pthread_t tid[row1*col1];
                for (int i = 0; i < row1; ++i) {
                   // monster.row = i;
                    for (int j = 0; j < col1; ++j) {
                        monster[i*row1+j].row = i;
                        monster[i*row1+j].col = j;
                        monster[i*row1+j].matrix1 = matrix1;
                        monster[i*row1+j].matrix2 = matrix2;
                        monster[i*row1+j].resultMatrix = resultMatrix;
                        //addMatrix(monster);
                        pthread_create(&tid[i+j],NULL, addMatrix,&monster[i*row1+j]);
                        //cout<< monster[i*row1+j].resultMatrix[i][j]<<" ";
                    }
                    cout<<endl;
                }
                for (int l = 0; l < row1*col1 ; ++l) {
                    pthread_join(tid[l],NULL);
                }
                for (int k = 0; k < row1; ++k) {
                    for (int i = 0; i < col1; ++i) {
                        cout<<resultMatrix[k][i]<<" ";
                    }
                    cout<<endl;
                }
            }

            cout << "Enter a selection: \n 1 = Add Matricies \n 2 = Subtract Matricies \n 3 = Multiply Matricies \n 4 = Exit\n";
            cin >> input;

        }
        else if (input == "2"){
           if (row1 != row2 || col1 != col2){
            cout<<"Cannot subtract these matricies!\n";

        }
        else {
            pthread_t tid[row1*col1];
            for (int i = 0; i < row1; ++i) {
                // monster.row = i;
                for (int j = 0; j < col1; ++j) {
                    monster[i*row1+j].row = i;
                    monster[i*row1+j].col = j;
                    monster[i*row1+j].matrix1 = matrix1;
                    monster[i*row1+j].matrix2 = matrix2;
                    monster[i*row1+j].resultMatrix = resultMatrix;
                    //addMatrix(monster);
                    pthread_create(&tid[i+j],NULL, sMatrix,&monster[i*row1+j]);
                    //cout<< monster[i*row1+j].resultMatrix[i][j]<<" ";
                }
                cout<<endl;
            }
            for (int l = 0; l < row1*col1 ; ++l) {
                pthread_join(tid[l],NULL);
            }
            for (int k = 0; k < row1; ++k) {
                for (int i = 0; i < col1; ++i) {
                    cout<<resultMatrix[k][i]<<" ";
                }
                cout<<endl;
            }
        }
            cout << "Enter a selection: \n 1 = Add Matricies \n 2 = Subtract Matricies \n 3 = Multiply Matricies \n 4 = Exit\n";
            cin >> input;
        }
        else if(input == "3") {
            if (row1 != col2) {
                cout << "Cannot multiply these matricies!\n";

            } else {
//                // need to replace this with threads somehow
//                double **MultiplyresultMatrix = new double* [row1];
//                for (int i = 0; i < row1; ++i) {
//                    MultiplyresultMatrix[i] = new double[col2];
//                }
//                for(int i = 0; i < row1; ++i) {
//                    monster.row = i;
//                    for (int j = 0; j < col2; ++j) {
//                        monster.col2 = j;
//                        for (int k = 0; k < col1; ++k) {
//                            monster.col = k;
//                            //MultiplyresultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
//                            mulMatrix(monster);
//                        }
//                    }
//                }
//                printArray(row1,col2,MultiplyresultMatrix);

            }

            cout << "Enter a selection: \n 1 = Add Matricies \n 2 = Subtract Matricies \n 3 = Multiply Matricies \n 4 = Exit\n";
            cin >> input;
        }
        else{
            cout << "Invalid Selection\n";
            cout << "Enter a selection: \n 1 = Add Matricies \n 2 = Subtract Matricies \n 3 = Multiply Matricies \n 4 = Exit\n";
            cin >> input;
        }
    } while (input != "4");

    //double solution = addArray(row1,col1,row1,col1,arr,arr);

    return 0;
}

void fillArray(int rows, int cols, double** &matrix){
    for (int k = 0; k < rows; ++k) {
        cout<<"Enter row values: \n";
        for (int i = 0; i < cols; ++i) {
            cin>>matrix[k][i];

        }

    }
    // need to have dynamic way to fill array

}

void printArray(int rows, int cols, double** &matrix){
    for (int i = 0; i < cols;  ++i) {
        for (int j = 0; j < rows; ++j) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void subArray(int row1, int col1, int row2, int col2, double**array1, double** array2){
    if (row1 != row2 || col1 != col2){
        cout<<"Cannot subtract these matricies!\n";
        return ;
    }
    // need to replace this with threads somehow
    double array[row1][col1];
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col1; ++j) {
            array[i][j] = array1[i][j] - array2[i][j];
        }
    }

}

void mulArray(int row1, int col1, int row2, int col2, double**array1, double** array2){
    if (row1 != col2 ){
        cout<<"Cannot multiply these matricies!\n";
        return ;
    }
    // need to replace this with threads somehow
    double resultMatrix[row1][col2];

}

void* addMatrix(void * addMatrix){
    // start timer here?
    struct addSub *x =  (struct addSub *)addMatrix;
    x->resultMatrix[x->row][x->col] = x->matrix1[x->row][x->col] + x->matrix2[x->row][x->col];
    return NULL;

    //update time stuff here
}

void mulMatrix(struct addSub &x){
    //timer?
// for loop inn here
    x.resultMatrix [x.row][x.col2] += x.matrix1[x.row][x.col] * x.matrix2[x.col][x.col2];
}

void* sMatrix(void * sMatrix){
    // start timer here?
    struct addSub *x =  (struct addSub *)sMatrix;
    x->resultMatrix[x->row][x->col] = x->matrix1[x->row][x->col] - x->matrix2[x->row][x->col];
    return NULL;
//
//    struct addSub *x =  (struct addSub *)addMatrix;
//    x->resultMatrix[x->row][x->col] = x->matrix1[x->row][x->col] + x->matrix2[x->row][x->col];
//    return NULL;
    //update time stuff here
}