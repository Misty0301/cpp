#include <iostream>
#include <vector>
#include <algorithm>

void print(int x){ 
    std::cout << x << " ";
}

int main(){
    std::vector<int> v = {1,2,3,4,5,6};
    // normal iterator
    for(std::vector<int>::iterator it = v.begin(); it!= v.end(); ++it){ //for(auto it = v.begin(); it!= v.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // reverse iterator
    for(std::vector<int>::reverse_iterator re_it = v.rbegin(); re_it!= v.rend(); re_it++){
        std::cout << std::flush << *re_it << " ";//std::flush is used to refresh the output buffer
    };

    std::cout << std::endl;
    // std::advance
    std::vector<int>::iterator it = v.begin();
    std::advance(it, 3); // move the iterator 3 steps forward
    std::cout << *it << std::endl;

    // std::distance
    std::cout << "distance: " << std::distance(v.begin(), it) << std::endl;

    // std::for_each
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;

    // std::sort
    std::sort(v.rbegin(), v.rend());
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;

    // std::stable_sort
    std::stable_sort(v.rbegin(), v.rend());
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;

    // std::unique  
    std::vector<int> v2 = {1,2,3,4,5,6,6,7,8,9,10,10,10,11,12,13};
    auto last = std::unique(v2.begin(), v2.end());
    v2.erase(last, v2.end());
    std::for_each(v2.begin(), v2.end(), print);
    std::cout << std::endl;

    // // std::find
    // std::vector<int> v3 = {1,2,3,4,5,6,7,8,9,10};
    // std::vector<int>::iterator it2 = std::find(v3.begin(), v3.end(), 5);
    // if(it2 != v3.end()){
    //     std::cout << "found: " << *it2 << std::endl;
    // }else{
    //     std::cout << "not found" << std::endl;
    // }


}