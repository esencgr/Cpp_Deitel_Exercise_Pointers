// Cpp DEITEL EXERCISE 7.25
// This solution assumes that there is only one
// entrance and one exit for a given maze, and
// these are the only two zeroes on the borders.
#include <iostream>
#include <cstdlib>
using namespace std;

enum Direction { DOWN, RIGHT, UP, LEFT };
const int X_START = 2, Y_START = 0;       // starting coordinate for maze

void maze_traversal( char[ ][ 12 ], int, int, int );
bool coord_edge( int, int );
bool valid_move( const char[ ][ 12 ], int, int );
void print( const char[ ][ 12 ] );

int main(){
  char maze[ 12 ][ 12 ] =
         { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
           {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
           {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
           {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
           {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
           {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
           {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
           {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
           {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
           {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
           {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
           {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };

    maze_traversal( maze, X_START, Y_START, RIGHT );

    return 0;
}
// Assume that there is exactly 1 entrance and exactly 1 exit to the maze.
void maze_traversal( char maze[ ][ 12 ], int x, int y, int direction ){
    static bool flag = false;
    maze[ x ][ y ] = 'x';
    print( maze );

    if ( coord_edge( x, y )  &&  x != X_START  &&  y != Y_START ){
        cout << "\nMaze successfully exited!\n\n";
        return; // maze is complete
    }
    else if ( x == X_START  &&  y == Y_START  &&  flag ) {
      cout << "\nArrived back at the starting location.\n\n";
      return;
    }
    else {
        flag = true;
        for ( int move = direction, count = 0; count < 4; count++, move++, move %= 4 ){
            switch ( move ){
               case DOWN:
                   if ( valid_move( maze, x + 1, y )){             // MOVE DOWN
                      maze_traversal ( maze, x + 1, y, LEFT );
                      return;
                   }
               break;
               case RIGHT:
                   if ( valid_move( maze, x, y + 1 )){             // MOVE RİGHT
                      maze_traversal ( maze, x, y + 1, DOWN );
                      return;
                   }
               break;
               case UP:
                   if ( valid_move( maze, x - 1 , y )){             // MOVE UP
                      maze_traversal ( maze, x - 1, y, RIGHT );
                      return;
                   }
               break;
               case LEFT:
                   if ( valid_move( maze, x, y - 1)){             // MOVE LEFT
                      maze_traversal ( maze, x, y - 1, UP );
                      return;
                   }
               break;
            }
        }
    }
}

bool coord_edge( int x, int y ){
    if ( (x == 0 || x == 11)  &&  ( y >= 0 && y <= 11) )
        return true;
    else if ( (y == 0 || y == 11)  &&  ( x >= 0 && x <= 11) )
        return true;
    else
        return false;
}

bool valid_move( const char maze[ ][ 12 ], int r, int c ){
    return ( r >= 0 && r <= 11  &&  c >= 0 && c <= 11  &&  maze[ r ][ c ] != '#' );
}

void print( const char maze[ ][ 12 ] ){
    for ( int x = 0; x < 12; x++ ){
        for ( int y = 0; y < 12; y++ )
             cout << maze[ x ][ y ];
    cout << endl;
    }
    cout << "\nHit return to see next move\n";
    cin.get();
}
