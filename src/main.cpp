#include <iostream>
#include <string>


/*
king = 100
queen = 10
rook = 5
knight = 3
bishop = 3
pawn = 1
*/
// PGN: if same type of pieces go to shared square, differentiate by either file or rank

int main() {
    // int board[8][8] = {
    //     -1,-2,-3,-4,-5,-3,-2,-1,
    //     -6,-6,-6,-6,-6,-6,-6,-6,
    //      0, 0, 0, 0, 0, 0, 0, 0, 
    //      0, 0, 0, 0, 0, 0, 0, 0, 
    //      0, 0, 0, 0, 0, 0, 0, 0, 
    //      0, 0, 0, 0, 0, 0, 0, 0, 
    //      6, 6, 6, 6, 6, 6, 6, 6,
    //      1, 2, 3, 4, 5, 3, 2, 1,
    // }

    return 0;
}


// void createBoard() {
//     // std::string 
//     for (int file = 0; file < 8; file++) {
//         for (int rank = 0; rank < 8; rank++) {
//             bool isDark = (file + rank) % 2;

//             std::string squareColor = (isDark) ? lightCol : darkCol;

//         }
//     }
// }