// Mr. Arkiletian ICTP 12
// Simultaneous linear equation assignment (2 team members)
// Solved using the STL generic vector container class 


#include <iostream>
#include <vector>
#include <cmath> // for pow function

using namespace std;

typedef vector <double> Dvector;
typedef vector <Dvector> Dmatrix;

// Prototypes (variable names included, but not needed)
// DO NOT change any prototypes!! NO other functions allowed.

Dmatrix GetA(); 
// gets the matrix A from the user and returns it

Dvector Getb(const int siz); 
// gets the vector b from the user and returns it

void Display(const Dvector &xvect); 
// displays the contents of vector xvect

void Display(const Dmatrix &Amat); 
// displays the contents of matrix Amat (Note: Display function is overloaded)

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect);
// Solves for systems of linear equations in the form Ax=b using cramer's rule 

double Det(const Dmatrix &Amat);
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix 

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect);
// Replaces the column 'col' in Rmat with bvect and returns Rmat

Dmatrix Minor(const Dmatrix &Amat, const int col);
// Gets the Minor matrix of Amat by crossing out the first row and 
// column 'col' then returns that smaller matrix


//-------------------------------------------
/*
 *TODO
 * Format input into matrix                   |done|
 * display matrix                             |done|
 * solve-x by cramer rule                     
 * 2x2 determinant algo
 * recursive determinant algo
 * insert b matrix
 * get minor function
 */

int main(){

Dmatrix A;     
Dvector b,x;

A=GetA();
Display(A);
b=Getb(A.size());
Display(b);
/*
x=Solvex(A,b);

Display(x);
*/
return(0);
}
//-------------------------------------------
Dmatrix GetA(){
    int width;
    cin >> width;

    Dmatrix bigMatrix;
    int input;

    for(int x = 0; x < width; x++){
        Dvector temp;
        for(int y = 0; y < width; y++){
            cin >> input;
            temp.push_back(input);
        }
        bigMatrix.push_back(temp);
    }
    
    return bigMatrix;
}

Dvector Getb(const int siz){
    Dvector vec;
    int inp;
    for (int i=0;i<siz;i++){
        cin>>inp;
        vec.push_back(inp);
    }
    return vec;
}

void Display(const Dmatrix &Amat){
    for (auto i:Amat){
        for (auto x:i){
            cout<<x<<" ";
        }
        cout<<endl;
    }

}

void Display(const Dvector &xvect){
    for (auto i:xvect){
        cout<<i<<endl;
    }
    cout<<endl;
}

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect){
    int size = Rmat.size();
    
    for (int i = 0; i<size;i++){
        Rmat.at(col).at(i) = bvect.at(i);
    }
    return Rmat;
}
