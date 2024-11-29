// UMBC - CMSC 341 - Spring 2024 - Proj0
#include "puzzle.h"

class Tester{//this is your tester class, you add your test functions in this class
    public:
    bool testCopyConstructorNormal(const Puzzle& puzzle);
    bool testConstructorErrorCase();
    bool testConstructorNormalCase();
    bool testReCreateNormalCase();
    bool testReCreateErrorCase();
    bool testAppendRightNormalCase();
    bool testAppendRightErrorCase();
    bool testAppendRightNonEmptyToEmpty();
    bool testAppendRightEmptyToNonEmpty();
    bool testAppendRightOfItself();
    bool testAppendBottomNormalCase();
    bool testAppendBottomErrorCase();
    bool testAppendBottomNonEmptyToEmpty();
    bool testAppendBottomEmptyToNonEmpty();
    bool testAppendBottomOfItself();
    bool testAssignmentOperatorEdgeCase();
    bool testAssignmentOperatorNormalCase();
    
};

int main() {
    Tester tester;
    {
        //test deep copy, object with many members
        Puzzle p1(10,12);
        cout << "Testing Copy Constructor (normal case): same values, same size, different pointers (deep copy):" << endl;
        if (tester.testCopyConstructorNormal(p1)) cout << "\tCopy constructor passed!" << endl;
        else cout << "\tCopy constructor failed!" << endl;

        cout << "Testing Constructor Error Case: ";
        if(tester.testConstructorErrorCase()){
            cout << "Passed!" << endl;
        }else{
            cout << "Failed" << endl;
        }
        cout << "Testing Constructor Normal Case: ";
        if(tester.testConstructorNormalCase()){ 
            cout << "Passed!"<< endl;
        }else{ 
            cout << "Failed!"<< endl;
        }
        cout <<  "Testing Recreate Normal Case: ";
        if(tester.testReCreateNormalCase()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Recreate Error Case: ";
        if(tester.testReCreateErrorCase()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Right Normal Case: ";
        if(tester.testAppendRightNormalCase()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Right Error Case: ";
        if(tester.testAppendRightErrorCase()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Right Non Empty to Empty Case: ";
        if(tester.testAppendRightNonEmptyToEmpty()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Right Empty to Non Empty Case: ";
        if(tester.testAppendRightEmptyToNonEmpty()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Right to Itself Case: ";
        if(tester.testAppendRightOfItself()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Assignment Operator Edge Case: ";
        if(tester.testAssignmentOperatorEdgeCase()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Assignment Operator Normal Case: ";
        if(tester.testAssignmentOperatorNormalCase()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Bottom Normal Case: ";
        if(tester.testAppendBottomNormalCase()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Bottom Error Case: ";
        if(tester.testAppendBottomErrorCase()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Bottom Non Empty to Empty Case: ";
        if(tester.testAppendBottomNonEmptyToEmpty()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Bottom Empty to Non Empty Case: ";
        if(tester.testAppendBottomEmptyToNonEmpty()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
        cout <<  "Testing Append Bottom to Itself Case: ";
        if(tester.testAppendBottomOfItself()){
            cout << "Passed!"<< endl;
        }else{
            cout << "Failed" << endl;
        }
    }
    
    // {
    //     Puzzle p1(10,10);
    //     p1.fill(10+time(0));
    //     cout << "\ndump of p1 after creation:\n\n"; p1.dump();
        
    //     Puzzle p2(10,10);
    //     p2.fill(5+time(0));
    //     cout << "\ndump of p2 after creation:\n\n"; p2.dump();
    //     //p1.appendBottom(p2);
    //     p1.appendRight(p2);
        
    //     cout << "\ndump of p1 after append:\n\n"; p1.dump();
    //     cout << "\ndump of p2 after append:\n\n"; p2.dump();
    //     // cout << endl;
    // }
    return 0;
}

bool Tester::testCopyConstructorNormal(const Puzzle& puzzle){
    Puzzle copy(puzzle);
    if (puzzle.m_numCols == copy.m_numCols && 
        puzzle.m_numRows == copy.m_numRows &&
        puzzle.m_puzzle != copy.m_puzzle){
        for (int i=0;i<puzzle.m_numRows;i++){
            for (int j=0;j<puzzle.m_numCols;j++)
            {
                if ((puzzle.m_puzzle[i][j] != copy.m_puzzle[i][j]) ||   //check the value
                    (puzzle.m_puzzle[i] == copy.m_puzzle[i])){            //check the ith pointer
                    return false;
                }
            }
        }
        return true;// everything is correct
    }
    else return false;//everthing else
}

bool Tester::testConstructorErrorCase(){
    bool res = true;

    Puzzle obj(-5, -10);
    res = res && (obj.m_puzzle == nullptr);
    res = res && (obj.m_numRows == MIN);
    res = res && (obj.m_numCols == MIN);

    return res;
}

bool Tester::testConstructorNormalCase(){
    bool res = true;

    Puzzle obj(12,12);
    res = res && (obj.m_puzzle != nullptr);
    res = res && (obj.m_numRows == 12);
    res = res & (obj.m_numCols == 12);

    return res;
}

bool Tester::testReCreateNormalCase(){
    bool res = true;
    Puzzle obj(10,10);
    obj.reCreate(12,14,123);
    res = res && (obj.m_puzzle != nullptr);
    res = res && (obj.m_numRows == 12);
    res = res && (obj.m_numCols == 14);

    return res;
}

bool Tester::testReCreateErrorCase(){
    bool res = true;
    Puzzle obj(10,10);
    res = res && !obj.reCreate(8,8,123);
    // res = res && (obj.m_puzzle == nullptr);
    // res = res && (obj.m_numRows == 10);
    // res = res && (obj.m_numCols == 10);

    return res;
}

bool Tester::testAppendRightNormalCase(){
    bool res = true;
    Puzzle obj1(10, 10);
    Puzzle obj2(10, 10);
    obj1.fill(10 + time(0));
    obj2.fill(5+ time(0));
    obj1.appendRight(obj2);
    // obj1.dump();
    // obj2.dump();

    
    // check if the columns size contains obj1 and obj2 size
    res = res && obj1.m_numCols == 20;

    // check if the items in obj2 are in obj1
    for (int i = 0; i < obj1.m_numRows; i++){
        for (int j = 10; j < obj1.m_numCols; j++){
            res = res && (obj2.m_puzzle[i][j - obj2.m_numCols] == obj1.m_puzzle[i][j]);
        }
    }
    return res;

}

bool Tester::testAppendRightErrorCase(){
    Puzzle obj1(10,10);
    Puzzle obj2(8,10);

    bool res = !obj1.appendRight(obj2);
    return res;
}

bool Tester::testAppendRightNonEmptyToEmpty(){
    Puzzle emptyObj(10,10);
    Puzzle nonemptyObj(10,10);
    nonemptyObj.fill(5 + time(0));

    //append the emptyOnj to nonemptyObj
    nonemptyObj.appendRight(emptyObj);
    //emptyObj.dump();
    //nonemptyObj.dump();

    bool res = nonemptyObj.m_numCols == 20;

    return res;
}

bool Tester::testAppendRightEmptyToNonEmpty(){
    Puzzle emptyObj(10,10);
    Puzzle nonemptyObj(10,10);
    nonemptyObj.fill(5 + time(0));

    //append the nonemptyOnj to emptyObj
    emptyObj.appendRight(nonemptyObj);

    bool res = emptyObj.m_numCols == 20;

    return res;
}

bool Tester::testAppendRightOfItself(){
    Puzzle obj1(10,10);
    obj1.fill(5 + time(0));
    Puzzle obj2(obj1); //copy of obj1

    obj1.appendRight(obj2);
    bool res = obj1.m_numCols == 20;

    //check if the items for the objects are in the right positons
    for(int i = 0; i < obj1.m_numRows; i++){
        for(int j = 0; j < obj2.m_numCols; j++){
            res = res && (obj2.m_puzzle[i][j] == obj1.m_puzzle[i][j]);
        }
    }
    //Check if items from obj1 append correctly after those of obj2
    for(int i = 0; i < obj1.m_numRows; i++){
        for(int j = obj2.m_numCols; j < obj1.m_numCols; j++){
            res = res && (obj1.m_puzzle[i][j] == obj2.m_puzzle[i][j-obj2.m_numCols]);
        }
    }
    return res;
}

bool Tester::testAssignmentOperatorEdgeCase(){
    Puzzle obj1(10,10);
    obj1.fill(10 + time(0)); // Fill obj1 with some content
    
    // Create a new Puzzle object and assign obj1 to it
    Puzzle obj2(10,10);
    obj2 = obj1;
    
    // Check if obj2 has the same size and content as obj1
    bool res = (obj1.m_numRows == obj2.m_numRows) && (obj1.m_numCols == obj2.m_numCols);
    for (int i = 0; i < obj1.m_numRows; ++i) {
        for (int j = 0; j < obj1.m_numCols; ++j) {
            res = res && (obj1.m_puzzle[i][j] == obj2.m_puzzle[i][j]);
        }
    }
    
    return res;
}

bool Tester::testAssignmentOperatorNormalCase(){
    //Create a Puzzle object with a specific size and content
    Puzzle obj1(5, 5);
    obj1.fill(10 + time(0)); 
    
    //Create a new Puzzle object and assign obj1 to it
    Puzzle obj2(5, 5);
    obj2.fill(5 + time(0)); //Fill obj2 with different content
    
    obj2 = obj1;
    
    //Check if obj2 has the same size and content as obj1
    bool res = (obj1.m_numRows == obj2.m_numRows) && (obj1.m_numCols == obj2.m_numCols);
    for (int i = 0; i < obj1.m_numRows; ++i) {
        for (int j = 0; j < obj1.m_numCols; ++j) {
            res = res && (obj1.m_puzzle[i][j] == obj2.m_puzzle[i][j]);
        }
    }
    
    return res; 
}

bool Tester::testAppendBottomNormalCase(){
    Puzzle obj1(10, 10);
    Puzzle obj2(10, 10);
    obj1.fill(10 + time(0));
    obj2.fill(5 + time(0));
    
    obj1.appendBottom(obj2);

    // Check if the rows size contains obj1 and obj2 size
    bool res = obj1.m_numRows == 20;

    // Check if the items in obj2 are in obj1
    for (int i = 10; i < obj1.m_numRows; i++) {
        for (int j = 0; j < obj1.m_numCols; j++) {
            res = res && (obj2.m_puzzle[i - obj2.m_numRows][j] == obj1.m_puzzle[i][j]);
        }
    }
    return res;
}

bool Tester::testAppendBottomErrorCase(){
    Puzzle obj1(10,10);
    Puzzle obj2(10,8);

    bool res = !obj1.appendBottom(obj2);
    return res;
}

bool Tester::testAppendBottomNonEmptyToEmpty(){
    Puzzle emptyObj(10,10);
    Puzzle nonemptyObj(10,10);
    nonemptyObj.fill(5 + time(0));

    //append the emptyOnj to nonemptyObj
    nonemptyObj.appendBottom(emptyObj);
    //emptyObj.dump();
    //nonemptyObj.dump();

    bool res = nonemptyObj.m_numRows == 20;

    return res;
}
bool Tester::testAppendBottomEmptyToNonEmpty(){
    Puzzle emptyObj(10,10);
    Puzzle nonemptyObj(10,10);
    nonemptyObj.fill(5 + time(0));

    //append the nonemptyOnj to emptyObj
    emptyObj.appendBottom(nonemptyObj);

    bool res = emptyObj.m_numRows == 20;

    return res; 
}
bool Tester::testAppendBottomOfItself(){
    Puzzle obj1(10, 10);
    obj1.fill(5 + time(0));
    Puzzle obj2(obj1); // Copy of obj1

    obj1.appendBottom(obj2);

    bool res = obj1.m_numRows == 20;

    // Check if the items for the objects are in the right positions
    for (int i = 0; i < obj2.m_numRows; i++) {
        for (int j = 0; j < obj2.m_numCols; j++) {
            res = res && (obj2.m_puzzle[i][j] == obj1.m_puzzle[i + obj2.m_numRows][j]);
        }
    }
    // Check if items from obj1 append correctly after those of obj2
    for (int i = obj2.m_numRows; i < obj1.m_numRows; i++) {
        for (int j = 0; j < obj1.m_numCols; j++) {
            res = res && (obj1.m_puzzle[i][j] == obj2.m_puzzle[i - obj2.m_numRows][j]);
        }
    }
    return res;
}