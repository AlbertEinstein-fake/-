#include<stdio.h>

typedef int VertexType;
typedef int EdgeType;

#define MAXSIZE 100
#define MAXEDGE 200
#define MAX 0x10000

typedef struct   //构建邻接矩阵
{
    VertexType vertex[MAXSIZE];
    EdgeType arc[MAXSIZE][MAXSIZE];
    int vertex_num;
    int edge_num;    
}Mat_Graph;

void createGraph(Mat_Graph* G)  //创建一个图
{
    G->vertex_num = 10;
    G->edge_num = 17;

    for (int i = 0; i < G->vertex_num; i++)
    {
        G->vertex[i] = i;
    }
    
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
    
    G->arc[0][1] = 1;
    G->arc[0][2] = 5;
  
    G->arc[1][2] = 3;
    G->arc[1][3] = 7;
    G->arc[1][4] = 5;

    G->arc[2][4] = 1;
    G->arc[2][5] = 7;

    G->arc[3][4] = 2;
    G->arc[3][6] = 3;

    G->arc[4][5] = 3;
    G->arc[4][6] = 6;
    G->arc[4][7] = 9;

    G->arc[5][7] = 5;
    G->arc[5][9] = 4;

    G->arc[6][7] = 2;
    G->arc[6][8] = 7;

    G->arc[7][8] = 4;

    for (int i = 0; i < G->vertex_num; i++)
    {
        for (int j= i; j < G->vertex_num; j++)
        {
            G->arc[j][i] = G->arc[i][j];   /* 邻接矩阵是对称的 把ij赋值给ji */
        }        
    }    
}
//返回下一次要观察哪一个顶点
int choose(int distance[], int found[], int vertex_num)
{
    int min = MAX; //min里面保存的是权值 
    int minPos = -1; //离起始点最近的点的权值 并且找到这个顶点是谁 minPos保存的是哪个点
    for (int i = 0; i < vertex_num; i++)
    {
        if (distance[i] < min && found[i] == 0) //找到未被访问的 距离最短的点
        {
            min = distance[i];
            minPos = i;
        } 
    }
    return minPos;    //返回最短路径的点
}

void dijkstra(Mat_Graph G,int begin)
{
    int found[MAXSIZE]; //顶点是否被走过
    int path[MAXSIZE]; //路径
    int distance[MAXSIZE]; //begin到达每一个顶点的最短距离
    for (int i = 0; i < G.vertex_num; i++)
    {
        found[i] = 0;
        path[i] = -1;
        distance[i] = G.arc[begin][i]; //begin i 表示起始点到下一个点的距离 一开始begin就是V0点
    }

    found[begin] = 1;
    distance[begin] = 0;  //自己到自己 肯定是零

    int next;  //下一个点
    for (int i = 1; i < G.vertex_num; i++)
    {
        next = choose(distance, found, G.vertex_num);
        //printf("%d\n", next);
        found[next] = 1;
        for (int j = 0; j < G.vertex_num; j++)
        {
            if (found[j] = 0)
            {
                if (distance[next] + G.arc[next][j] < distance[j])  //
                {
                    distance[j] = distance[next] + G.arc[next][j];  //将最短路径赋给distance
                    path[j] = next;
                }
            }
        }
    }
    
    for (int i = 1; i < G.vertex_num; i++)
    {
        printf("V0 -> v%d : %d\n", i, distance[i]);

		int j = i;
		printf("V%d <- ", i);
		while(path[j] != -1)
		{
			printf("V%d <- ", path[j]);
			j = path[j];
		}
		printf("V0\n");
        
    }   

}

int main(int argc, char const*argv[])
{
    Mat_Graph G;
    createGraph(&G);
    int begin = 0;
    dijkstra(G,begin);
    return 0; 
}
