#include "time.h"

using namespace chron;

Time::Time(int h, int m, int s)
{
	TotalSeconds=h*3600+m*60+s;
	Normalize();
}
int Time::TotalSecondss() const{
	return TotalSeconds;
}
void Time::Normalize(){
	TotalSeconds%=86400;
	if(TotalSeconds<0){
		TotalSeconds+=86400;
	}
	
}
Time& Time::operator+=(int s){
	TotalSeconds+=s;
	Normalize();
	return *this;
}
int Time::GetHours() const
{
	return TotalSeconds/3600;
}
int Time::GetMinutes() const
{
	return (TotalSeconds%3600)/60;
}
int Time::GetSeconds() const
{
	return (TotalSeconds%3600)%60;
}

Time Time::operator +(int s)const{
	return Time(TotalSeconds+s);
}

int operator -(const  chron::Time& t2,const  chron::Time& t1){
	return t1.TotalSecondss()-t2.TotalSecondss();
}
std::istream& operator>>(std::istream& in,chron::Time& t ){
		int h,m,s;
		char temp;
		in>>h>>temp;
		in>>m>>temp;
		in>>s>>temp;
		t=Time(h,m,s);
		return in;
}

std::ostream& operator<<(std::ostream& out,const chron::Time& t ){
		out<<t.GetHours()<<":"<<t.GetMinutes()<<":"<<t.GetSeconds();
		return out;
}
