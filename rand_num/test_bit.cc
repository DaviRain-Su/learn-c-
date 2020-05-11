#include <iostream>

int main()
{
	union
	{
		short i;
		char a[2];
	}u;
	u.a[0] = 0x11;
	u.a[1] = 0x22;
	printf ("0x%x\n", u.i);  //0x2211 为小端  0x1122 为大端
	return 0;
}

