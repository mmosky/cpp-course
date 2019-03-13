/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 * 
 * 单元测试
 * g++ ExprTree.cpp TEST_ExprTree.cpp -o tmp -g
 */

#include "ExprTree.h"
#include <iostream>
using namespace std;

int main()
{
    /* 测试二叉树的构造和display
    ExprTree expr("(1+2)*(4-3)");
    expr.display();

    expr = "((1+2)*(4-3))";
    expr.display();

    expr = "1+2-3/(4*5-6)";
    expr.display();
    // 已通过 */

    /* 测试转换回中缀
    string expr = "(1+2)*(4-3)";
    ExprTree exprTree(expr);
    cout << "原表达式: " << expr << endl;
    cout << "建树转回: " << exprTree.toInfixExpression() << endl;

    expr = "((1+2)*(4-3))";
    exprTree = expr;
    cout << "原表达式: " << expr << endl;
    cout << "建树转回: " << exprTree.toInfixExpression() << endl;

    expr = "1+2-3/(4*5-6)";
    exprTree = expr;
    cout << "原表达式: " << expr << endl;
    cout << "建树转回: " << exprTree.toInfixExpression() << endl;
    // 通过 */

    /* 测试转换回中缀/后缀
    string expr = "(1+2)*(4-3)";
    ExprTree exprTree(expr);
    cout << "原表达式: " << expr << endl;
    cout << "转回中缀: " << exprTree.toInfixExpression() << endl;
    cout << "转回后缀: " << exprTree.toPostfixExpression() << endl;

    expr = "((1+2)*(4-3))";
    exprTree = expr;
    cout << "原表达式: " << expr << endl;
    cout << "转回中缀: " << exprTree.toInfixExpression() << endl;
    cout << "转回后缀: " << exprTree.toPostfixExpression() << endl;

    expr = "1+2-3/(4*5-6)";
    exprTree = expr;
    cout << "原表达式: " << expr << endl;
    cout << "转回中缀: " << exprTree.toInfixExpression() << endl;
    cout << "转回后缀: " << exprTree.toPostfixExpression() << endl;
    // 通过 */

    return 0;
}