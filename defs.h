#ifndef DEFS_H
#define DEFS_H

#include <stdlib.h>
////////////////////////////////////////////////////////////////
#define DEBUG
#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if(!(n)) { \
printf("%s - Failed", #n); \
printf("On %s ",__DATE__); \
printf("At %s ",__TIME__); \
printf("In file %s ",__FILE__); \
printf("At Line %d\n",__LINE__); \
exit(1);}
#endif
///////////////////////////////////////////////////////////////

/*         /\
          //\\
THIS THING ||  is a handy debugger that I use to check my self on new material
           ||

*/

typedef unsigned long long U64; // Using every 8 digits to count as occupied pieces on corresponding rows

#define NAME "ChessEngine 1.0"
#define BRD_SQ_NUM 120

#define MAXGAMEMOVES 2048 // The longest game recorded was just over 1000 moves, or 2000 half moves

enum { EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bR, bQ, bK};
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE};
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE};

enum { WHITE, BLACK, BOTH};

enum {
  A1 = 21, B1, C1, D1, E1, F1, G1, H1,
  A2 = 31, B2, C2, D2, E2, F2, G2, H2,
  A3 = 41, B3, C3, D3, E3, F3, G3, H3,
  A4 = 51, B4, C4, D4, E4, F4, G4, H4,
  A5 = 61, B5, C5, D5, E5, F5, G5, H5,
  A6 = 71, B6, C6, D6, E6, F6, G6, H6,
  A7 = 81, B7, C7, D7, E7, F7, G7, H7,
  A8 = 91, B8, C8, D8, E8, F8, G8, H8, NO_SQ
};

enum { FALSE, TRUE};

// 0 0 0 0
// 4 bits represent castling permissions
// 1 0 0 1
// white can only castle kingside, and black can only castle queenside
enum { WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8};

typedef struct {

  int move;
  int castlePerm;
  int enPas;
  int fiftyMove;
  U64 posKey;

} S_UNDO;

typedef struct {

  int pieces[BRD_SQ_NUM]; // What is on the board
  U64 pawns[3]; // White, black and both 1 or 0 if it occupies rank and row
                // 01000000 00000000 00000000 00000000 00000000 ...

  int KingSq[2]; // Good to hold the square that the king is in

  int side; // Current side to move
  int enPas; // En'Passant square if one is not active, set to NO_SQ
  int fiftyMove; // Game is drawn after 50 moves

  int ply; // How many half moves we are in to the current search
  int hisPly; // Total number of half moves

  int castlePerm; // If rook or king is moved, castling is no longer possible

  U64 posKey; // A unique key that is generated for each position

  int pceNum[13]; // The number of pieces on the board indexed by piece type. Black king is index 12
  int bigPce[3];  // Number of pieces that aren't a pawn
  int majPce[3];  // Nmber of rooks and queens
  int minPce[3];  // Number of bishops and rooks

  S_UNDO history[MAXGAMEMOVES]; // Every time a move is made, we will store the values specified by the S_UNDO

  // Piece list increases solution speed by about 20%. Optimizes search techniques
  int pList[13][10];



} S_BOARD;

/* MACROS */
#define FR2SQ(f,r) ((21 + (f)) + ((r)*10)) // Returns equivalent file and rank

/* GLOBALS */
extern int Sq120ToSq64[BRD_SQ_NUM];  // These declarations are conversion tables between a normal 1-64 chess table
extern int Sq64ToSq120[64];          // and our weird 1-120 chess table

/* FUNCTIONS */
extern void AllInit();

#endif
