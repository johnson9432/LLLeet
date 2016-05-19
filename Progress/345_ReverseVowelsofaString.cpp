class Solution {
public:
    string reverseVowels(string s) {
        string vowels="aeiouAEIOU";
        for(int i=0,j=s.length()-1;i<j;i++){
            if(vowels.find(s[i])!=string::npos) {
            while(vowels.find(s[j])==string::npos)
                j--;
            if(j<i) break;
            swap(s[i],s[j]);
            j--;
            }
        }
        return s;
    }
};
