//tempalte Example

#include <iostream>

using namespace std;

template <typename T1, typename T2>
void sample(T1 a, T2 b){
	cout << a + b << "\n";
}

template <typename T2> // template specialization (템플릿 특수화) 
void sameple(bool a, T2 b){
	if(a){
		cout << b << "\n";
	}
}

int main() {
	int a = false;
	double b = 1.5;
	
	sample(a, b);
	
	return 0;
}
