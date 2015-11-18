#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Author: Zeyuan Shang
# @Date:   2015-11-18 17:22:37
# @Last Modified by:   Zeyuan Shang
# @Last Modified time: 2015-11-18 17:22:44
class Solution:
    operators = ['+', '-', '*', '/']
    
    def getPriority(self, operator):
        return {
            '+' : 1,
            '-' : 1,
            '*' : 2,
            '/' : 2,
        }.get(operator, 0)
    
    def toRPN(self, s):
        tokens, stack = [], []
        number = ''
        for c in s:
            if c.isdigit():
                number += c
            else:
                if number:
                    tokens.append(number)
                    number = ''
                if c in self.operators:
                    while len(stack) and self.getPriority(stack[-1]) >= self.getPriority(c):
                        tokens.append(stack.pop())
                    stack.append(c)
                elif c == '(':
                    stack.append(c)
                elif c == ')':
                    while len(stack) and stack[-1] != '(':
                        tokens.append(stack.pop())
                    stack.pop()
        if number:
            tokens.append(number)
        while len(stack):
            tokens.append(stack.pop())
        return tokens
        
    def calcValue(self, x, y, operator):
        return {
            '+': lambda x, y: x + y,
            '-': lambda x, y: x - y,
            '*': lambda x, y: x * y,
            '/': lambda x, y: int(float(x) / y),
        }[operator](x, y)
        
    def evalRPN(self, tokens):
        operands = []
        for token in tokens:
            if token in self.operators:
                y, x = operands.pop(), operands.pop()
                operands.append(self.calcValue(x, y, token))
            else:
                operands.append(int(token))
        return operands[0]
    
    def calculate(self, s):
        tokens = self.toRPN(s)
        return self.evalRPN(tokens)