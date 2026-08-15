class Solution {
public:
void  solve ( int index , vector<string> mapping , string output,string digits, vector <string > &ans){
    if (index >=digits.size() ){
        ans.push_back( output);
        return;
    }

    int number = digits[index]-'0';
    string value = mapping [number];

for (int i = 0; i < value.size(); i++){
        output.push_back(value [i]);
        solve ( index +1, mapping, output, digits , ans  );
        output.pop_back();
    }

}
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;
       string output;
       int index = 0;
       vector<string> mapping ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
       solve ( index ,  mapping , output,digits, ans);
        return ans;
    }
};