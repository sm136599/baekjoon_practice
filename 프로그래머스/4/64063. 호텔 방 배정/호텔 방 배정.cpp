#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

long long find_room(unordered_map<long long, long long>& m, long long room) {
    if (m.find(room) == m.end()) {
        return room;
    }
    
    return m[room] = find_room(m, m[room]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    int n = room_number.size();
    vector<long long> answer;
    unordered_map<long long, long long> m;
    for (int i = 0; i < n; i++) {
        long long wished_room = room_number[i];
        long long decided_room = find_room(m, wished_room);
        
        answer.push_back(decided_room);
        m[decided_room] = decided_room + 1;
    }
    return answer;
}