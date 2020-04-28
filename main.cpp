#include <iostream>
#include <vector>
#include <typeinfo>
#include <type_traits>

#include <variant>

int main() {
    const std::string givenKey = "Thread";
    const std::string givenValue = "1";
    std::cout << std::endl;

    std::vector<std::vector<std::variant<std::string, double, int, bool>>> vecVecVariant = {
        {std::string("Thread"), 2, 1, 128},
        {std::string("OpenTimeoutSecs"), 0.0, 0.0, 10},
        {std::string("Profile"), true}
    };
    // display each value
    for (auto &vv : vecVecVariant){
        for (auto &v : vv) {
            std::visit([](auto &&arg) { std::cout << arg << " "; }, v);// 2
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // display each type
    for (auto &vv : vecVecVariant) {
        for (auto &v : vv) {
            std::visit([](auto &&arg) { std::cout << typeid(arg).name() << " "; }, v);// 3
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    // check the key

    for (auto &vv : vecVecVariant) {

        std::string keyWord = std::get<std::string>(vv[0]);

        if (givenKey == keyWord){
            // dispatch by type
            std::string stype = std::visit([](auto &&arg) { return typeid(arg).name(); }, vv[1]);

            if (stype == typeid(std::string("")).name()){
                std::cout << "Handle string" << " ";
            }else if(stype == typeid(int).name()){
                std::cout << "Handle int" << " ";
            }else if (stype == typeid(double).name()){
                std::cout << "Handle double" << " ";
            }if (stype == typeid(bool).name()){
                std::cout << "Handle bool" << " ";
            }
            break;
        }
    }
}



