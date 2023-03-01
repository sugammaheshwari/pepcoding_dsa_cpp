
// sudoko problem , my solution 

#include<iostream>
using namespace std;


char sub_grid_labels[9][9]={{'a','a','a','b','b','b','c','c','c'},
                            {'a','a','a','b','b','b','c','c','c'},
                            {'a','a','a','b','b','b','c','c','c'},
                            {'d','d','d','e','e','e','f','f','f'},
                            {'d','d','d','e','e','e','f','f','f'},
                            {'d','d','d','e','e','e','f','f','f'},
                            {'g','g','g','h','h','h','i','i','i'},
                            {'g','g','g','h','h','h','i','i','i'},
                            {'g','g','g','h','h','h','i','i','i'}};


bool loop_checker(int g[9][9],int r_beg,int r_end,int c_beg,int c_end,int n){
    
    for(int i=r_beg;i<=r_end;i++){
        for(int j=c_beg;j<=c_end;j++){
            if(g[i][j]==n)
                return false;
        }
    }
    
    return true;
}


bool is_safe_subgrid(int g[9][9],int r,int c,int n){
    
    if(g[r][c]!=0) return false;
    
    char sub_label=sub_grid_labels[r][c];
    switch (sub_label) {
        case 'a':
            return( loop_checker(g,0, 2, 0, 2, n));
            
        case 'b':
            return( loop_checker(g,0, 2, 3, 5, n));
            
        case 'c':
        return( loop_checker(g,0, 2, 6, 8, n));
            
        case 'd':
        return( loop_checker(g,3, 5, 0, 2, n));
            
        case 'e':
            return( loop_checker(g,3, 5, 3, 5, n));
            
        case 'f':
            return( loop_checker(g,3, 5, 6, 8, n));
            
        case 'g':
            return( loop_checker(g,6, 8, 0, 2, n));
            
        case 'h':
            return( loop_checker(g,6, 8, 3, 5, n));
            
        case 'i':
            return( loop_checker(g,6, 8, 6, 8, n));
            
        default:
            return (0);
    }
    
}


bool is_safe_row_and_col(int g[9][9],int r,int c,int n){
    
    
    if(g[r][c]!=0) return false;
    
    for(int i=0;i<9;i++){
        if(g[r][i]==n) return false;
        if(g[i][c]==n) return false;
    }
    
    return true;
    
}


void sudoko_solver(int grid[9][9],int i){
    
    if(i==81){
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    int r=i/9;
    int c=i%9;
            if(grid[r][c]==0){
                for(int num_to_insert=1;num_to_insert<=9;num_to_insert++){
                    if( is_safe_row_and_col(grid,r, c, num_to_insert) && is_safe_subgrid(grid,r, c, num_to_insert) ){
                        grid[r][c]=num_to_insert;
                        sudoko_solver(grid,i+1);
                        grid[r][c]=0;
                    }
                    
                }
                
            }
            else{
                sudoko_solver(grid,i+1);
            }
    
}

int main(){
    
    


    int grid[9][9]={{3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    
    sudoko_solver(grid, 0);
    
}
