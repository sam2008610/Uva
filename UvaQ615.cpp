#include<iostream>
#include<deque>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 10000

using namespace std;
int nodeSize,v[MAX],in[MAX];
deque<int> node[MAX];
vector<int> name; //各點名字
vector<int>::iterator it;
int newindex(int new){
    it=find(name.begin(),name.end(),new);
    if(it<name.end()) {return it-name.begin();}
    else if (it == name.end()){  //找不到 
        name.push_back(new);         //字串p加入name     
        return name.size()-1;   //回傳該點的編號 
  }
}
int main(){

}