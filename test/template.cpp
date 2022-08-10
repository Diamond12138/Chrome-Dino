#include <iostream>
#include <tuple>

void out()
{
	
}

template<typename T,typename ...Ts>
void out(T a,Ts... b)
{
	std::cout << a << std::endl;
	out(b...);
}

int main()
{
	out(1," ",2);
	return 0;
}
