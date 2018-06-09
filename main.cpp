#include <iostream>
using namespace std;
void fillArray(int rows, int cols,double** &matrix);
void printArray(int rows, int cols, double** &matrix);
void addArray(int row1, int col1, int row2, int col2, double**array1, double** array2);
void subArray(int row1, int col1, int row2, int col2, double**array1, double** array2);
void mulArray(int row1, int col1, int row2, int col2, double**array1, double** array2);
double number(double number);

int main() {
    int row1, col1;
//    cout<<"Enter matrix 1 dimensions: \n";
//    cin >> row1 >> col1;
////    double arr[row1][col1];
//    double **matrix1 = new double* [row1];
//    for (int i = 0; i < row1; ++i) {
//        matrix1[i] = new double[col1];
//    }
//
//
//    fillArray(row1,col1, matrix1);
//    printArray(row1,col1,matrix1);
    string input;
    do{
        if(input == "1"){
            //addArray
            cout << "Enter a selection: \n 1 = Add Matricies \n 2 = Subtract Matricies \n 3 = Multiply Matricies \n 4 = Exit\n";
            cin >> input;

        }
        else if (input == "2"){
            //subArray
            cout << "Enter a selection: \n 1 = Add Matricies \n 2 = Subtract Matricies \n 3 = Multiply Matricies \n 4 = Exit\n";
            cin >> input;
        }
        else if(input == "3"){
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
void addArray(int row1, int col1, int row2, int col2, double**array1, double** array2){
    if (row1 != row2 || col1 != col2){
        cout<<"Cannot add these matricies!\n";
        return ;
    }
    // need to replace this with threads somehow
    double array[row1][col1];
    pthread_t tid;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col1; ++j) {
            array[i][j] = pthread_create(&tid,NULL,number,(array1[i][j] + array2[i][j])); // each thread does this the plus is the last arg
            if(pthread_create(&tid, NULL, print_pos, &pos[i]))
            {
                fprintf(stderr, "Error creating thread\n");
                return 1;

            }
        }
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
    double array[col1][row2];

}

double number(double number){
    return number;
}