#include "defs.h"
#include "stdlib.h"
#define RAND_64 ((U64)rand() + ((U64)rand() << 15) + ((U64)rand() << 30) + ((U64)rand() << 45) + (((U64)rand() & 0xf) << 60))

int Sq120ToSq64[BRD_SQ_NUM];  // These declarations are conversion tables between a normal 1-64 chess table
int Sq64ToSq120[64];          // and our weird 1-120 chess table

U64 SetMask[64];
U64 ClearMask[64];

U64 PieceKeys[13][120];
U64 SideKey;
U64 CastleKeys[16];

void InitHashKeys() {
    int index = 0;
    int index2 = 0;
    for(index = 0; index < 13; index++) {
        for(index2 = 0; index < 120; index2++) {
            PieceKeys[index][index2] = RAND_64;
        }
    }
}

void InitBitMasks(){
    int index = 0;

    for(index = 0; index < 64; index++){
        SetMask[index] = 0;
        ClearMask[index] = 0;
    }

    for(index = 0; index < 64; index++){
        SetMask[index] |= (1ULL << index);
        ClearMask[index] = ~SetMask[index];
    }
}

//Initializes values in conversion tables
void InitSq120To64(){

    int sq  = A1;
    int sq64 = 0;
    for(int i = 0; i < BRD_SQ_NUM; ++i){
        Sq120ToSq64[i] = 65;
    }
    for(int i = 0; i < 64; ++i){
        Sq64ToSq120[i] = 120;
    }

    for(int rank = RANK_1; rank <= RANK_8; ++rank){
        for(int file = FILE_A; file <= FILE_H; ++file){
            sq = FR2SQ(file, rank);
            Sq64ToSq120[sq64] = sq;
            Sq120ToSq64[sq] = sq64;
            sq64++;
        }
    }
}

void AllInit(){
    InitSq120To64();
    InitBitMasks();
    InitHashKeys();
}
