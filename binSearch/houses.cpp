#include<iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
//given houses coor and heaterc coord find least radius standart so that all houses will be warmed
//all heaters will have same raduis so minilamize it.
using namespace std;
bool pos(vector<int>& houses, vector<int>& heaters,long long int r){
        unordered_map<int,int> diff; //okay....
        int to_be_covered=houses[0];
        int prevind = 0;
        int last = 0;
        for(auto x:heaters){ //iterate heaters
            if( x-r > to_be_covered)  //if already bad one
                return false;
            while(prevind < houses.size() and houses[prevind]<=x+r){ //chech if okay
                prevind++;
            }

            if(prevind>=houses.size()) //if so good
                return true;

            to_be_covered=houses[prevind]; //maybe next

            last=x+r; //find till the end!
        }
        return 0;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        long long int l=0,r=1e10;
        sort(heaters.begin(),heaters.end());
        sort(houses.begin(),houses.end());
        while(l<r){
            long long int mid=l+(r-l)/2;
            if(pos(houses,heaters,mid)) r=mid;
            else l=mid+1;
        }
        return l;
    }