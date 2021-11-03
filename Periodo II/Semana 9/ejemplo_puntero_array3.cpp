#include <iostream>

using namespace std;

int main()
{
	int c[5] = {1, 2, 3, 4, 5};
	int *p3;
	int sam;
	
	p3 = &c[1];
	
	sam = *(p3 + 3);
	
	cout << "*p3 = " << *p3 << endl;
	cout << "sam = " << sam << endl;
		
	return 0;
}
