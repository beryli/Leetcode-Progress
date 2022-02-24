class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if (s.size() < p.size()) {return ret;}
        
        vector<int> letter_count(26, 0);
        int key;
        for (int i = 0; i < p.size(); i++) {
            key = p[i] - 'a';
            letter_count[key]--;
            key = s[i] - 'a';
            letter_count[key]++;
        }
            
        if (all_of(letter_count.begin(), letter_count.end(), [](int i) { return i==0; }))
            {ret.push_back(0);}
        
        for (int i = 0; i < s.size() - p.size(); i++) {
            key = s[i] - 'a';
            letter_count[key]--;
            key = s[i+p.size()] - 'a';
            letter_count[key]++;
            if (all_of(letter_count.begin(), letter_count.end(), [](int i) { return i==0; }))
                {ret.push_back(i+1);}
        }
        
        return ret;
    }
};