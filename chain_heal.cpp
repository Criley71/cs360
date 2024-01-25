#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
/*
x y pp  maxpp name
0 0 100 100   Urgosa_the_Healing_Shaman
2 0 100 500   Adam_the_Warrior
3 0 400 450   Catherine_the_Great
4 0 45  400   Chad_the_Priest
4 1 300 600   James_the_Lightning_Lord
*/
class Node {
  public:
  string name;
  int x, y;
  int curr_pp, max_pp;
  Node *prev;
  int adj_size;
  vector<Node> adj;
  bool visited = false;
  Node(int a, int b, int currentpp, int maxpp, string n){
    x = a;
    y = b;
    curr_pp = currentpp;
    max_pp = maxpp;
    name = n;
  }
};

void dfs(Node node, int hopNum, int max_jump){

}
//How to run: chain_heal initial_range jump_range num_jumps initial_power power_reduction < input_file
// ./ch 2 1 4 500 0.25 chain_heal.txt
// ./ch 1 2 4 500 0.25 chain_heal.txt
int main(int argc, char **argv){

  vector<Node> nodes;
  ifstream fin;
  int initial_range = atoi(argv[1]);
  int jump_range = atoi(argv[2]);
  int num_jumps = atoi(argv[3]);
  int initial_power = atoi(argv[4]);
  int power_reduction = atoi(argv[5]);
  //read file and distribute to variables
  fin.open(argv[6]);
  string line;
  int x_in, y_in, curr_pp_in, max_pp_in;
  string name_in;
  //make array of nodes
  while(getline(fin, line)){
    stringstream sstream(line);
    sstream >> x_in >> y_in >> curr_pp_in >> max_pp_in >> name_in;
    nodes.push_back(Node(x_in, y_in, curr_pp_in, max_pp_in, name_in));
    sstream.clear();

  }
  //check that it assigned variables correctly
  for(int i = 0; i < nodes.size(); i++){
    cout << nodes[i].x << ' ';
    cout << nodes[i].y << ' ';
    cout << nodes[i].curr_pp << ' ';
    cout << nodes[i].max_pp << ' ';
    cout << nodes[i].name << '\n';
  }




  //get adj size
  for(int i = 0; i < nodes.size(); i++){

    int adj_size_calc = 0;
    for(int j = 0; j < nodes.size(); j++){
  
      int x_dist = nodes[i].x - nodes[j].x;
      if (x_dist < 0) x_dist *= -1;
    

      int y_dist = nodes[i].y - nodes[j].y;
      if (y_dist < 0) y_dist *= -1;
   

    

      if(x_dist <= initial_range || x_dist <= jump_range || y_dist <= initial_range || y_dist <= jump_range){
        adj_size_calc++;
     

      }
    }
    nodes[i].adj_size = adj_size_calc;
    //nodes[i].adj.resize(nodes[i].adj_size);
 
  }

  cout << initial_range << '\n';
  cout << jump_range << '\n';
  int calc_dist;
  for(int i = 0; i < nodes.size(); i++){
    for(int j = 0; j < nodes.size(); j++){
      int x_dist = nodes[i].x - nodes[j].x;
      if (x_dist < 0) x_dist *= -1;

      int y_dist = nodes[i].y - nodes[j].y;
      if (y_dist < 0) y_dist *= -1;

      calc_dist = y_dist + x_dist;
      /*
      if(x_dist == 0) {
        calc_dist = y_dist;
      }
      else if(y_dist == 0){
        calc_dist = x_dist;
        
      }
      else{
        if(x_dist > y_dist) calc_dist = x_dist + y_dist;
        else if(y_dist > x_dist) calc_dist = y_dist + x_dist;
        else calc_dist = y_dist / x_dist;
      }
*/
      if(calc_dist <= initial_range || calc_dist <= jump_range){
        //cout << nodes[i].name << " adds " << nodes[j].name << " to adj list with total distance of  " << calc_dist << "\n" ;
        nodes[i].adj.push_back(nodes[j]);
      }
      cout << nodes[i].name << " distance to " << nodes[j].name << " with x being " << x_dist << " with y being " << y_dist << " total distance = " << calc_dist << "\n" ;
    }
    cout << "adj for " << nodes[i].name << ": ";
  
    for(int k = 0; k < nodes[i].adj.size(); k++){
     cout << nodes[i].adj[k].name << " ";
    } 
    cout << '\n';
    cout << '\n';
  }

  /*
x y pp  maxpp name
0 0 100 100   Urgosa_the_Healing_Shaman
2 0 100 500   Adam_the_Warrior
3 0 400 450   Catherine_the_Great
4 0 45  400   Chad_the_Priest
4 1 300 600   James_the_Lightning_Lord
*/
  Node *urgo = new Node(0, 0, 100, 100, "urgosa");
  Node *adam = new Node(0, 0, 100, 100, "adam");
  Node *cath = new Node(0, 0, 100, 100, "catherine");
  Node *chad = new Node(0, 0, 100, 100, "chad");
  Node *james = new Node(0, 0, 100, 100, "james");




  int hop = 1;
  for(int i = 0; i < nodes.size(); i++){
      int back_hop = hop;
    for(int j = 0; j < nodes[i].adj.size(); j++){
      if(nodes[i].adj[j].visited == false){
        hop = back_hop;
        nodes[i].visited = true;
        cout << nodes[i].adj[j].name << " hop " << hop << "\n";
        hop+=1;
        if(hop > num_jumps){
          break;
        }
      }
      hop = back_hop + 1;
    }
    if(hop > num_jumps){
          break;
        }
  }

  exit(0);
}