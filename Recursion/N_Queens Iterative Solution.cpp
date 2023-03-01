
#include<iostream>
#include<vector>
using namespace std;

// Data initialisation

int row_=4,col_=4,q_=4;
vector<vector<bool>> box(row_, vector<bool>(col_, false));
vector<vector<int>> q_dir = {{0, -1}, {-1, 0}, {-1, -1}, {-1, 1}, {0, 1}, {1, 0}, {1, 1}, {1, -1}};

bool isQueenSafe(vector<vector<bool>> &boxes, int r, int c)
{

    for (int d = 0; d < q_dir.size(); d++)
    {
        for (int jump = 1; jump <= boxes.size(); jump++)
        {
            int nr = r + jump * q_dir[d][0];
            int nc = c + jump * q_dir[d][1];

            if (nr >= 0 && nc >= 0 && nr < boxes.size() && nc < boxes[0].size())
            {
                if (boxes[nr][nc])
                    return false;
            }
            else
                break;
        }
    }

    return true;
}

int queen2DCombination(vector<vector<bool>> &boxes, int bn, int qpsf, int tnq, string ans)
{
    if (qpsf == tnq)
    {
        cout << ans << endl;
        return 1;
    }
    int count = 0;

    for (int i = bn; i < boxes.size() * boxes[0].size(); i++)
    {
        int r = i / boxes[0].size();
        int c = i % boxes[0].size();
        if (!boxes[r][c] && isQueenSafe(boxes, r, c))
        {
            boxes[r][c] = true;
            count += queen2DCombination(boxes, i + 1, qpsf + 1, tnq,
                                        ans + "(" + to_string(r) + ", " + to_string(c) + ") ");
            boxes[r][c] = false;
        }
    }

    return count;
}

int main(){
    
    cout<<"\n N_queens solution iterative method :"<<endl;
    cout<<queen2DCombination(box, 0, 0, q_, "")<<endl;
    
}
