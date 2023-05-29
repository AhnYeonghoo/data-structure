#include <iostream>
#include <array>
#include <type_traits>
using namespace std;

template<typename ... Args>
auto buildArray(Args&& ... args) -> std::array<typename std::common_type<Args...>::type, sizeof...(args)>
{
    using common_type = typename std::common_type<Args...>::type;
    return {std::forward<common_type>((Args&&)args)...};
}

int main()
{
    auto data = buildArray(1, 0u, 'a', 3.2f, false);
    for (auto i : data)
        cout << i << " ";
    
    cout << endl;

    return 0;
}