#include <iostream>
#include <cfenv>
#include <conio.h>

#pragma STDC FENV_ACCESS ON

/*	Source by Programmiz
*	Modified by Rizky Khapidsyah
*/

using namespace std;

void print_exceptions() {
	cout << "Raised exceptions : ";

	if (fetestexcept(FE_ALL_EXCEPT)) {
		if (fetestexcept(FE_DIVBYZERO)) {
			cout << "FE_DIVBYZERO ";
		}
			
		if (fetestexcept(FE_INEXACT)) {
			cout << "FE_INEXACT ";
		}
			
		if (fetestexcept(FE_INVALID)) {
			cout << "FE_INVALID ";
		}
			
		if (fetestexcept(FE_OVERFLOW)) {
			cout << "FE_OVERFLOW ";
		}
			
		if (fetestexcept(FE_UNDERFLOW)) {
			cout << "FE_UNDERFLOW ";
		}
	} else {
		cout << "None";
	}
		
	cout << endl;
}

int main() {
	fexcept_t excepts;
	feraiseexcept(FE_DIVBYZERO);

	/* save current state*/
	fegetexceptflag(&excepts, FE_ALL_EXCEPT);
	print_exceptions();
	feraiseexcept(FE_INVALID | FE_OVERFLOW);
	print_exceptions();

	/* restoring previous exceptions */
	fesetexceptflag(&excepts, FE_ALL_EXCEPT);
	print_exceptions();

	_getch();
	return 0;
}