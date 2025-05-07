#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    return eq == "=" ? (ineq == "<" ? n <= m : n >= m) : (ineq == ">" ? n > m : n < m);
}