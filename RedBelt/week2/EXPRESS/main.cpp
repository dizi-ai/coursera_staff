#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <set>

using namespace std;

class RouteManager {
public:
  void AddRoute(const int start, const int finish) {
    reachable_lists_[start].insert(finish);
    reachable_lists_[finish].insert(start);
  }
  int FindNearestFinish(const int start, const int finish) const {
    int result = abs(start - finish);
    if (reachable_lists_.count(start)<1) {
        return result;
    }
      const auto finish_pos =  reachable_lists_.at(start).lower_bound(finish);
      if (finish_pos != reachable_lists_.at(start).end()) {
          result = min(result, abs(finish - *finish_pos));
      }
      if (finish_pos != reachable_lists_.at(start).begin()) {
          result = min(result, abs(finish - *prev(finish_pos)));
      }
    return result;
  }
private:
  map<int, set<int>> reachable_lists_;
};


int main() {
    RouteManager routes;
    int query_count;
    cin >> query_count;
    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int start, finish;
        cin >> start >> finish;
        if (query_type == "ADD") {
            routes.AddRoute(start, finish);
        } else if (query_type == "GO") {
            cout << routes.FindNearestFinish(start, finish) << "\n";
        }
    }

    return 0;
}