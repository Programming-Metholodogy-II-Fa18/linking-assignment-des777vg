Name - Desmond Johnson (RUID - 191001434)
This contains the code for problem 1. The int main used to test this file will be shown at the bottom.

Please note that int output[arraySize]; did not cause any compile issues using atom with a c++ compilewr, but it did in visula studio. If for some reason you experience an issue with this array, please ensure that arraySize is intialized the same way as shown in the example main function below. If the issue still persists, please set the size of output manually to the current arraySize.



using namespace std;
//-----------------------

int main() {

	int arraypass[5] = {32,  47, 7, 236, 229 };
	int arr_size = sizeof(arraypass) / sizeof(arraypass[0]);;
	Problem1(arraypass, arr_size);
	while (1) {

	}
}
