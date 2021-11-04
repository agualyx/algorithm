#include <iostream>
#include <math.h>
using namespace std;
int erosionTime(float x,float y){
    float s=3.14*(x*x+y*y)/2;
    int year=1;
    while((50*year)<s){
        year++;
    }
    return year;
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        float tempX,tempY;
        cin>>tempX>>tempY;
        int year=erosionTime(tempX,tempY);
        cout<<"Property "<<i+1<<": This property will begin eroding in year "<<year<<"."<<endl;
    }
    cout<<"END OF OUTPUT.";
    return 0;
}
