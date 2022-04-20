from Copy import *


if __name__ == '__main__':


    stack1 = StackType()
    stack2 = StackType()


    print("PUSH 1 into stack1")
    stack1.push('1')
    
    print("PUSH 2 into stack1")
    stack1.push('2')
    
    print("PUSH 3 into stack1")
    stack1.push('3')
    print("PRINT STACK 1")
    print(stack1)


    print("copy stack1 into stack2")
    stack2.copy(stack1)
    
    print("PRINT COPIED STACK 2")
    print(stack2)

    print()

    print("POP stack2")
    stack2.pop()
    print("PUSH 7 into stack2")
    stack2.push('7')

    print("PRINT STACK 1")
    print(stack1)
    
    print("PRINT STACK 2")
    print(stack2)

    
