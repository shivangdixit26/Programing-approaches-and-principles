class Solution {
vector<string>coulmnstates;
vector<vector<int>>t;
const int MOD =1e9+7;
void generatecoulmnstates(string current,int remaining, char prev){
    if(remaining==0){
        coulmnstates.push_back(current);
        return;
    }
    for(char ch:{'R','G','B'}){
        if(ch==prev)continue;
        generatecoulmnstates(current+ch,remaining-1,ch);
        
    }

}
int solve(int remaining ,int prev, int totalc){
    if(remaining==0)return 1;
    if(t[remaining][prev]!=-1)return t[remaining][prev];
    int total=0;
    string prev_coulmn=coulmnstates[prev];
    for(int next=0;next<coulmnstates.size();next++){
        string next_coulmn=coulmnstates[next];
        bool valid=true;
        for(int r=0;r<totalc;r++){
            if(prev_coulmn[r]==next_coulmn[r]){
                valid=false;
                break;
            }
        }
        if(valid){
            total=(total+solve(remaining-1,next,totalc))%MOD;
        }
    }
    return t[remaining][prev]=total;
}
public:
    int colorTheGrid(int m, int n) {
        coulmnstates.clear();
        generatecoulmnstates("", m, '#');

        int p = coulmnstates.size();
        t.assign(n + 1, vector<int>(p, -1));
        int result = 0;
        for (int i = 0; i < coulmnstates.size(); i++) {
            result = (result+solve(n - 1, i, m)) % MOD;
        }
        return result;
    }
};