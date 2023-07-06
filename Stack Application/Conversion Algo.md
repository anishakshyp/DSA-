## Infix to Postfix -
1. Create a stack
2. for each character ‘t’ in the input
{
if (‘t’ is an operand)
output ‘t’;
else if (‘t’ is a right parenthesis)
{
pop and output token until a left parenthesis is
popped (but left parenthesis should not display in the
output string)
}
else \\ ‘t’ is the operator or left parenthesis
{
pop and output the operators which have precedence
greater than or equal to the precedence of the
incoming operator ‘t’ or left parenthesis is
encountered or the stack is empty.
}
3. pop and output all the tokens until the stack is empty.

## Postfix Evaluation -
1. Scan the postfix string array from left to right
2. Initialize an empty stack
3. Repeat steps 4 and 5 till all the characters are scanned
4. If the scanned character is an operand, push it onto the
stack
5. If the scanned character is an operator, and if the
operator is unary, then pop an element from the stack.
If the operator is binary, then pop two elements from
the stack. After popping the element, apply the operator
to those popped elements. Finally, push the result on to
the stack.
6. After all the elements are scanned, the result will be in
the stack. Return the result by popping the stack.

## Postfix to Infix -
1. Scan the given postfix expression from left to right
character by character.
2. If the character is an operand, then push it into the
stack.
3. If a character is an operator,
i. pop operand from the stack, say it’s operand2.
ii. pop operand from the stack, say it’s operand1.
iii. concatenate (operand1 operator operand2) and
push it to stack.
4. Repeat this process until the end of postfix expression.
5. Finally, there is only one value in the stack, i.e., infix
expression.
6. Return infix expression by popping the stack.

## Prefix to Infix -
1. Scan the given prefix expression from right to left
character by character.
2. If the character is an operand, then push it into the
stack.
3. If a character is an operator,
i. pop operand from the stack, say it’s operand2.
ii. pop operand from the stack, say it’s operand1.
iii. concatenate (operand1 operator operand2) and
push it to stack.

4. Repeat this process until the end of prefix expression.
5. Finally, there is only one value in the stack, i.e., infix
expression.
6. Return infix expression by popping the stack.
