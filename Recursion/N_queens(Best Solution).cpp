
// N queens problem solution best_solution

#include<iostream>
#include<vector>
using namespace std;

// data initialization

int row_ = 4, col_ = 4, queen_ = 4;
vector<bool> row(row_, false);
vector<bool> col(col_, false);
vector<bool> diag(row_ + col_ - 1, false);
vector<bool> antiDiag(row_ + col_ - 1, false);
vector<vector<bool>> box(row_, vector<bool>(col_, false));
int boxSize = col_;


void mark_queen(int r, int c)
{
    row[r] = true;
    col[c] = true;
    diag[r + c] = true;
    antiDiag[r - c + boxSize - 1] = true;
}

void unmark_queen(int r, int c)
{
    row[r] = false;
    col[c] = false;
    diag[r + c] = false;
    antiDiag[r - c + boxSize - 1] = false;
}


bool isQueenSafe(int r, int c)
{
    return !row[r] && !col[c] && !diag[r + c] && !antiDiag[r - c + boxSize - 1];
}

int nqueen_bestWala(int row, int tnq, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int col = 0; col < col_; col++)
    {
        if (isQueenSafe(row, col))
        {
            mark_queen(row, col);

            count += nqueen_bestWala(row + 1, tnq - 1, ans + "(" + to_string(row) + ", " + to_string(col) + ") ");

            unmark_queen(row, col);
        }
    }
    return count;
}

int main(){
    
    cout<<"nqueens best sol:"<<endl;
    cout<<nqueen_bestWala(row_,queen_, "");
}
