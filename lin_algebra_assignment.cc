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
 * Format input into matrix
 * display matrix
 * solve-x by cramer rule
 * 2x2 determinant algo
 * insert b matrix
 * get minor function
 */

int main(){

Dmatrix A;     
Dvector b,x;

A=GetA();
Display(A);
b=Getb(A.size());
x=Solvex(A,b);
Display(x);

return(0);
}
//-------------------------------------------

Dmatrix GetA(){
    string inp;
    vector <vector <int>> matrix;
    cout<<"Enter matrix ";
    getline(inp);
    size = inp[0];
    for (auto i:inp){
        
    
    return matrix;
}


