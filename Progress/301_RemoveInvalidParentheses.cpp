class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftrm(0),rightrm(0);
        unordered_set<string> res;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') leftrm++;
            else if(s[i]==')')
            if(leftrm) leftrm--;
            else rightrm++;
        }
        int startIndex=0, NoOfpair=0;
        string startString="";
        DFS(&res,s,leftrm,rightrm,startIndex,NoOfpair,startString);
        //cout<<res.size();
        return vector<string>(res.begin(),res.end());
    }
    
    void DFS(unordered_set<string> *res, string s, int lr, int rr, int startIndex,int NoOfpair,string SS){
        if(startIndex==s.length()&&NoOfpair==0&&lr==0&&rr==0){
            //cout<<SS<<endl;
            res->insert(SS);
            return;
        }
        if(lr<0||rr<0||NoOfpair<0||startIndex>s.length()) return;
        if(s[startIndex]=='('){
            DFS(res,s,lr,rr,startIndex+1,NoOfpair+1,SS+'(');
            DFS(res,s,lr-1,rr,startIndex+1,NoOfpair,SS);
        }
        else if(s[startIndex]==')'){
            DFS(res,s,lr,rr,startIndex+1,NoOfpair-1,SS+')');
            DFS(res,s,lr,rr-1,startIndex+1,NoOfpair,SS);
        }
        else DFS(res,s,lr,rr,startIndex+1,NoOfpair,SS+s[startIndex]);
        return;
    }
    
    
    
    
};
