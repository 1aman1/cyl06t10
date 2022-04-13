#include<iostream>
#include<vector>

// figuring out internal representation method to start
// whether 2d arry, 2d vector, or some other hybrid

class graph {
private:
    //int matGraph[][];
public:

};

void print( bool matGraph[4][4] ) {
    for ( int row = 0; row < 4; row++) {
        for ( int col = 0; col < 4; col++) {
            std::cout << matGraph[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

void print( std::vector<std::vector<int>> vec ) {
    for ( int row = 0; row < 4; row++) {
        for ( int col = 0; col < 4; col++) {
            std::cout << vec[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    bool matGraph[4][4];
    int size;


    std::vector<std::vector<int>> vec( size , std::vector<int> (size, 0));
 
    matGraph[0][1] = true;
    matGraph[1][2] = true;
    matGraph[2][0] = true;
    matGraph[3][2] = true;

    print(matGraph);
    print(vec);


    return 0;
}