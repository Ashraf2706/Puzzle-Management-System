// UMBC - CMSC 341 - Spring 2024 - Proj0
#include "puzzle.h"
Puzzle::Puzzle(int rows, int cols){
    if((rows < DEFSIZE) || (cols < DEFSIZE)){// checking if the number of rows and columns are less than the default size
        m_puzzle = nullptr;
        m_numRows = MIN;
        m_numCols = MIN;
        return;
    }

    m_numRows = rows; 
    m_numCols = cols;
    m_puzzle = new char* [rows]; //allocate memory for rows
    for(int i = 0; i < rows; i++){
        m_puzzle[i] = new char[cols]; // allocate memory for columns
        for (int j = 0; j < cols; j++) {
            m_puzzle[i][j] = 0; // initialize all elements to 0
        }
    }
}

Puzzle::~Puzzle(){
    clear();
}

void Puzzle::clear(){// clearing the puzzle
    if(m_puzzle != nullptr){
        for(int i = 0; i < m_numRows; i++){
            delete [] m_puzzle[i];
        }
        delete [] m_puzzle;
    m_numRows = MIN;
    m_numCols = MIN;
    m_puzzle = nullptr;
    }
}

bool Puzzle::reCreate(int rows, int cols, int seed){
    if((rows < DEFSIZE) || (cols < DEFSIZE)){
        return false;
    }
    clear();

    m_numRows = rows; 
    m_numCols = cols;
    m_puzzle = new char* [rows]; //allocate memory for rows
    for(int i = 0; i < rows; i++){
        m_puzzle[i] = new char[cols]; // allocate memory for columns
        for (int j = 0; j < cols; j++) {
            m_puzzle[i][j] = 0; // initialize all elements to 0
        }
    }

    fill(seed); // filling the puzzle with new values
    return true;
}

void Puzzle::fill(int seed){
    Random randGen(MIN, MAX);// creating a random number generator
    randGen.setSeed(seed);// setting the seed for the random number generator

    for (int i = 0; i < m_numRows; i++){
        Random numSeperators(0, 3, NORMAL);// creating a random number generator for the number of separators
        int num = numSeperators.getRandNum(); // getting a random number of separators

        for (int j = 0; j < m_numCols; j++){
            int rand_index = randGen.getRandNum(); // getting a random index
            m_puzzle[i][j] = ALPHA[rand_index];
        }

        Random position(0, m_numCols - 1, NORMAL);
        for (int k = 0; k < num; k++){
            int randCol = position.getRandNum();
            m_puzzle[i][randCol] = SEPARATOR; // setting the value of the puzzle at the current position to the separator
        }
    }
}

Puzzle::Puzzle(const Puzzle& rhs){
    if(rhs.m_puzzle == nullptr){// checking if the puzzle to be copied is empty
        m_puzzle = nullptr;
        m_numRows = MIN;
        m_numCols = MIN;
        return;
    }
    m_numRows = rhs.m_numRows;
    m_numCols = rhs.m_numCols;
    m_puzzle = new char* [m_numRows];
    for(int i = 0; i < m_numRows; i++){
        m_puzzle[i] = new char[m_numCols]; // allocate memory for column
    }
    for(int i = 0; i < m_numRows; i++){
        for (int j = 0; j < m_numCols; j++){
            m_puzzle[i][j] = rhs.m_puzzle[i][j];
        }
    }
}

const Puzzle& Puzzle::operator=(const Puzzle& rhs){
    if (this == &rhs){
        return *this;
    }
    //clear();
    for(int i = 0; i < m_numRows; i++){
        delete [] m_puzzle[i];
    }
    delete [] m_puzzle;
    m_puzzle = nullptr;

    m_numRows = rhs.m_numRows;
    m_numCols = rhs.m_numCols;
    m_puzzle = new char* [m_numRows];
    for(int i = 0; i < m_numRows; i++){
        m_puzzle[i] = new char[m_numCols]; // allocate memory for column
    }
    for(int i = 0; i < m_numRows; i++){
        for (int j = 0; j < m_numCols; j++){
            m_puzzle[i][j] = rhs.m_puzzle[i][j];
        }
    }
    return *this;
}

bool Puzzle::appendRight(const Puzzle& rhs){
    if(m_numRows != rhs.m_numRows){
        return false;
    }
    // clear();
    char **newPuzzle = new char*[m_numRows];
    for (int i = 0; i < m_numRows; i++){
        newPuzzle[i] = new char[m_numCols + rhs.m_numCols];
        for(int j = 0; j < m_numCols; j++){
            newPuzzle[i][j] = m_puzzle[i][j];
        }
        for(int k = 0; k < rhs.m_numCols; k++){
            newPuzzle[i][m_numCols + k] = rhs.m_puzzle[i][k];
        }
    }

    for(int i = 0; i < m_numRows; i++){
            delete [] m_puzzle[i];
    }
    delete [] m_puzzle;
    m_puzzle = nullptr;

    m_puzzle = newPuzzle;
    m_numCols += rhs.m_numCols;
    return true;
}

bool Puzzle::appendBottom(const Puzzle& bottom){
    if(m_numCols != bottom.m_numCols){
        return false;
    }
    char **newPuzzle = new char* [m_numRows + bottom.m_numRows];
    for (int i = 0; i < m_numRows + bottom.m_numRows; i++){
        newPuzzle[i] = new char[m_numCols];
        if(i < m_numRows) {
            for(int j = 0; j < m_numCols; j++){
                newPuzzle[i][j] = m_puzzle[i][j];
            }
        } else{
            for(int j = 0; j < m_numCols; j++){
                newPuzzle[i][j] = bottom.m_puzzle[i - m_numRows][j];
            }
        }

    }

    for(int i = 0; i < m_numRows; i++){
        delete [] m_puzzle[i];
    }
    delete [] m_puzzle;
    m_puzzle = nullptr;

    m_puzzle = newPuzzle; // set new puzzle
    m_numRows += bottom.m_numRows; // update number of rows
    return true;
}

void Puzzle::dump(){
    int i=0;
    int j=0;
    cout << "   ";
    for (int k=0;k<m_numCols;k++){
        if ((k+1) < 10) cout << "0";
        cout << (k+1) << " ";
    }
    cout << endl; 
    while(i<m_numRows){
        if ((i+1) < 10) cout << "0";
        cout << (i+1) << " ";
        while(j<m_numCols){
            if (m_puzzle[i][j] == '#')
                cout << "\033[1;31m\u2731\033[0m" << "  ";   // this prints HEAVY ASTERISK as separators
            else
                cout << m_puzzle[i][j] << "  ";
            j++;
        }
        cout << endl;
        j=0;
        i++;
    }
    cout << endl;
}