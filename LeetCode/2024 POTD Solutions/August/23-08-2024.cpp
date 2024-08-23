/*
Problem of the Day: 592. Fraction Addition and Subtraction
Problem Description: https://medium.com/@pradeepsooryavanshee1210/592-fraction-addition-and-subtraction-leetcode-solution-698d032c58f6
*/

class Solution
{
public:
    string fractionAddition(string expression)
    {
        int numerator = 0, denominator = 1;
        int i = 0, n = expression.size();

        while (i < n)
        {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-')
            {
                sign = expression[i] == '+' ? 1 : -1;
                i++;
            }

            int num = 0;
            while (i < n && isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }

            i++;

            int denom = 0;
            while (i < n && isdigit(expression[i]))
            {
                denom = denom * 10 + (expression[i] - '0');
                i++;
            }

            numerator = numerator * denom + sign * num * denominator;
            denominator *= denom;

            int gcd = std::gcd(abs(numerator), denominator);
            numerator /= gcd;
            denominator /= gcd;
        }

        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};