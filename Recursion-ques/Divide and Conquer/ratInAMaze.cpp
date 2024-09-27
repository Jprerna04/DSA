#include<iostream>
#include<vector>
using namespace std;

bool issafe(int row,int col,int i, int j,vector<vector<bool>>&visited, int maze[][4]){
    if ( ((i>=0 && i<row) && (j>=0 && j<col))
    && (maze[i][j]==1) && 
    (visited[i][j]==false)){
        return true;
    }
    else {
    return false;
  }
}

void findmaze(int maze[4][4],int row,int col,int i,int j,vector<vector<bool>>&visited,vector<string>&path, 
string output){
    //base condition
    if (i==row-1 && j==col-1){
        path.push_back(output);
        return;
    }

    //movement
    //down 
    if (issafe(row,col,i+1,j,visited, maze)){
        visited[i+1][j]=true;
        //recursion
        findmaze(maze, row, col, i+1, j, visited, path, output+'D');
        //backtrack
        visited[i+1][j]=false;
    }

    //up
    if (issafe(row,col,i-1,j,visited, maze)){
        visited[i-1][j]=true;
        //recursion
        findmaze(maze, row, col, i-1, j, visited, path, output+'U');
        //backtrack
        visited[i-1][j]=false;
    }

    //left
    if (issafe(row,col,i,j-1,visited, maze)){
        visited[i][j-1]=true;
        //recursion
        findmaze(maze, row, col, i, j-1, visited, path, output+'L');
        //backtrack
        visited[i][j-1]=false;
    }

    //right
    if (issafe(row,col,i,j+1,visited, maze)){
        visited[i][j+1]=true;
        //recursion
        findmaze(maze, row, col, i, j+1, visited, path, output+'R');
        //backtrack
        visited[i][j+1]=false;
    }
    
}

int main(){
    int maze[4][4] = { {1,0,0,0}, 
                 {1,1,0, 1},
                 {1,1,0,0},
                 {0,1,1,1}};
    int row=4;
    int col=4;
    if (maze[0][0]==0){
        cout<<"no path found";
    }
    vector<vector<bool>>visited(row, vector<bool>(col,false));
    visited[0][0] = true;
    vector<string> path;
    string output = "";
    findmaze(maze,row,col,0,0,visited,path, output);
    for (auto i: path){
        cout<<i<<" ";
    }
    cout<<endl;
   if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
    }
    return 0;
}