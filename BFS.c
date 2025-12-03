#include<stdio.h>

typedef char VertexType;  //顶点数据类型用char
typedef int EdgeType;  //边的数据类型int

#define MAXSIZE 100


typedef struct 
{
    VertexType vertex[MAXSIZE];  //邻接矩阵 一维数组
    EdgeType arc[MAXSIZE][MAXSIZE];  //边的数组 二维
    int vertex_num;  //顶点数量
    int edge_num;  /* 边的数量 */
}Mat_Graph;  //邻接矩阵的图 matrix

int visited[MAXSIZE];  //记录顶点是否被遍历过
int front = 0;
int rear = 0;
int queue[MAXSIZE];



//创建一个图
void create_graph(Mat_Graph*G)  //创建一个图
{
    G->vertex_num = 9;
    G->edge_num = 15;
    G->vertex[0] = 'A';
    G->vertex[1] = 'B';
    G->vertex[2] = 'C';
    G->vertex[3] = 'D';
    G->vertex[4] = 'E';
    G->vertex[5] = 'F';
    G->vertex[6] = 'G';
    G->vertex[7] = 'H';
    G->vertex[8] = 'I';

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j= 0; j < G->vertex_num; j++)
        {
            G->arc[i][j] = 0; /* 给二维数组的9*9个格子都赋值为0 */
        }
        
    }
    //A-B A-F连线
G->arc[0][1] = 1;
G->arc[0][5] = 1;

//B-C B-G B-I
G->arc[1][2] = 1;
G->arc[1][6] = 1;
G->arc[1][8] = 1;

//C-D C-I
G->arc[2][3] = 1;
G->arc[2][8] = 1;

//D-E D-G D-H D-I
G->arc[3][4] = 1;
G->arc[3][6] = 1;
G->arc[3][7] = 1;
G->arc[3][8] = 1;

//E-F E-H
G->arc[4][5] = 1;
G->arc[4][7] = 1;

//F-G
G->arc[5][6] = 1;

//G-H
G->arc[6][7] = 1;

for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j= 0; j < G->vertex_num; j++)
        {
            G->arc[j][i] = G->arc[i][j];   /* 邻接矩阵是对称的 把ij赋值给ji */
        }
        
    }

    
}



//bfs核心代码
void bfs(Mat_Graph G)
{
    int i = 0;
    visited[i] = 1;
    printf("%c\n",G.vertex[i]);
    queue[rear] = i;
    rear++;
    while(front != rear)  //首尾不相同 即队列不为空
    {
        i = queue[front];  //出队
        front++;
        for(int j = 0; j < G.vertex_num; j++)
        {
            if(G.arc[i][j] == 1 &&visited[j] == 0)
            {
                visited[j] = 1;
                printf("%c\n", G.vertex[j]);
                queue[rear] = j;
                rear++;

            }
        }
        
    }


}


int main(int argc,char const *argv[])
{
    Mat_Graph G;
    create_graph(&G);

    for (int i = 0; i < G.vertex_num; i++)
    {
        visited[i] = 0;  //访问初始化
    }
    bfs(G);
    return 0;

}