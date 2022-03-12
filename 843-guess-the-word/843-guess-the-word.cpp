/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    vector<vector<int>> similarity;
    vector<int> vis;
    int len;
    void getSim(vector<string>& wordlist){
        for(int i = 0; i < len; i++){
            similarity[i][i] = 6;
            for(int j = i + 1; j < len; j++){
                int count = 0;
                for(int k = 0; k < 6; k++){
                    if(wordlist[i][k] == wordlist[j][k]) count++;
                }
                similarity[i][j] = count;
                similarity[j][i] = count;
            }
        }
    }
    int getNext(){
        int Max = INT_MAX, Next = -1;
        for(int i = 0; i < len; i++){
            if(!vis[i]) continue;
            vector<int> count(6,0);
            for(int j = 0; j < len; j++){
                if(i == j || !vis[i]) continue;
                count[similarity[i][j]]++;
            }
            int maxVal = *max_element(count.begin(), count.end());
            if(maxVal < Max){
                Max = maxVal;
                Next = i;
            }
        }
        return Next;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        len = wordlist.size();
        similarity.resize(len, vector<int>(len,0));
        vis.resize(len, 1);
        getSim(wordlist);
        
        while(1){
            int Next = getNext();
            int count = master.guess(wordlist[Next]);
            if(count == 6) return;
            else{
                for(int i = 0; i < len; i++){
                    if(similarity[i][Next] != count) vis[i] = 0;
                }
            }
        }
    }
};