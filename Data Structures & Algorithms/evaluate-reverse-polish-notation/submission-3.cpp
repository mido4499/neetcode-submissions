class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        int operand;
        int operand2;

        for (string& token: tokens){
            if (token == "+" || token == "-" || token == "*" || token == "/"){
                operand = operands.top();
                operands.pop();
                operand2 = operands.top();
                operands.pop();
                char tokenChar = token[0];
                switch(tokenChar){
                    case '+':
                        operand = operand + operand2;
                        break;
                    case '-':
                        operand = operand2 - operand;
                        break;
                    case '*':
                        operand = operand2 * operand;
                        break;
                    case '/':
                        operand = operand2 / operand;
                        break;
                }
                operands.push(operand);
            }else{
                operands.push(stoi(token));
            }
        }

        return operands.top();
    }
};

