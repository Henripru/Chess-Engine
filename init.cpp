#include "defs.h"

int Sq120ToSq64[BRD_SQ_NUM];  // These declarations are conversion tables between a normal 1-64 chess table
int Sq64ToSq120[64];          // and our weird 1-120 chess table

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
}
