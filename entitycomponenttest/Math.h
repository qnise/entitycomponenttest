#pragma once

class Math
{
public:
	float fMath(float value1, char _operator, float value2) {
		switch (_operator)
		{
		case '+': return value1 + value2;
		case '-': return value1 - value2;
		case '*': return value1 * value2;
		case '/': return value1 / value2;
		case '=': return value1 = value2;
		}
	}
};