	// Function.cpp : Defines the entry point for the application.
//

#include "Function.h"


int main()
{
	topLevelConst("michael");//pass plain string to const object
	//first experiment 
	//nexttest("mich");error
	//nextTest(12);
	auto a = 12;
	nextTest(&a);
	std::cout << "is sentence \t \"" << "michael sipayung. live in nyu. " << "\"" << isSetence("michael sipayung. live in nyu.") <<"\"" << std::endl;
	const int testCon(12);
	print(&testCon);
	const char* name_d = "michael sipayung";
	print(name_d);
	int array[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	print(std::begin(array), std::end(array));
	//alternative 
	print(&array[0], &array[12]);
	std::cout << std::endl;
	const int data_A[] = { 1,2,4,3,1,2,4,6,7 };
	int element = sizeof(data_A) / sizeof(*data_A);
	std::cout << "before call the reference " << std::endl;
	print_All(data_A,element);
	std::cout << "After call the array reference parameters \t:";
	int nonC_data_A[] = { 1,2,4,3,1,2,4,6,7 };
	print(nonC_data_A);
	print_All(nonC_data_A, element);
	std::string fullName("michael sipayung"),shortName("Michael");
	if (fullName!=shortName)
	{
		varyingParam({ "name is",shortName,"and full name is " , fullName });
	}
	else {
		std::cout << "fullname and short name are equal" << std::endl;
	}

	//applying return for implicit in void function 
	double data_1 = 12.0, data_2 = 13.0;
	returnVal(data_1, data_2);
	std::cout << "data_1\t: " << data_1 << "\ndata_2\t: " << data_2 << std::endl;
	int dataSis[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	minus_1(dataSis);
	show_data(std::begin(dataSis), std::end(dataSis));
	multiplyTwo(dataSis);
	show_data(std::begin(dataSis), std::end(dataSis));
	const std::string bookNo("0xd-discrete"), bookAd("0x9-calculus");
	std::cout << "is " << bookNo << "less than " << bookAd << "\t: " << shorter(bookNo, bookAd) << std::endl;
	//reference returns are rvalue
	std::string unitSol("0x-90");
	std::cout << "current unit \t" << unitSol << std::endl;
	get_val(unitSol, 0) = 'A';
	std::cout << "call function , current unit \t" << unitSol << std::endl;
	//show message, case : return message from a vector 
	auto pro = process();
	for (auto i : pro)
	{
		std::cout << i << "| ";
	}
	std::cout << std::endl;
	auto recursive = recur(5);
	std::cout << "5! \t: " << recursive << std::endl;
	
	return 0;
}

//passing plain string to const object 
void topLevelConst(const std::string&a) {
	std::cout << "test noncost object pass to const object \t " << a << std::endl;
}
void nextTest(int *a) {
	std::cout << " non const object \t " << *a << std::endl;
}
bool isSetence(const std::string& a) {
	bool status = false;
	for (size_t i = 0; i != a.size(); ++i)
	{
		if (a[i] == '.') {
			status = true;
			break;
		}
	}
	return status;

}
void print(const int*a) {
	std::cout << "test const a\t: " << *a << std::endl;
}
void print(const char*name) {
	if (name) //check whether a given variable is null pointer
	{
		while (*name)
		{
			std::cout << *name++ << "|";
		}
	}
}
void print(const int*begin, const int*end) {
	std::cout << std::endl;
	while (begin!=end)
	{
		std::cout << *begin++ << "|";
	}
}
void print_All(const int a[],int total_d) {
	std::cout << "list of data \t: ";
	for (size_t i = 0; i !=total_d; ++i)
	{
		std::cout << a[i] << "|";
	}
	std::cout<<std::endl;
}
void print(int(&arr)[10]) {
	for (auto i : arr) {
		i = i-1;
	}
}
void varyingParam(std::initializer_list<std::string>li) {
	auto begin = li.begin();
	auto end = li.end();
	while (begin!=end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}
}
void elipsParam(...) {
	//interface to c code 
	//using varargs header
}
void returnVal(double&a, double&b) {
	if (a==b)
	{
		return;
	}
	double temp;
	temp = a;
	a = b;
	b = temp;
}
void minus_1(int(&data)[12]) {
	for (auto &i : data)
	{
		i -= 1;
	}
}
void show_data(const int *begin,const int*end) {
	while (begin!=end)
	{
		std::cout << *begin++<<"|";
	}
	std::cout << std::endl;
}
void multiplyTwo(int(&data)[12]) {
	for (auto& i : data)
	{
		i *= 2;
	}
}
//return reference 
//the string are not copied when the function is called
const std::string& shorter(const std::string&a, const std::string&b) {
	return a.size() < b.size() ? a : b;
}
char& get_val(std::string&str, std::string::size_type iz) {
	return str[iz];
}
std::vector<std::string> process() {
	std::string expec("0x-90"),ac("0x-908");
	if (expec.empty()||ac.empty())
	{
		return {};
	}
	else if (expec!=ac)
	{
		return{ "actual not equals to" , "expected" , ac,expec };
	}
	else {
		return{ "missing variable value " };
	}
}
long long recur(int n) {
	if (n>1)
	{
		return recur(n - 1) * n;
	}
	return 1;
}
auto func(int  i)->int(*)[5]{
	int odd[] = {1,3,5,7,9};
	int even[] = { 2,4,6,8,10 };
	return (i % 2) ? &odd : &even;
}