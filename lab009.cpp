/*
C++ Program to check for balanced parentheses in an expression using stack.
Given an expression as string comprising of opening and closing characters
of parentheses - (), curly braces - {} and square brackets - [], we need to
check whether symbols are balanced or not.
*/
#include <cmath>
#include<iostream>
#include<stack>
#include<string>
using namespace std;
// Function to check whether two characters are opening 
// and closing of same type. 
bool ArePair(char opening, char closing)
{
	if (opening == '(' && closing == ')') return true;
	else if (opening == '{' && closing == '}') return true;
	else if (opening == '[' && closing == ']') return true;
	return false;
}
bool AreParanthesesBalanced(string exp)
{
	stack<char>  S;
	for (int i = 0; i<exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.empty() || !ArePair(S.top(), exp[i]))
				return false;
			else
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

double linear(string x){

	float a = 0;
	float c = 0;

	for (int i = 0; i < x.length(); i++){
		if (x[i] == 'x'){

			char* aa = &x[i - 1];
			std::string fs(aa);
			float che = std::stof(fs);
			if (x[i - 2] == '-'){
				che = -che;
			}
			a += che;
		}
		if (x[i] == '='){
			char* aa = &x[i + 2];
			std::string fs(aa);
			c = std::stof(fs);
			if (x[i + 1] == '-'){
				c = -c;
			}
		}
	}
	if (a == 0){ return 8888;}
	float ans = 0;

	ans = c / a;
	return  ans;
}
void quard(string x){

	float a = 0;
	float b = 0;
	float c = 0;
	
	for (int i = 0; i < x.length(); i++){
		if (x[i] == '^'){
			if (x[i + 1] == '2'){
				char* aa = &x[i - 2];
				std::string fs(aa);
				float che = std::stof(fs);
				if (x[i - 3] == '-'){
					che = -che;
				}
				a += che;
			}
			if (x[i + 1] == '1'){
				char* aa = &x[i - 2];
				std::string fs(aa);
				float che = std::stof(fs);
				if (x[i - 3] == '-'){
					che = -che;
				}
				b += che;
			}

		}
		if (x[i] == '='){
			char* aa = &x[i +2];
			std::string fs(aa);
			c= std::stof(fs);
			if (x[i+1] == '+'){
				c = -c;
			}
		}
		
	}

	

	
	float x1, x2, determinant, realPart, imaginaryPart;
	cout << a << b << c << endl;

	determinant = b*b - 4 * a*c;

	if (determinant > 0) {
		x1 = (-b + sqrt(determinant)) / (2 * a);
		x2 = (-b - sqrt(determinant)) / (2 * a);
		cout << "Roots are real and different." << endl;
		cout << "x1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}

	else if (determinant == 0) {
		cout << "Roots are real and same." << endl;
		x1 = (-b + sqrt(determinant)) / (2 * a);
		cout << "x1 = x2 =" << x1 << endl;
	}

	else {
		realPart = -b / (2 * a);
		imaginaryPart = sqrt(-determinant) / (2 * a);
		cout << "Roots are complex and different." << endl;
		cout << "x1 = " << realPart << "+" << imaginaryPart << "i" << endl;
		cout << "x2 = " << realPart << "-" << imaginaryPart << "i" << endl;
	}
	
}


int main()
{
	/*Code to test the function AreParanthesesBalanced*/
	while (1){
		int op;
		cout << "Enter 1 to solve linear equation\n";
		cout << "Enter 2 to solve linear equation\n";
		cin >> op;
		string expression;
		if (op == 1){
			cout << "Enter an expression of the form +ax+bx+c....=+c  "; // input expression from STDIN/Console
			cin >> expression;

			if (AreParanthesesBalanced(expression))
			{
				cout << "Balanced\n";
				float y = linear(expression);

				if (y == 8888){ cout << "invalid equation" << endl; }
				cout << "root is" << y << endl;
			}

			else
				cout << "Not Balanced\n";
		}
		if (op == 2){
			cout << "Enter an expression of the form +ax^2+...+bx^1+....=+c  "; // input expression from STDIN/Console
			cin >> expression;
			quard(expression);
		}

	}
	system("pause");
}