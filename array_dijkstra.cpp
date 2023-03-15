#include "stdio.h"
#include "iostream"
#include "set"

#define DEFAULT_NODE_COUNT 6
#define MAX_NODE_WEIGHT 20
#define INF INT32_MAX
static int input_map_arr[6][6] =
{
    {0,     2,      5,      1,      INF,    INF},
    {2,     0,      3,      2,      INF,    INF},
    {5,     3,      0,      3,      1,      5},
    {1,     2,      3,      0,      1,      INF},
    {INF,   INF,    1,      1,      0,      2},
    {INF,   INF,    5,      INF,    2,      0}
};

static int min_weight_map_arr[6] = {INF};

static std::set<int> visited_node_set;


void init_first_step()
{
    for(int i = 0 ; i < DEFAULT_NODE_COUNT ; i++)
    {
        min_weight_map_arr[i] = input_map_arr[0][i];
    }

    visited_node_set.insert(0);

    printf("---------------------------------------------\n");
    printf("|   init min_weight_map[] with first Node   |\n");
    printf("---------------------------------------------\n");
    printf("        %d %d %d %d %d %d \n"
            , min_weight_map_arr[0]
            , min_weight_map_arr[1]
            , min_weight_map_arr[2]
            , min_weight_map_arr[3]
            , min_weight_map_arr[4]
            , min_weight_map_arr[5]);

    printf("\n");
    printf("\n");
    printf("\n");
}

int get_next_node()
{
    int next_node;
    int min_weight = INF;

    for(int i = 0 ; i < DEFAULT_NODE_COUNT; i++)
    {
        if(min_weight_map_arr[i] != INF &&                          // 갈 수 없는 노드가 아니고
            min_weight_map_arr[i] != 0 &&                           // 현재 자기 노드가 아니고
            min_weight_map_arr[i] < min_weight &&                   // 현재 min_weight보다 작고
            visited_node_set.find(i) == visited_node_set.end())     // 방문된 node가 아니면
        {
            min_weight = min_weight_map_arr[i];
            next_node = i;                                          // 다음 탐색 노드 변경
        }
    }

    return next_node;
}

void update_min_weight_map_arr(int current_node)
{
    int current_min_weight;
    unsigned int comp_weight;

    for(int i = 0 ; i < DEFAULT_NODE_COUNT; i++)
    {
        if(visited_node_set.find(i) == visited_node_set.end() && current_node != i)
        {
            current_min_weight = min_weight_map_arr[i];
            
            comp_weight = min_weight_map_arr[current_node] + input_map_arr[current_node][i];

            if(current_min_weight > comp_weight)
            {
                min_weight_map_arr[i] = comp_weight;
            }
        }
    }

    printf("---------------------------------------------\n");
    printf("|       update min_weight_map_arr           |\n");
    printf("|           current Node : %d                |\n", current_node);
    printf("---------------------------------------------\n");
    printf("        %d %d %d %d %d %d \n"
            , min_weight_map_arr[0]
            , min_weight_map_arr[1]
            , min_weight_map_arr[2]
            , min_weight_map_arr[3]
            , min_weight_map_arr[4]
            , min_weight_map_arr[5]);
    printf("\n");
    printf("\n");
    printf("\n");


    visited_node_set.insert(current_node);
}

void find_min_weight_route()
{
    int next_node;
    

    while(visited_node_set.size() != DEFAULT_NODE_COUNT)
    {
        next_node = get_next_node();
        printf("next_node : %d \n" ,next_node);
        update_min_weight_map_arr(next_node);
    }
}


int main(int argc, char* argv[])
{
    init_first_step();

    find_min_weight_route();


    

}