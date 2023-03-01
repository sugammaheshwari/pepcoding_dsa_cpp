
/* Flood fill Algorithm – how to implement fill() in paint?

Input:
       screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                      };
    x = 4, y = 4, newColor = 3
 
The values in the given 2D screen indicate colors of the pixels.
x and y are coordinates of the brush, newColor is the color that
should replace the previous color on screen[x][y] and all surrounding
pixels with same color.

Output:
Screen should be changed to following.
       screen[M][N] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 3, 3, 3, 3, 0, 1, 0},
                      {1, 1, 1, 3, 3, 0, 1, 0},
                      {1, 1, 1, 3, 3, 3, 3, 0},
                      {1, 1, 1, 1, 1, 3, 1, 1},
                      {1, 1, 1, 1, 1, 3, 3, 1},
                      };
 all moves allowed up ,left ,right, down , diagnol ( all four directions );
 
*/

// solving using DFS

#include<iostream>
#include<vector>
using namespace std;


//input
vector<vector < int> > image = {{1, 1, 1, 1, 1, 1, 1, 1},
                                {1, 1, 1, 1, 1, 1, 0, 0},
                                {1, 0, 0, 1, 1, 0, 1, 1},
                                {1, 2, 2, 2, 2, 0, 1, 0},
                                {1, 1, 1, 2, 2, 0, 1, 0},
                                {1, 1, 1, 2, 2, 2, 2, 0},
                                {1, 1, 1, 1, 1, 2, 1, 1},
                                {1, 1, 1, 1, 1, 2, 2, 1},
                               };


int r_len=(int)image.size();
int c_len=(int)image[0].size();

vector < vector <int> > visited ;

vector <vector <int> > neighbours(int r,int c){
    vector <vector <int> > list ;
    list.push_back({r,c+1});
    list.push_back({r,c-1});
    list.push_back({r+1,c});
    list.push_back({r-1,c});
    list.push_back({r+1,c+1});
    list.push_back({r-1,c-1});
    list.push_back({r-1,c+1});
    list.push_back({r+1,c-1});
    
    return(list);
    
}

void flood_fill(int r,int c,int color , int replace_color){
    // flood fills the given segement starting from the r,c index
    
    if(r<0 || r>= r_len) return;
    if(c<0 || c>= c_len) return;
    if( image[r][c]!=color) return;
    
    image[r][c]=replace_color;
    
    vector<vector <int> > moves=neighbours(r, c);
    
    visited.push_back({r,c});
    
    // code for searching if the move is in visited vector
    // if not call return ( call floodfill with current moves r and column ;
    //end
}

void display_vector(vector<vector<int>>vec){
                    
                    for (int i = 0; i < 8; i++) {
                        for (int j = 0; j < 8; j++){
                            cout<< vec[i][j]<< " ";
                        }
                        cout<< "\n";
                    }
                    
                    
                    }

int main(){
   
   /* cout<<endl<<"before flood fill:"<<endl;
    display_vector(image);
    flood_fill(4, 4, 2, 3);
    cout<<endl<<"after flood fill:"<<endl;
    display_vector(image);
*/
    
    visited.push_back({10,2});
}
