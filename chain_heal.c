#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
  char *name;          // 8
  int x, y;            // 8
  int curr_PP, max_PP; // 8
  struct node *prev;   // 8
  int adj_size;        // 4
  struct node **adj;   // 8
} Node;

typedef struct global_info
{
  int i_range;
  int jump_r;
  int n_jump;
  int i_power;
  double power_red;

} Global;

int main(int argc, char *argv[])
{
  int initial_range;
  int jump_range;
  int num_jumps;
  int initial_power;
  double power_reduction;
  char in_name[1024];
  int x_in, y_in, curr_pp_in, max_pp_in;
  int num_nodes = 0;
  // notes
  //  char *string = (char *)malloc(100);
  //  allocate array of 4 ints
  // int *arr = (int *)malloc(4 * sizeof(int));
  sscanf(argv[1], "%d", &initial_range);
  sscanf(argv[2], "%d", &jump_range);
  sscanf(argv[3], "%d", &num_jumps);
  sscanf(argv[4], "%d", &initial_power);
  sscanf(argv[5], "%lf", &power_reduction);
  printf("initial_range: %d \njump_range: %d \nnum_jumps: %d \ninitial_power %d \npower_reduction %lf \n ", initial_range, jump_range, num_jumps, initial_power, power_reduction);
  // Node *all_nodes = malloc(sizeof(Node));
  Node *all_nodes = NULL;
  Node *prev_node = NULL;
  int index = 0;
  while (scanf("%i %i %i %i %s", &x_in, &y_in, &curr_pp_in, &max_pp_in, in_name) == 5)
  {

    ++num_nodes;

    printf("X: %d, Y: %d, Curr_pp: %d, max_pp: %d, name: %s \n", x_in, y_in, curr_pp_in, max_pp_in, in_name);
    all_nodes = realloc(all_nodes, num_nodes * sizeof(Node));
    // all_nodes[index].name = malloc(strlen(in_name) + 1);
    // strcpy(all_nodes[index].name, in_name);
    // char *name_p = in_name;
    // printf("%s\n", &name_p);
    all_nodes[index].name = strdup(in_name);
    all_nodes[index].x = x_in;
    all_nodes[index].y = y_in;
    all_nodes[index].curr_PP = curr_pp_in;
    all_nodes[index].max_PP = max_pp_in;

    // printf( "%s\n", all_nodes[index].name);

    all_nodes[index].prev = prev_node;

    if (index != 0 && all_nodes[index].prev != NULL)
    {
      printf("Previous node is %d\n", all_nodes[index].prev->max_PP);
      printf("%s\n", &all_nodes[index].prev->name);
      printf("%d\n", all_nodes[index].prev->x);
      printf("%d\n", all_nodes[index].prev->y);
      printf("%d\n", all_nodes[index].prev->curr_PP);
      printf("%d\n", all_nodes[index].prev->max_PP);
      printf("\n\n\n");

      // printf("%d\n", all_nodes[index].prev->index);
    }

    prev_node = &all_nodes[index];
    // f(index != 0){
    // printf("previous node of %s is %s\n ", all_nodes[index].name, all_nodes[index].prev->name);
    // }

    index++;
  }

  for (int i = 1; i < num_nodes; i++)
  {
    if (i != 0)
    {
      printf("%c\n", &all_nodes[i].prev->name);
    }
    printf("%d\n", all_nodes[i].prev->x);
    printf("%d\n", all_nodes[i].prev->y);
    printf("%d\n", all_nodes[i].prev->curr_PP);
    printf("%d\n", all_nodes[i].prev->max_PP);
  }
 //stuck 
  Node *pointer_array[num_nodes];
  Node *p = *all_nodes[num_nodes-1];
  while(*p != NULL){

  }
}

// ignore the names for now, just identify them via index