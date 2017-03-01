#include <iostream>
#include "defs.h"
using namespace std;

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
