import java.util.ArrayList;
import java.util.HashMap;

class Pair {
    String uid;
    int enter;

    Pair() {
    }

    Pair(String uid, int enter) {   // 0: enter, 1: leave
        this.uid = uid;
        this.enter = enter;
    }
}

class Solution {
    public String[] solution(String[] record) {
        String[] answer = {};
        ArrayList<Pair> list = new ArrayList<>();
        HashMap<String, String> info = new HashMap<>();
        for (int i = 0; i < record.length; i++) {
            String[] str = record[i].split(" ");   // \\s로 써야되나
            if (str[0].equals("Enter")) {
                list.add(new Pair(str[1], 0));
                info.put(str[1], str[2]);
            } else if (str[0].equals("Leave")) {
                list.add(new Pair(str[1], 1));
            } else if (str[0].equals("Change")) {
                info.put(str[1], str[2]);
            }
        }
        answer = new String[list.size()];

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).enter == 0) {  // enter
                answer[i] = info.get(list.get(i).uid) + "님이 들어왔습니다.";
            } else if (list.get(i).enter == 1) {// leave
                answer[i] = info.get(list.get(i).uid) + "님이 나갔습니다.";
            }
        }
        return answer;
    }
}