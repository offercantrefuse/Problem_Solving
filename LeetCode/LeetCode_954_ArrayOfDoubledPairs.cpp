class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {     
        if (arr.size() == 0) return true;

        vector<int> minus_arr;
        vector<int> plus_arr;

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] < 0) {
                minus_arr.push_back(arr[i]);
            }
            else {
                plus_arr.push_back(arr[i]);
            }
        }

        sort(minus_arr.begin(), minus_arr.end(), greater<int>());
        sort(plus_arr.begin(), plus_arr.end());


        int pt1 = 0, pt2 = 1;
        int plus_size = plus_arr.size();
        int plus_cnt = 0;
        if (plus_size != 0) {
            bool p_visit[30001];
            memset(p_visit, false, sizeof(p_visit));
            while (pt1 < plus_size && pt2 < plus_size) {
                if (plus_arr[pt2] == plus_arr[pt1] * 2) {
                    p_visit[pt2++] = true;
                    while (p_visit[++pt1]);
                    if (pt1 == pt2) pt2++;
                    plus_cnt += 2;
                }
                else {
                    pt2++;
                }
            }
        }

        int pt3 = 0, pt4 = 1;
        int min_size = minus_arr.size();
        int minus_cnt = 0;
        if (min_size != 0) {
            bool m_visit[30001];
            memset(m_visit, false, sizeof(m_visit));
            while (pt3 < min_size && pt4 < min_size) {
                if (minus_arr[pt4] == minus_arr[pt3] * 2) {
                    m_visit[pt4++] = true;
                    while (m_visit[++pt3]);
                    if (pt3 == pt4) pt4++;
                    minus_cnt += 2;
                }
                else {
                    pt4++;
                }
            }
        }

        if (plus_cnt == plus_size && minus_cnt == min_size)
            return true;
        return false;      
    }
};