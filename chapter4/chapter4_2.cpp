#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct Student_info {
	string name; 
	double midterm, final; 
	vecotr<double> homework;
};
int main()
{


return 0;
}

istream& read(istream& is, student_info& s){

	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);
	return is;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if(in){
		hw.clear();
	double x; 

	while(in >> x)
		hw.push_back(x);
	in.clear();
	}
	return in; 
}

double grade(Student_info& s)
{
	return s.final * .4 + s.midterm * .2 + median(s.homework) *.4;
}

bool compare(const Student_info& x, const Student_info& y){
	return x.name < y.name ;
}

