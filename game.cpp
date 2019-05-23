#include <iostream>
#include <cmath> 
#include "graph.h"
#include "marker.h"

using namespace std;
using namespace main_savitch_15;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};
graph <marker> game;
int checkwin();
void connect();

void board();

int main()
{
	int player = 1,i,choice;
    char mark;
    do
    {
        
        board();
        player=(player%2)?1:2;

        cout << "Player " << player << ", enter a number:  ";
        cin >> choice;

        mark=(player == 1) ? 'X' : 'O';


        if (choice == 1 && square[1] == '1')
        {
            square[1] = mark;
            
            marker m = marker(0,0,mark);
            game.add_vertex(m);
        }    
        else if (choice == 2 && square[2] == '2')
        {
            square[2] = mark;
            
            marker m = marker(0,1,mark);
            game.add_vertex(m);
        }
        else if (choice == 3 && square[3] == '3')
        {
            square[3] = mark;
            
            marker m = marker(0,2,mark);
            game.add_vertex(m);
        }
        else if (choice == 4 && square[4] == '4')
        {
            square[4] = mark;
            
            marker m = marker(1,0,mark);
            game.add_vertex(m);
        }
        else if (choice == 5 && square[5] == '5')
        {
            square[5] = mark;
            
            marker m = marker(1,1,mark);
            game.add_vertex(m);
        }
        else if (choice == 6 && square[6] == '6')
        {
            square[6] = mark;
            
            marker m = marker(1,2,mark);
            game.add_vertex(m);
        }
        else if (choice == 7 && square[7] == '7')
        {
            square[7] = mark;
            
            marker m = marker(2,0,mark);
            game.add_vertex(m);
        }
        else if (choice == 8 && square[8] == '8')
        {
            square[8] = mark;
            
            marker m = marker(2,1,mark);
            game.add_vertex(m);
        }
        else if (choice == 9 && square[9] == '9')
        {
            square[9] = mark;
            
            marker m = marker(2,2,mark);
            game.add_vertex(m);
        }
        else
        {
            cout<<"Invalid move ";

            player--;
            cin.ignore();
            cin.get();
        }
        
       
            connect();
    
        i=checkwin();
        player++;
    }
    while(i==-1);
    board();
    if(i==1)

        cout<<"==>\aPlayer "<<--player<<" win ";
    else
        cout<<"==>\aGame draw";

    cin.ignore();
    cin.get();
    return 0;
}

/*********************************************
    FUNCTION TO RETURN GAME STATUS
    1 FOR GAME IS OVER WITH RESULT
    -1 FOR GAME IS IN PROGRESS
    O GAME IS OVER AND NO RESULT
**********************************************/

int checkwin()
{
       std::set<std::size_t>::iterator it;
       std::set<std::size_t>::iterator it2;
       for (int i = 0; i<game.size();i++)
       {
        
        std::set<std::size_t> connections = game.neighbors(i);
        
       for (it = connections.begin( ); it != connections.end( ); ++it)
        {
          size_t c1 = game.is_edge(i,*it);
          std::set<std::size_t> NextConnection = game.neighbors(*it);

            for (it2 = NextConnection.begin( ); it2 != NextConnection.end( ); ++it2)
            {
                if(c1 == game.is_edge(*it,*it2))
                {
                    return 1;
                }
            }

        }
        
        if(game.size()==9)
            return 0;
       
       }
       return -1;
       
}


// Function that connects markers and add weight to edges specifying connection type.
void connect(){
    int place = 0;
    
    for(int place = 0;place<game.size();place++)
    {
        for (int cursor = place+1; cursor<game.size();cursor++)
        {
        if((game[cursor].getType())==(game[place].getType()))
        {
            // Makes connections if in same row.
            if((game[cursor].getRow()==game[place].getRow())&&(game[cursor].getCol()==game[place].getCol()+1))
            {
                //weighted edge, 1 for row, 2 for col, 3 for left diagonal, 4 for right diagonal
                game.add_edge(place,cursor,1);
            }

            else if((game[cursor].getRow()==game[place].getRow())&&(game[cursor].getCol()+1==game[place].getCol()))
            {
                //weighted edge, 1 for row, 2 for col, 3 for left diagonal, 4 for right diagonal
                game.add_edge(cursor,place,1);
            }

            //Make connection if in the same column.
           if((game[cursor].getCol()==game[place].getCol())&&(game[cursor].getRow()==game[place].getRow()+1))
            {
                //weighted edge, 1 for row, 2 for col, 3 for left diagonal, 4 for right diagonal
                game.add_edge(place,cursor,2);
            }

            else if((game[cursor].getCol()==game[place].getCol())&&(game[cursor].getRow()+1==game[place].getRow()))
            {
                //weighted edge, 1 for row, 2 for col, 3 for left diagonal, 4 for right diagonal
                game.add_edge(cursor,place,2);
            }
            
        // makes connections in left diagonals
            if((game[cursor].getRow()==game[place].getRow()+1)&&(game[cursor].getCol()+1==game[place].getCol()))
            {
                game.add_edge(place,cursor,3);  
            }

            else if((game[cursor].getRow()+1==game[place].getRow())&&(game[cursor].getCol()==game[place].getCol()+1))
            {
                game.add_edge(cursor,place,3);  
            }
            
            // Makes connections in right diagonal
            if((game[cursor].getRow()==game[place].getRow()+1)&&(game[cursor].getCol()==game[place].getCol()+1))
            {
                game.add_edge(place,cursor,4);
                
            }

           else if((game[cursor].getRow()+1==game[place].getRow())&&(game[cursor].getCol()+1==game[place].getCol()))
            {
                game.add_edge(cursor,place,4);
                
            }
        }
        }
    }
    
}

/*******************************************************************
     FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
********************************************************************/


void board()
{
    system("clear");
    cout << "\n\n\tTic Tac Toe\n\n";

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

/*******************************************************************
                END OF PROJECT
********************************************************************/