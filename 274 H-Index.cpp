class Solution {
public:
    int hIndex(vector<int>& citations) {
        // max h-index = citations.size() - 1 
        // for this to be the case every integer in citations
        // would need to be greater than or equal to "citations.size() - 1"
        // e.g. for 0 [0,0,0,0]
        // e.g. for 1 [1,0,0,0]
        // e.g. for 2 [1,1,2,1]
        sort(citations.begin(), citations.end());
        int h = 0;
        for (int i = citations.size() - 1; i > -1; i--) {
            if (citations[i] > h) {
                h++;
            }
        }
        return h;
    }
};