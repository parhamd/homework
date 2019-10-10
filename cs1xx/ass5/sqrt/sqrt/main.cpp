//Parham Davoodi
//find top and bottom of sqrt function number
//cs111


#include <iostream>
using namespace std;


int main() {
    int num; //input
    int ii; // i*i
    int diff=99; //difference
    int top=0;//dumby high
    int low=0; //dumby low
    int closest=999; //closes sqr
    int closestnum=999; //closest lower
    int tt;// top*top
    int ll;// low*low
    int ttd, lld, ttdp, lldp, closest2;
    //ttd = top*top difference
    //ttdp = ttd * ttd
    //lld = low*low difference
    //lldp = lld * lld
    //closest2 is closest number
    
    
    cout <<"Enter num: ";
    cin>>num;
    
    for (int i=0;i<num;i++) {
        ii=i*i;
        diff=num-ii;
        if (diff > 0 && diff<= closest)
        {
            closest = diff;
            closestnum= i;
            top = i +1;
            low = i;
        }else if (diff == 0){
            top = i;
            low = i-1;
        }
    }
            
    tt = top*top;
    ll = low*low;
    
    ttd = num - tt;
    lld = num - ll;
    ttdp = ttd * ttd;
    lldp = lld * lld;
    
    if ( ttdp<lldp)
    {
        closest2 = top;
    }else {
        closest2 = low;
    }
    
    
    cout << "Top is: "<< top<<endl;
    cout << "Bottom is: "<< low << endl;
    cout << "Between "<< top << " and " << low << ", " << closest2 << " is closer" <<endl;
    
    return 0;
}
