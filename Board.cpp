#include <algorithm>
#include <iostream>
#include <stdexcept>
using namespace std;
#include "Board.hpp"
using namespace ariel;

void Board::resize(unsigned int row, unsigned col){
    board.resize(col, vector<char>(row, '_'));    //resize the the colums and fills them with vector of the given row size filled with '_'
    //resize the rest of the colums and rows
    for(int i = 0; i <= length; i++){
    	board.at(i).resize(row, '_');
    	}
    //set the new bounderies
    length = col-1;
    height = row-1;
}
//post a message on the board on the given loacation and direction
void Board::post(unsigned int row, unsigned int col, Direction dirc, string msg){
    int size = msg.size();
    //check for valid message
    if(size == 0){
    	throw invalid_argument("empty message");
    }
    //check for directions
    if(dirc == Direction::Horizontal){
    	//check if the loaction is within bounds
        if(col+size-1 > length){
            //resize according to the needed bounderies
            resize(max(row,height)+1, col+size);
            }
        //write the message on the board
        for(int i = 0; i < size; i++){
            board.at(col+i).at(row) = msg.at(i);
            }
        }
    else if(dirc == Direction::Vertical){
    	//check if the loaction is within bounds
        if(row+size-1 > height){
            //resize according to the needed bounderies
            resize(row+size, max(col,length)+1);
            }
        for(int i = 0; i < size; i++){
            //write the message on the board
            board.at(col).at(row+i) = msg.at(i);
            }
        }
    else{
    	    throw invalid_argument("Invalid direction");
    }
}
//returns the message on the given loaction of the board            
string Board::read(unsigned int row, unsigned int col, Direction dirc, unsigned int len){
    //check validity of len
    if(len == 0){
    	throw invalid_argument("message length must be greater than 0");
    }
    string msg;
    //check if the location is within bounds
    if(col <= length && row <= height){
        msg = board.at(col).at(row);
        }
    //if not the message should be '_'*len
    else{
        msg = "_";
        for(int i = 1; i < len; i++){
            msg += "_";
            }
        return msg;
        }
    //check for directions
    if(dirc == Direction::Vertical){
    	//as long as the message is inside the board read it
        for(unsigned int r = row+1; r < row+len && r <= height; r++){
            msg += board.at(col).at(r);
            }
        }
    else if(dirc == Direction::Horizontal){
    	//as long as the message is inside the board read it
        for(unsigned int c = col+1; c < col+len && c <= length; c++){
            msg += board.at(c).at(row);
            }
        }
    else{
            throw invalid_argument("Invalid direction");	
        }
    int msg_len = msg.size();
    //if the message was not completly in the bounds of the board add the missing letters with '_' 
    if(msg_len < len){
        for(int i = msg_len; i < len; i++){
            msg += "_";
     	    }  
        }
    return msg;
}
            
void Board::show(){
    //moves on every index of the vector table and print it
    for(int i = 0; i <= length; i++){
        for(int j = 0; j <= height; j++){
             cout << board.at(i).at(j);
           }
        cout << "\n";
        }    
}

