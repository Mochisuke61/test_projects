#include<iostream>

void test(void) {

	static int count = 0;
	printf("Hello World\n");
	if (++count > 2020)	return;
	test();
}

int main(void) {


	test();
	return 0;
}

