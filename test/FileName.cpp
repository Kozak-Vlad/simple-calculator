#include <iostream>
#include <vector>
#include <string>
int main() {
	int operation;
	float Multiply(float massive[], int size);
	float Add(float massive[], int size);
	float Subtract(float massive[], int size);
	float Divide(float massive[], int size);
	char again;
	std::string input;
	do
	{
		std::cout << "choose operation: press 1 for multiplication; 2 for addition; 3 for subtraction; 4 for division\n  ";
		std::cin >> operation;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::vector<float> massive;
		switch (operation)
		{
		case 1:
		{
			std::cout << "Enter numbers to multiply:\n ";
			while (true)
			{
				std::getline(std::cin, input);
				if (input.empty()) break;
				massive.push_back(std::stof(input));
			} 
			std::cout << "Result: " << Multiply(massive.data(), massive.size()) << std::endl;
			massive.clear();
			break;
		}
		case 2:
		{
			std::cout << "Enter numbers to add:\n ";
			while (true)
			{
				std::getline(std::cin, input);
				if (input.empty()) break;
				massive.push_back(std::stof(input));
			} 
			std::cout << "Result: " << Add(massive.data(), massive.size()) << std::endl;
			massive.clear();
			break;
		}
		case 3:
		{
			std::cout << "Enter numbers to subtract:\n ";
			while (true)
			{
				std::getline(std::cin, input);
				if (input.empty()) break;
				massive.push_back(std::stof(input));
			} 
			std::cout << "Result: " << Subtract(massive.data(), massive.size()) << std::endl;
			massive.clear();
			break;
		}
		case 4:
		{
			std::cout << "Enter numbers to divide:\n ";
			while (true)
			{
				std::getline(std::cin, input);
				if (input.empty()) break;
				massive.push_back(std::stof(input));
			} 
			std::cout << "Result: " << Divide(massive.data(), massive.size()) << std::endl;
			massive.clear();
			break;
		}

		}
		std::cout << "Do you want to perform another operation? (y/n):\n ";
		std::cin >> again;
	} while (again == 'y' || again == 'Y');
	return 0;
}
float Multiply(float massive[], int size)
{
	float a = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			a += massive[i];
		}
		else
		{
			a *= massive[i];
		}
	}
	return a;
}
float Add(float massive[], int size)
{
	float a = 0;
	for (int i = 0; i < size; i++)
	{
		a += massive[i];
	}
	return a;
}
float Subtract(float massive[], int size)
{
	float a = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			a += massive[i];
		}
		else
		{
			a -= massive[i];
		}
	}
	return a;
}
float Divide(float massive[], int size)
{
	float a = 0;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			a += massive[i];
		}
		else
		{
			a /= massive[i];
		}
	}
	return a;
}