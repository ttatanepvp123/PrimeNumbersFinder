#include <iostream>
#include <memory>
#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>
#include <string>


bool isPrime(int a,std::vector<int>& numbers){
    for(size_t i = 0; i < numbers.size(); i++){
        int tmp = numbers[i];
        if(tmp<=sqrt(a)){
            if((a%tmp)==0){
                return false;
            }
        } else {
            return true;
        }
    }
    return true;
}

void getNumbers(std::vector<int> *numbers, int limit){
    numbers->push_back(2);
    numbers->push_back(3);
    int k = 0;
    while(k<limit-6){
        k += 6;
        for(size_t i = 0; i < 1; i++){
            if (isPrime(k-1,*numbers)) {
                numbers->push_back(k-1);
            }
            if (isPrime(k+1,*numbers)) {
                numbers->push_back(k+1);
            } 
        }
    }
}

int main(int argc, char const *argv[]){
    int limit = -1;
    std::vector<int> numbers(0,0);
    while(limit == -1){
        std::cout << "find the prime number from 1 to : ";
        std::cin >> limit;
        if(limit < 20){
            limit = 20;
        };
    }
    int begin = (int)time(NULL);
    getNumbers(&numbers,limit);
    int end = (int)time(NULL);
    std::cout << "execution time : " << end-begin << "s" << std::endl;
    std::cout << ">>> " << numbers.size() << " numbers found" << std::endl;
    std::string tmp("");
    while(tmp != "Yes" && tmp != "No"){
        std::cout << "do you want to save the number to a file ? [Yes/No] : ";
        std::cin >> tmp;
        if(tmp != "Yes" && tmp != "No") {
            std::cout << "Yes or No ! è_é" << std::endl;
        }
    }
    if(tmp == "Yes"){
        std::cout << "file name : ";
        std::cin.ignore();
        std::getline(std::cin, tmp);
        std::ofstream resultsFile(tmp);
        for(size_t i = 0; i < numbers.size(); i++){
            resultsFile << numbers[i] << std::endl;
        }
    }
    return 0;
}
