// jai shree ram
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n;
    cin>>n;
    // arrival time and departure time
    vector<int> arrival(n) , departure(n);
    for(int i = 0 ; i < n ; i++) {
      cin>>arrival[i];
      cin>>departure[i];
    }
    sort(arrival.begin(), arrival.end());
    sort(departure.begin() , departure.end());
    int totalCustomersAtATime = 0 , currCustomer = 0;
    for(int i = 0 , j = 0 ; i < n && j < n ; ) {
      if(arrival[i] < departure[j]) {
        currCustomer++;
        totalCustomersAtATime = max(currCustomer , totalCustomersAtATime);
        i++;
      }
      else {
        currCustomer--;
        j++;
      }
    }
    cout<<totalCustomersAtATime<<endl;
    return 0;
}
