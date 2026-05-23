#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double ans[2];
        double kelvin,fahrenheit;
fahrenheit=celsius*1.80+32.00;
kelvin = celsius+273.15;
ans [1]= fahrenheit;
ans [0]= kelvin;
return {ans[0],ans[1]};
    }
};