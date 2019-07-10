// Cpp DEITEL EXERCISE 7.25 - 7.26 - 7.27
// This solution assumes that there is only one
// entrance and one exit for a given maze, and
// these are the only two zeroes on the borders.
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum Direction { DOWN, RIGHT, UP, LEFT };
const int row = 10, col = 10;       // starting coordinate for maze
// const int MAX_DOTS = 100; // maximum possible dots for maze

void maze_traversal( char[ ][ col ], const int, const int, int, int, int );
void maze_generate( char [ ][ col ], int *, int * );
bool coord_edge( int, int );
bool valid_move( const char[ ][ col ], int, int );
void print( const char[ ][ col ] );

int main(){
  // char maze[ row ][ col ] =
  //        { {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
  //          {'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
  //          {'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
  //          {'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
  //          {'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
  //          {'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
  //          {'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
  //          {'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
  //          {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
  //          {'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
  //          {'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
  //          {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} };
    char maze [ row ][ col ];
    int x_start, y_start, x, y;
    srand( time ( 0 ));

    for ( int loop = 0; loop < row; ++loop )
        for ( int loop2 = 0; loop2 < col; ++loop2 )
            maze[ loop ][ loop2 ] = '#';

    maze_generate( maze, &x_start, &y_start );
    x = x_start;
    y = y_start;
    maze_traversal( maze, x_start, y_start, x, y , RIGHT);
    return 0;
}

// Assume that there is exactly 1 entrance and exactly 1 exit to the maze.
void maze_traversal( char maze[ ][ col ], const int x_start, const int y_start , int x, int y, int direction ){
    static bool flag = false;
    maze[ x ][ y ] = 'x';
    print( maze );

    if ( coord_edge( x, y )  &&  x != x_start  &&  y != y_start ){
        cout << "\nMaze successfully exited!\n\n";
        return; // maze is complete
    }
    else if ( x == x_start  &&  y == y_start  &&  flag ) {
      cout << "\nArrived back at the starting location.\n\n";
      return;
    }
    else {
        flag = true;
        for ( int move = direction, count = 0; count < 4; count++, move++, move %= 4 ){
            switch ( move ){
               case DOWN:
                   if ( valid_move( maze, x + 1, y )){             // MOVE DOWN
                      maze_traversal ( maze, x_start, y_start, x + 1, y, LEFT );
                      return;
                   }
               break;
               case RIGHT:
                   if ( valid_move( maze, x, y + 1 )){             // MOVE RİGHT
                      maze_traversal ( maze, x_start, y_start, x, y + 1, DOWN );
                      return;
                   }
               break;
               case UP:
                   if ( valid_move( maze, x - 1 , y )){             // MOVE UP
                      maze_traversal ( maze, x_start, y_start, x - 1, y, RIGHT );
                      return;
                   }
               break;
               case LEFT:
                   if ( valid_move( maze, x, y - 1)){             // MOVE LEFT
                      maze_traversal ( maze, x_start, y_start, x, y - 1, UP );
                      return;
                   }
               break;
            }
        }
    }
}
//  generate maze randomly
void maze_generate( char maze[ ][ col ], int *x_ptr, int *y_ptr){
    int a, x, y, entry, exit;
    do{
       entry = rand() % 4;
       exit = rand() % 4;
    } while( entry == exit );

    // DETERMINE ENTRY POSITION
    if ( entry == 0 ){
        *x_ptr = 1 + rand() % (row - 2);
        *y_ptr = 0;
        maze[ *x_ptr ][ *y_ptr  ] = '.';
    }
    else if ( entry == 1 ){
        *x_ptr = 0;
        *y_ptr = 1 + rand() % (col - 2);
        maze[ *x_ptr  ][ *y_ptr ] = '.';
    }
    else if ( entry == 2 ){
        *x_ptr = 1 + rand() % (row - 2);
        *y_ptr = col - 1;
        maze[ *x_ptr ][ *y_ptr  ] = '.';
    }
    else{
        *x_ptr = row - 1;
        *y_ptr = 1 + rand() % (col - 2);
        maze[ *x_ptr   ][ *y_ptr ] = '.';
    }

    // DETERMINE EXIT POSITION
    if ( exit == 0 ){
        a = 1 + rand() % (row - 2);
        // *y_ptr = 0;
        maze[ a ][ 0 ] = '.';
    }
    else if ( exit == 1 ){
        // *x_ptr = 0;
        a = 1 + rand() % (col - 2);
        maze[ 0 ][ a ] = '.';
    }
    else if ( exit == 2 ){
        a = 1 + rand() % (row - 2);
        // *y_ptr = 11;
        maze[ a ][ col - 1 ] = '.';
    }
    else{
        // *x_ptr = 11;
        a = 1 + rand() % (col - 2);
        maze[ row - 1 ][ a ] = '.';
    }

    // ADD DOTS RANDOMLY
    for ( int i = 1; i < ( row - 2 ) * ( col - 2 ); i++){
        x = 1 + rand() % (row - 2);
        y = 1 + rand() % (col - 2);
        maze[ x ][ y ] = '.';
    }
}

// move is valid ?
bool valid_move( const char maze[ ][ col ], int r, int c ){
    return ( r >= 0 && r <= (row - 1)  &&  c >= 0 && c <= (col - 1)  &&  maze[ r ][ c ] != '#' );
}

bool coord_edge( int x, int y ){
    if ( (x == 0 || x == (row - 1))  &&  (y >= 0 && y <= (col - 1)) )
        return true;
    else if ( (y == 0 || y == (col - 1))  &&  (x >= 0 && x <= (col - 1)) )
        return true;
    else
        return false;
}



void print( const char maze[ ][ col ] ){
    for ( int x = 0; x < row; x++ ){
        for ( int y = 0; y < col; y++ )
             cout << maze[ x ][ y ] << ' ';
    cout << endl;
    }
    cout << "\nHit return to see next move\n";
    cin.get();
}
