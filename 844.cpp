class Solution {
public:
    bool method_1 (string s, string t) {
        string s_new = "", t_new = "";
        for (int i = 0; i < s.size(); i++){
            if (s[i] != '#') {s_new.push_back(s[i]);}
            else if (s_new.size() != 0) {s_new.pop_back();}
        }
        for (int i = 0; i < t.size(); i++){
            if (t[i] != '#') {t_new.push_back(t[i]);}
            else if (t_new.size() != 0) {t_new.pop_back();}
        }
        return s_new.compare(t_new) == 0 ? true : false;
    }
    
    bool method_2 (string s, string t) {
        int i = s.size(), j = t.size();
        int i_skip = 0, j_skip = 0;
        while (i >= 0 && j >= 0) {
            i--; j--;
            while (i >= 0){
                if (s[i] == '#') {i_skip++; i--;}
                else if (i_skip) {i_skip--; i--;}
                else {break;}
            }
            while (j >= 0){
                if (t[j] == '#') {j_skip++; j--;}
                else if (j_skip) {j_skip--; j--;}
                else {break;}
            }
            if (i >= 0 && j >= 0 && s[i] != t[j]) {return false;}
        }
        if (i >= 0 || j >= 0) {return false;}
        
        return true;
    }
    
    bool backspaceCompare(string s, string t) {
        // return method_1(s, t);
        return method_2(s, t);
    }
};