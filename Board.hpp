#pragma once

#include <string>
#include <vector>
#include "Direction.hpp"

namespace ariel {
    class Board{
    	unsigned int length = 10;	//the max colum number
    	unsigned int height = 10;	//the max row number
    	std::vector<std::vector<char>> board;    //2D vector object for storing the messages
    	void resize(unsigned int row, unsigned col);	//resizes the boared when more space is needed
        public:
            Board(){
            	//create a board with the default size and fills it withh '_'
            	board = std::vector<std::vector<char>>(length+1, std::vector<char>(height+1, '_'));
            }
            //post a message on the board on the given loacation and direction
            void post(unsigned int row, unsigned int col, Direction dirc, std::string msg);
            //returns the message on the given loaction of the board
            std::string read(unsigned int row, unsigned int col, Direction dirc, unsigned int len);
            void show(); //prints the board
    };
}
