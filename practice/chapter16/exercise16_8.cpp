# include <iostream> 
# include <list>
# include <string>
# include <iterator>
# include <algorithm>
# include <set>

template <typename Iter>
void printRange(Iter begin, Iter end) {
    for (auto it = begin; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<std::string> Mat_list = {"Mat", "Pat", "Cat", "Bat", "Rat", "Fat", "Nat"};
    std::list<std::string> Pat_list = {"Pat", "Cat", "Bat", "Fat", "Nat", "Sat", "Hat"};
    std::set<std::string> Gust_set;

    std::set_union(Mat_list.begin(), Mat_list.end(),
                          Pat_list.begin(), Pat_list.end(),
                          std::inserter(Gust_set, Gust_set.begin()));
    printRange(Gust_set.begin(), Gust_set.end());

    // 证明 set_union 的结果和直接插入 set 的结果相同
    std::copy(Mat_list.begin(), Mat_list.end(),
              std::inserter(Gust_set, Gust_set.begin()));
    std::copy(Pat_list.begin(), Pat_list.end(),
              std::inserter(Gust_set, Gust_set.begin()));
    printRange(Gust_set.begin(), Gust_set.end());

    return 0;

}