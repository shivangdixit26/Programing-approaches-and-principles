class Disjointset{
    unordered_map<int,int>parent;
public:
int find(int i ){
    if(parent.find(i)==parent.end()){
        parent[i]=i;

    }
    if(parent[i]==i){
        return i;
    }
    return parent[i]=find(parent[i]);
}
void unite(int i ,int j){
    int rootI=find(i);
    int rootJ=find(j);
    if(rootI!=rootJ){
        parent[rootI]=rootJ;
    }
}
int getComponentCount(){
    int count=0;
    for(auto& [node,root]:parent){
        if(node==root)count++;
    }
    return count;
}

};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        Disjointset dsu;
        for(auto& stone:stones){
            dsu.unite(stone[0],stone[1]+10001);


        }
        return stones.size()-dsu.getComponentCount();
        
        
        
    }
};