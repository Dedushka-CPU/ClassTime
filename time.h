#ifndef TIME_H
#define TIME_H
#include <ostream>
#include <istream>
namespace chron {
	class Time {
	private:
		int TotalSeconds=0;
		void Normalize();
	public:
		Time()=default;
		Time(int h, int m, int s);
		Time(int h, int m);
		Time(int s):Time(0,0,s){};
		int GetHours() const;
		int GetMinutes() const;
		int GetSeconds() const;
		void AddSeconds(int s);
		int TotalSecondss() const;
		Time& operator+=(int s);
		Time operator+(int s)const;
		
	};
}
int operator-(const chron::Time& t1,const chron::Time& t2);
std::ostream& operator<<(std::ostream& out,const chron::Time& t );
std::istream& operator>>(std::istream& in,chron::Time& t );

#endif //TIME_H
