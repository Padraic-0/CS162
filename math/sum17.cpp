#include <iostream>
using namespace std;
int main(){
    int sum = 17;
    int num = 0;
    for (int i = 0; i <= sum ; i++){
        for (int j = 0; j <= sum ; j++){
            for (int k = 0; k <= sum ; k++){
                for (int l = 0; l <= sum ; l++){
                    if (i+j+k+l == 17){
                        num += 1;
                    }
                }
            }
        }
    }
    cout <<num;
    return 0;
}