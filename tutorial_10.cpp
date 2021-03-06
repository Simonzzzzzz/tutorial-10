// Student name:	ZHOU Zhenghao
// Student ID  :	54381018

// Submission deadline : 19 Nov 2017, Sunday, 11 pm.

/*
	Part-1:
		Implement a non-recursive function to compute the Fibonacci number using looping.

	Part-2:
		Implement a function to evaluate a prefix expression using recursion.

	Part-3:
		Assume there are n integer data points on a number line.
		One can measure the distances between each pair of points.
		For n data points, there are n(n-1)/2 distance values.
		Assume the first data point is located at 0.
		Implement a recursive function to determine the values of the
		other n-1 data points from the set of distances.

		For example: let the set of data points = {0, 3, 5, 9}
		The set of distances = {3, 5, 9, 2, 6, 4}.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>  // pow(double x, double y), compute the value of x to power y

using namespace std;

bool isOperator(char c)
{
   return (c == '+' || c == '-' || c == '*' || c == '/' || c == '$');
}

double evaluateOperator(char opr, double d1, double d2)
{
	//This print statement is for debugging purpose.
	//cout << "evaluate " << d1 << " " << opr << " " << d2 << endl;

	switch (opr) 
	{
		case '+' : return d1 + d2;
		case '-' : return d1 - d2;
		case '*' : return d1 * d2;
		case '/' : return d1 / d2;
		case '$' : return pow(d1, d2);
		default : return 0;
	}
}

double nextOperand(const string& expr, int& i)
{
	int j = i;
	while (j < expr.length() && expr[j] != ' ')
		j++;

	string number = expr.substr(i, j-i);
	i = j;

	return stod(number);
}

unsigned fib(unsigned n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fib(n-2) + fib(n-1);
}

//--------------------------------- function for part_1

unsigned fib_2(unsigned n)
{
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	int prev_1=0;
	int prev_2=1;
	int temp=0;
	for(int i=2;i<=n;i++){
		temp=prev_1+prev_2;
		prev_1=prev_2;
		prev_2=temp;
	}
	
	
	// Non-recursive function to compute the Fibonacci number using looping

	// Your codes

	return temp;  // dummy return statement
}

//--------------------------------- function for part_2

double evalPrefix( string& prefix_expr,int& i)
{
	// Recursive function to evaluate a prefix expression.
	while(i<prefix_expr.length()){
	while(prefix_expr[i]=' '){
		i++;
	}
	if(isOperator((char)prefix_expr[i])){
		return evaluateOperator((char)prefix_expr[i],evalPrefix(prefix_expr,++i),evalPrefix(prefix_expr,++i));
	}
	return nextOperand(prefix_expr,i);
	}
	// Your codes

 // dummy return statement

}

double evaluate_prefix(string& prefix_expr)
{
	// Driver function to call the recursive function evalPrefix().
	int i=0;
	
	// Your local variables

	return evalPrefix(prefix_expr,i);
}

//--------------------------------- functions for part_3

int removeMax(int *d, int m)
{
	// Find and remove the max value.
	// Logically the removed value is placed at the right hand side of the array.
	int maxPos = 0;
	for (int i = 1; i < m; i++)
		if (d[i] > d[maxPos])
			maxPos = i;

	int max = d[maxPos];
	d[maxPos] = d[m-1];
	d[m-1] = max;
	return max;
}

bool removeValue(int *d, int m, int v)
{
	// Find and remove the value v from d[].
	// Logically the removed value is placed at the right hand side of the array.
	// Return true if the value v is found and removed; otherwise return false.
	

	// Your codes

	return false; // dummy return statement
}

bool fixPoint(int *x, int n, int left, int right, int *d, int m)
{
	// Return true if a solution is found; otherwise return false.

	// For debugging purpose
	/*
	cout << "Calling fixPoint: ";
	cout << "left = " << left << ", right = " << right << endl;
	cout << "d[] : ";
	for (int j = 0; j < m-1; j++)
		cout << d[j] << ", ";
	cout << d[m-1] << endl << endl;
	*/

	// Your codes

	return false; // dummy return statment
}

//---------------------------------------- driver functions prepared for you

void part_1()
{
	cout << "----- Compute Fibonacci number -----" << endl << endl;

	int k = 36;
	cout << "Non-recursive function to compute Fibonacci number\n";
	cout << "fib_2(" << k << ") = " << fib_2(k) << endl << endl;

	cout << "Recursive function to compute Fibonacci number\n";
	cout << "fib(" << k << ") = " << fib(k) << endl << endl;
}

void part_2()
{
	cout << "----- Evaluate Prefix Expression -----" << endl << endl;

	ifstream infile;
	infile.open("prefix_expr.txt");
	if (!infile.is_open())
	{
		cout << "Error: cannot open prefix_expr.txt" << endl;
		system("pause");
		exit(0);
	}

	string prefix_expr;
	while (getline(infile, prefix_expr))
	{		
		cout << "prefix expression: " << prefix_expr;
		double value = evaluate_prefix(prefix_expr);
		cout << " = " << value << endl;
	}
	cout << endl;
	infile.close();
}

bool reconstructPoint(int *x, int n, int *d, int m)
{	
	// Initialize x[0] and x[n-1]
	x[0] = 0;
	int max = removeMax(d, m);
	x[n-1] = max;

	return fixPoint(x, n, 1, n-2, d, m-1);
}

void part_3(int *d, int m)
{
	int n;
	for (n = 2; n < m; n++)
		if (n * (n-1) / 2 == m)
			break;

	cout << "----- Point set reconstruction -----\n";
	cout << "m = " << m << ", n = " << n << endl;
	cout << "d[] : ";
	for (int j = 0; j < m-1; j++)
		cout << d[j] << ", ";
	cout << d[m-1] << endl << endl;

	int *x = new int[n];
	if (reconstructPoint(x, n, d, m))
	{
		cout << "Solution:\n";
		cout << "x[] : ";
		for (int i = 0; i < n-1; i++)
			cout << x[i] << ", ";
		cout << x[n-1] << endl << endl;
	}
	else
		cout << "No solution.\n\n";
	
	delete[] x;
}

int main()
{	
	part_1();

	part_2();

	// Part_3
	int d1[] = {2, 3, 4, 5, 6, 9};
	int m1 = 6;
	part_3(d1, m1);

	int d2[] = {2, 2, 4, 5, 10, 8, 3, 7, 6, 3};
	int m2 = 10;
	part_3(d2, m2);

	int d3[] = {2, 2, 4, 5, 10, 8, 3, 7, 6, 5};
	int m3 = 10;
	part_3(d3, m3);

	int d4[] = {6};
	int m4 = 1;
	part_3(d4, m4);

	system("pause");
	exit(0);
}