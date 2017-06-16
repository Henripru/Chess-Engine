#include <iostream>
#include "defs.h"
using namespace std;

const int BitTable[64] = {
    63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2,
    51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52,
    26, 60, 6, 23, 44, 46, 27, 56, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28,
    58, 20, 37, 17, 36, 8
};

//Returns the index of the bit that is being moved and marks it as 0
int PopBit(U64 *bb) {
    U64 b = *bb^(*bb-1);
    unsigned int fold = (unsigned) ((b&0xffffffff)^b>>32);
    *bb &= (*bb - 1);
    return BitTable[(fold * 0x783a9b23) >> 26];
}

//Returns the number of pieces that are on the table
int CountBits(U64 b) {
    int r;
    for(r = 0; b; r++, b &= b - 1);
    return r;
}

void PrintBitBoard(U64 bb) {

    U64 shiftMe = 1ULL;

    int sq = 0;
    int sq64 = 0;

    for(int rank = RANK_8; rank >= RANK_1; --rank)
    {
        for(int file = FILE_A; file <=FILE_H; ++file)
        {
            sq = FR2SQ(file,rank); //120 based
            sq64 = SQ64(sq); // 64 based

            if(shiftMe << sq64 & bb)
            {
                cout << "X";
            }
            else
            {
                cout << "-";
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}
