#include <string>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <unordered_map>
#include <cmath>

using namespace std;

int calculateFee(int time, const vector<int>& fees)
{
    if(time <= fees[0])
    {
        return fees[1];
    }
    
    int addTime = time - fees[0];
    int addFee = ceil((double)addTime / fees[2]) * fees[3];
    
    return fees[1] + addFee;
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    unordered_map<string, int> cars; 
    map<string, int> parkingFees;
    
    for(string s : records)
    {
        stringstream ss(s);
        string time, carNum, status; 
        ss >> time >> carNum >> status; 
        
        int parkingTime = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
        
        if(status == "IN")
        {
            cars[carNum] = parkingTime;
        }
        
        else if(status == "OUT")
        {
            if(cars.find(carNum) != cars.end())
            {
                int totalTime = parkingTime - cars[carNum];
                parkingFees[carNum] += totalTime; 
                cars.erase(carNum);
            }
        }
    }
    
    for(const auto& car : cars)
    {
        int totalTime = 1439 - car.second; 
        parkingFees[car.first] += totalTime;
    }
    
    for(const auto fee : parkingFees)
    {
        answer.push_back(calculateFee(fee.second, fees));
    }
    
    return answer;
}