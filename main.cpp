#include <iostream>
#include "time.h"

using std::cout;
using std::cin;



int main(){
	chron::Time t(1,5,9);
	chron::Time t1;
	cin>>t1;
	cout<<t<<"\n";
	cout<<t1.GetSeconds()<<"\n";
	cout<<t1-t<<"\n";
	return 0;
}
