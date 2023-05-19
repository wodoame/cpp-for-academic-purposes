#include <iostream>
#include <cmath>
using namespace std; 

int main(){
    double opposite, adjacent, hypotenuse; 
    cout << "Enter the opposite side >> "; 
    cin >> opposite;
    cout << "Enter the adjacent side >> ";
    cin >> adjacent;
    hypotenuse = hypot(opposite, adjacent);
    cout << "The hypotenuse is: " << hypotenuse;

    // The most obvious way to compute the hypotenuse is: 
    // hypotenuse = sqrt(pow(opposite, 2) + pow(adjacent, 2));
    // But hypot() function was provided by cmath
  
    return 0;
}
