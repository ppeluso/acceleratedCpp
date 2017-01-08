#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
double grade(double midterm, double final, const vector<double>& hw);
double median(vector<double> vec);
istream& read_hw(istream& in, vector<double>& hw);
int main()
{
cout << "Please enter your first name: ";
string  name;
cin >> name; 

cout << "Hello" << name << "!" << endl;

cout << "Please enter your midterm and final grades, "; 

double midterm, final ; 

cin >> midterm >> final;

cout << "enter all homework grades followed by end-of-file: ";

vector<double> homework;

read_hw(cin, homework);

try{
	double final_grade = grade(midterm, final, homework);
	cout << "your final grade is" << final_grade << endl; 

}catch(domain_error) {
	cout << endl << "you must enter your grades, try again";
	return 1;

}

return 0;

}

double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has no homework");

	return 0.4 * final + 0.4* median(hw)+ .2 * midterm;
}

double median(vector<double> vec)
{
	typedef vector<double> :: size_type vec_sz; 

	vec_sz size = vec.size();
	if(size == 0)
		throw domain_error("median of an empty");
	sort(vec.begin(), vec.end());
	vec_sz mid = size /2; 

	return size %2 == 0 ?  vec[mid]: (vec[mid] + vec[mid -1]) /2;
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in){
	hw.clear();
	
	double x; 
	while(in >> x)
		hw.push_back(x);

	in.clear();
	
	}
	return in;

}

