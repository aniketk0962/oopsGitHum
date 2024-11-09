#include<bits/stdc++.h>
using namespace std;
class Details{
    long long const aadharNum;
    long long const panNum;
    string address;
    long long const contactNum;
    public:
    Details():aadharNum(243567584635),panNum(33333333993),contactNum(6202021932){

    }
    Details(string address):aadharNum(243567584635),panNum(33333333993),contactNum(6202021932){
        this->address=address;
    }
    string setDetails(){
        return address;
    }
    long long get()const{
        return aadharNum;
        return panNum;
        return contactNum; 
    }
};
int main(){
    string address;
    //cin>>address;
    Details d1;
    cout<<"Your address is:"<<d1.setDetails();
    cout<<"Required number is:"<<d1.get();
    return 0;
}