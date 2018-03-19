#include <map>
#include <string>
using namespace std;

int main(void) {
  map<string, int> my_map;

  // insert
  my_map["age"] = 27;
  my_map.insert(make_pair("year", 1992));
  my_map["height"] = 172;
  printf("[insert] %d %d\n", my_map["age"], my_map["year"]);  // 28 1992

  // count
  int count = my_map.count("age");

  printf("[count] %d\n", count);  // 1
  count = my_map.count("name");
  printf("[count] %d\n", count);  // 0

  // find and erase
  std::map<string, int>::iterator it;

  it = my_map.find("age");
  printf("[erase] %s: %d\n", it->first.c_str(), it->second);
  my_map.erase(it);

  // iterate
  for (it = my_map.begin(); it != my_map.end(); ++it)
    printf("[iter] %s: %d\n", it->first.c_str(), it->second);
  return (0);
}
