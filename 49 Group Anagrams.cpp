class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > groups;

        unordered_map<string, int> mapToGroup; //maps strings to index in group
        int counter = 0;
        int n = strs.at(0).size();

        for (int i = 0; i < strs.size(); i++) {
            string strCopy = strs.at(i);
            sort(strCopy.begin(), strCopy.end());
            counter = mapToGroup.size(); //if something new is in the map, this will increase
            mapToGroup.insert({strCopy, counter});
            if (mapToGroup.size() > groups.size()) { //need to create a new group
                groups.push_back({strs.at(i)}); // need to push_back a vector of string, thats why the curly braces
            }
            else { //insert into existing group
                groups.at(mapToGroup[strCopy]).push_back(strs.at(i)); //just need to push_back a string here
            }        
        }

        return groups;
    }
};