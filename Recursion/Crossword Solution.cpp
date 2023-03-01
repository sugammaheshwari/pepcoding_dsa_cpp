
// Cross_word Problem

#include<iostream>
#include<vector>

using namespace std;

string words[6]={"MATHS","PHYSICS","CHEMISTRY","HISTORY","GEOGRAPHY","CIVICS"};


void insert_horizontal(char grid[10][10],int grid_count[10][10],string word,int c_start,int c_end,int r){
    
    for(int i=c_start;i<=c_end;i++){
        grid_count[r][i]++;
        grid[r][i]=word[i-c_start];
    }
    
}


void remove_horizontal(int grid_count[10][10],int c_start,int c_end,int r){
    
    for(int i=c_start;i<=c_end;i++){
        grid_count[r][i]--;
    }
    
}

void insert_vertical(char grid[10][10],int grid_count[10][10],string word,int r_start,int r_end,int c){
    
    for(int i=r_start;i<=r_end;i++){
        grid_count[i][c]++;
        grid[i][c]=word[i-r_start];
    }
    
}

void remove_vertical(int grid_count[10][10],int r_start,int r_end,int c){
    
    for(int i=r_start;i<=r_end;i++){
        grid_count[i][c]--;
    }
    
}

bool check_horizontal_insertion(char grid[10][10],int grid_count[10][10],string word,int c_start,int r){
    
    int word_len=int(word.length());
    if(c_start+word_len>10) return false;
    
    int i=c_start;
    while(i<c_start+word_len){
        if(grid_count[r][i]==-1) return false;
        if(grid_count[r][i]==1 && grid[r][i]!=word[i-c_start]) return false;
        i++;
    }
    
    if(i!=10)
        if(grid_count[r][i]!=-1) return false;

    return true;
}


bool check_vertical_insertion(char grid[10][10],int grid_count[10][10],string word,int r_start,int c){
    
    int word_len=int(word.length());
    if(r_start+word_len>10) return false;
    
    int i=r_start;
    while(i<r_start+word_len){
        if(grid_count[i][c]==-1) return false;
        if(grid_count[i][c]==1 && grid[i][c]!=word[i-r_start]) return false;
        i++;
    }
    
    if(i!=10)
        if(grid_count[i][c]!=-1) return false;

    return true;
}


void find_solution_crossword(char grid[10][10],int grid_count[10][10],int sub_placed){
    
    if(sub_placed==6){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++)
                cout<<grid[i][j]<< "  ";
            cout<<endl;
        }
        return;
    }
    
    for(int i=0;i<100;i++){
        
        int r=i/10;
        int c=i%10;
        
        if(grid[r][c]!=-1){
            string word_to_be_placed=words[sub_placed];
            int len=int(word_to_be_placed.length())-1;
            
            if(check_horizontal_insertion(grid,grid_count,word_to_be_placed,c,r)){
                insert_horizontal(grid,grid_count,word_to_be_placed,c,c+len,r);
                find_solution_crossword(grid, grid_count, sub_placed+1);
                remove_horizontal(grid_count,c,c+len,r);
            }
            
            if(check_vertical_insertion(grid,grid_count,word_to_be_placed,r,c)){
                insert_vertical(grid,grid_count,word_to_be_placed,r,r+len,c);
                find_solution_crossword(grid, grid_count, sub_placed+1);
                remove_vertical(grid_count,r,r+len,c);
            }
        }
        
    }
    
}




int main(){
    
    char  grid[10][10]=            {{'+','+','+','+','+','+','+','+','+','-'} ,
                                    {'-','+','+','+','+','+','+','+','+','-'},
                                    {'-','-','-','-','-','-','-','+','+','-'},
                                    {'-','+','+','+','+','+','+','+','+','-'},
                                    {'-','+','+','+','+','+','+','+','+','-'},
                                    {'-','+','+','+','+','-','-','-','-','-'},
                                    {'-','-','-','-','-','-','+','+','+','-'},
                                    {'-','+','+','+','+','+','+','+','+','-'},
                                    {'+','-','-','-','-','-','-','-','-','-'},
                                    {'+','+','+','+','+','+','+','+','+','+'}};


           
    int grid_count[10][10]={    {-1,-1,-1,-1,-1,-1,-1,-1,-1,0},
                                {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                                {0,0,0,0,0,0,0,-1,-1,0},
                                {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                                {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                                {0,-1,-1,-1,-1,0,0,0,0,0},
                                {0,0,0,0,0,0,-1,-1,-1,0},
                                {0,-1,-1,-1,-1,-1,-1,-1,-1,0},
                                {-1,0,0,0,0,0,0,0,0,0},
                                {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1} };



    find_solution_crossword(grid,grid_count,0);
    
}
