#include <iostream>
#include "defs.h"
using namespace std;

int main()
{
  AllInit();

  U64 playBitBoard = 0ULL;

  cout << "Start: " << endl;
  PrintBitBoard(playBitBoard);

  playBitBoard |= (1ULL << SQ64(D2));
  cout << "D2 Added: " << endl << endl;
  PrintBitBoard(playBitBoard);

  playBitBoard |= (1ULL << SQ64(G2));
  cout << "G2 Added: " << endl << endl;
  PrintBitBoard(playBitBoard);

  return 0;
}
