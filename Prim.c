#include<stdio.h>
#include<stdlib.h>

typedef char VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAX 0x7fffffff

typedef struct   //构建邻接矩阵
{
    VertexType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;    /* data */
}Mat_Graph;



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
            if (i == j)
            {
                G->arc[i][j] = 0;  //对角线为零
            }
            else
            {
                G->arc[i][j] = MAX;  //不是对角线为无穷  表示暂时没有边
            }            
        }        
    }
    //A-B A-F连线
G->arc[0][1] = 10;
G->arc[0][5] = 11;

//B-C B-G B-I
G->arc[1][2] = 18;
G->arc[1][6] = 16;
G->arc[1][8] = 12;

//C-D C-I
G->arc[2][3] = 22;
G->arc[2][8] = 8;

//D-E D-G D-H D-I
G->arc[3][4] = 20;
G->arc[3][6] = 22;
G->arc[3][7] = 16;
G->arc[3][8] = 21;

//E-F E-H
G->arc[4][5] = 26;
G->arc[4][7] = 7;

//F-G
G->arc[5][6] = 17;

//G-H
G->arc[6][7] = 19;

for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j= 0; j < G->vertex_num; j++)
        {
            G->arc[j][i] = G->arc[i][j];   /* 邻接矩阵是对称的 把ij赋值给ji */
        }        
    }    
}


void prim(Mat_Graph*G)
{
    int i,j,k;
    int min;  //保存最小值
    int weight[MAXSIZE];  //侯选边。
    int vex_index[MAXSIZE];  //值代表出发点  下标代表到达点


    //
    weight[0] = 0;
    vex_index[0] = 0;

    for ( i = 1; i < G->vertex_num; i++)
    {
        weight[i] = G->arc[0][i];  //weight当中放了第一行里面的值 （备选的）
        vex_index[i] = 0;                    
        /* code */
    }

    for (int i = 0; i < G->vertex_num; i++)
    {
        min = MAX;
        j = 0;
        k = 0;
        while (j < G->vertex_num)
        {
            if (weight[j] != 0 && weight[j] < min)
            {
                min = weight[j];
                k = j;
            }
            j++;
        }
        
        printf("(%d,%d)\n", vex_index[k],k);  //两个数 第一个是起点的字母值 第二个是连线终点的字母值
        printf("(%c,%c)\n",G->vertex[vex_index[k]],G->vertex[k]);
        weight[k] = 0;

        for ( j = 0; j < G->vertex_num; j++)
        {
            if (weight[j] != 0 && G->arc[k][j] < weight[j])
            {
                weight[j] = G->arc[k][j];
                vex_index[j] = k;
            }
            
        }
        

    }

    
}
int main(void)
{
    
    Mat_Graph G;
    create_graph(&G);
    prim(&G);
    return 0;
}

