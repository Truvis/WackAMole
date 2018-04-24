#include "Area.h"
#include "Cell.h"
#include "Mask.h"

Area::Area( int high,int wide,  int down,  int over)
         : Page(high,    wide   ,   down,      over )
         , high(high),   wide(wide),down(down),over(over)
{
    area = new Cell**[high];                        // a new matrix of rows of cols of cell pointers
    for(int row = 0; row<high ; ++row) {
       area[row]= new Cell*[wide];                  // a new row of to be filled columns of cell*
       for(int col=0;col<wide ; ++col)
          area[row][col] = new Cell(  row,col       // new col filled with a cell pointer
                         , Mask::Site(row*down      // tell the cell its location on the page
                                     ,col*over));   // cell*wide; count of letters over the cell is
    }
}

Area::~Area()
{
    for(int row = 0; row<high ; ++row) {
       for(int col=0;col<wide ; ++col) delete area[row][col];
       delete area[row];
    }
    delete area;
}

void Area::Show() {
    for(   int row=0;row < high;++row) {
       for(int col=0;col < wide;++col)
          area[row] [col]->Show(this);
    }
}

// mod does not work well with negatives in C
// use the +high and +wide to prevent crash from going off screen
// this keeps it smaller and without using if statements.
Cell*Area::Upon(int row, int col) {
    return  area[(row+high)%high][(col+wide)%wide];
}

// Pass the memory location of the area where
// the club is currently located.
// Adjust the values of that object by passing in
// the y and x movements.
Cell* Area::Move(Cell*currentcell,int Yvalue,int Xvalue){
    return Upon(currentcell->Down()+Yvalue,currentcell->Over()+Xvalue);
}

Cell*Area::FindingRandomly(SLOT having, SLOT nothaving){
    /// adding holes.
    /// slot check having this
    for(int t=0;t<TRYS;t++){
        int row = rollHigh.Invoke();
        int col = rollWide.Invoke();
        Cell* cell = Upon(row,col);
        /// if found. check to see if not having something there.
        if(having==ZERO || cell->Have(having)){
            /// nothing found add.
            if(nothaving==ZERO || !cell->Have(nothaving)){
                return cell;

            }
        }
    }
    return 0;
}
