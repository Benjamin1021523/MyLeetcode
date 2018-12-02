class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> deck) {
        sort(deck.begin(), deck.end());
        vector<int> use(deck.size(), deck[0]-1);
        int u = 0, i = 0;
        while(1){
            while(use[u] >= deck[0]){
                u = (u + 1) % use.size();
            }
            use[u] = deck[i++];
            if(i == deck.size())
                break;
            while(use[u] >= deck[0]){
                u = (u + 1) % use.size();
            }
            u = (u + 1) % use.size();
        }
        return use;
    }
};