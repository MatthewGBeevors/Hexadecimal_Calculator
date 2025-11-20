#include <iostream>
#include <vector>
#include <cmath>
//#include <algorithm>

using namespace std;


class Entity
{
public:
	static vector<int> Remainders;
	static float DivisionResult;

	static void CalculatorFunction(float& start_val)
	{

		for (int i = 0; i < 100; i++)
		{
			/*run the code*/
			/*DIVISION*/
			DivisionResult = start_val / 16;

			cout << "Division result = " << DivisionResult << endl;
			/*Now seperate the division into its integer part and its remainder*/
			float DivisionFloor = floor(DivisionResult);
			int DivisionRemainder = static_cast<int>((DivisionResult - DivisionFloor) * 16);

			cout << "Division Floor = " << DivisionFloor << endl
				<< "Division Remainder = " << DivisionRemainder
				<< endl << "===============" << endl;

			Remainders.push_back(DivisionRemainder);
			start_val = DivisionFloor;

			if (start_val < 1)
				break;
		}

		PrintingVector(Remainders);
	}

	static void PrintingVector(vector<int>& vector)
	{
		cout << "[ ";
		for (int n : vector)
		{
			cout << n << ", ";
		}
		cout << "]" << endl << "===============" << endl;

	}

	static void HexadecimalCoversion(std::vector<int> flipped_vector)
	{
		cout << "[ ";

		for (int n : flipped_vector)
		{
			if (n == 10)
			{
				cout << "A";
			}
			else if (n == 11)
			{
				cout << "B";
			}
			else if (n == 12)
			{
				cout << "C";
			}
			else if (n == 13)
			{
				cout << "D";
			}
			else if (n == 14)
			{
				cout << "E";
			}
			else if (n == 15)
			{
				cout << "F";
			}
			else
			{
				cout << n;
			}
			cout << ", ";
		}
		cout << "]" << endl;
	}
};

/*initalise the Remainders array outside ONCE*/
vector<int> Entity::Remainders;
//You redeclare DivisionResult inside the loop, hiding the static member. So initalise it here:
float Entity::DivisionResult = 0.0f;


/*Main function, takes in a number, calls the function to do the maths, and spits out a number*/
int main()
{
	Entity e;

	cout << "hello user" << endl << "please provide a number: ";
	float input_num;
	cin >> input_num;
	
	///*call the function*///
	e.CalculatorFunction(input_num);

	/*swap the order of the array*/
	std::reverse(e.Remainders.begin(), e.Remainders.end());
	e.PrintingVector(e.Remainders);

	/*covert values 10-15 into A-F, and print the result*/
	e.HexadecimalCoversion(e.Remainders);

}


/*NOTES:

	% THIS RETURNS THE REMAINDER SO 17 % 16 = 1

	Static member functions cannot access non-static members directly (like Remainders).

	Static functions can only access static members.

	Non-static functions can access both static and non-static members.

	Your Remainders vector should match the function type: make both static or both non-static.
	*/
	//swapping example:
	//std::vector<float> example{ 1.1, 2.22, 3.333, 4.4444, 5.55555 };
	//std::reverse(example.begin(), example.end());
	//e.PrintingVector(example);

	/*
	TODO:
	(1) - write safety net so even if a user enters an invalid value (4.5) the code wont break.
	(2) - fix the end result list to not contain an extra "," after the last value
	(3) - Write the end resulting list as just "xyz" not [x, y, z,]
	(4) - when using a huge number it puts the number into standard form losing the remainder
	*/