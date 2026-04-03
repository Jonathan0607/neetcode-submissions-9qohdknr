class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for x in tokens:
            if x=="+":
                stack.append(stack.pop()+stack.pop())
            elif x=="*":
                stack.append(stack.pop()*stack.pop())
            elif x=="-":
                a,b = stack.pop(),stack.pop()
                stack.append(b-a)
            elif x=="/":
                i = stack.pop()
                j = stack.pop()
                stack.append(int(float(j)/i))
            else:
                stack.append(int(x))
        return stack[0]
            
