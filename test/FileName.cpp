#include <iostream>
#include <vector>
#include <string>
struct Token {
	float value;
	char op;
	bool isNumber;
};
std::vector<Token> tokenize(const std::string& expr) {
	std::vector<Token> tokens;
	std::string num;
	for (char c : expr) {
		if (std::isdigit(c) || c == '.') {
			num += c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			if (!num.empty()) {
				tokens.push_back({ std::stof(num), 0, true });
				num.clear();
			}
			tokens.push_back({ 0, c, false });
		}
	}
	if (!num.empty()) tokens.push_back({ std::stof(num), 0, true });
	return tokens;
}
float evaluate(const std::vector<Token>& tokens) {
	std::vector<Token> temp = tokens;
	float result = 0;
	// Спочатку множення і ділення
	for (int i = 0; i < temp.size(); i++) {
		if (!temp[i].isNumber && (temp[i].op == '*' || temp[i].op == '/')) 
		{
			float left = temp[i - 1].value;
			float right = temp[i + 1].value;
			float result = (temp[i].op == '*') ? (left * right) : (left / right);

			// Замінюємо три токени на один результат
			temp[i - 1].value = result;
			temp.erase(temp.begin() + i, temp.begin() + i + 2);
			i--;
		}
	}
	if (temp.empty()) return 0;
	result = temp[0].value;
	for (int i = 1; i < temp.size(); i += 2) {
		char op = temp[i].op;
		float num = temp[i + 1].value;
		if (op == '+') result += num;
		if (op == '-') result -= num;
	}
    return result;
}

int main() {
	while(true)
	{
		std::string expr;
		std::cout << "Enter expression (e.g. 2+3*4-5/2): ";
		std::getline(std::cin, expr);

		auto tokens = tokenize(expr);
		float result = evaluate(tokens);
		std::cout << "Result: " << result << std::endl;
		if (expr.empty()) break;
	}
	return 0;
    
}