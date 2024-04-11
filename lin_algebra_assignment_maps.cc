// Mr. Arkiletian ICTP 12
// Simultaneous linear equation assignment (2 team members)
// Solved using the STL generic vector container class 

#include <map>
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
 * 2x2 determinant algo                       |done|
 * recursive determinant algo                 |done|
 * insert b matrix 
 * get minor function                         |done|
 */

int main(){

Dmatrix A;     
Dvector b,x;

A=GetA();
Display(A);
b=Getb(A.size());
Display(b);

x=Solvex(A,b);

Display(x);


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
        Rmat.at(i).at(col) = bvect.at(i);
    }
    return Rmat;
}

Dmatrix Minor(const Dmatrix &Amat, const int col){
    Dmatrix minor;
    int size = Amat.size();
    for (int x = 0;x<size;x++){
        if (x==0){
            continue;
        }
        Dvector row;
        for (int i = 0; i<size; i++){
            if (i == col){
                continue;
            }
            row.push_back(Amat.at(x).at(i));
        }
        minor.push_back(row);
    }
    return minor;
}

double Det(const Dmatrix &Amat){
    map <Dmatrix, double> Detcache;
    int total = 0;
    if (Amat.size() == 2){
        return Amat.at(0).at(0)*Amat.at(1).at(1)-Amat.at(0).at(1)*Amat.at(1).at(0);
    }
    else{
        for (uint x=0;x<Amat.size();x++){
            auto matrix=Detcache.find(Amat);
            if (Detcache.find(Amat) != Detcache.end()){
                total += matrix->second;
            }
            else{
                Detcache[Amat]=pow(-1,x)*Amat.at(0).at(x)*(Det(Minor(Amat,x)));
        }       total += Detcache[Amat];
    }
    return total;
}
}

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect){
    int detvalue = 0, bigdet = 0;
    Dvector solutions = {};
    bigdet = Det(Amat);
    Dmatrix current;
    for (uint x = 0;x<Amat.size();x++){
        current = Replace(Amat,x,bvect);
        Display(current);
        detvalue = Det(current);
        detvalue = detvalue/bigdet;
        solutions.push_back(detvalue);
        detvalue = 0;
    }
    return solutions;
}
