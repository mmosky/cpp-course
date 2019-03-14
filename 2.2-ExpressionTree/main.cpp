/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 * 
 * g++ ExprTree.cpp main.cpp -o tmp
 * 
 * 命令行交互式
 * Usage:
 *  expr [expression]   用expr建树
 *  show [type] 展示当前的树的某种视图
 *      show tree
 *      show infix
 *      show postfix
 *  help
 *  exit
 */

#include "ExprTree.h"

#include <iostream>

using namespace std;

void help()
{
    cout << "用法:" << endl;
    cout << "  expr [expression] # 使用expression表达式建树" << endl;
    cout << "                    # 需要是合法中缀表达式且只含 '0-9', '+-*/' 和 '()'" << endl;
    cout << endl;
    cout << "  show [view]       # 展示当前表达式的某种视图" << endl;
    cout << "    show tree       # 打印表达式的二叉树视图" << endl;
    cout << "    show infix      # 打印中缀表达式" << endl;
    cout << "    show postfix    # 打印后缀表达式" << endl;
    cout << endl;
    cout << "  help              # 打印此页面" << endl;
    cout << "  exit              # 退出" << endl;
}

int main()
{
    string cmd, para;
    ExprTree tree;

    cout << "-- 表达式转换工具 --" << endl;

    while (true)
    {
        cout << "> ";
        getline(cin, cmd);

        // exit 命令
        if (cmd == "exit")
        {
            cout << "Bye~";
            exit(0);
        }

        // help 命令
        if (cmd == "help")
        {
            help();
            continue;
        }

        size_t pos = cmd.find(' ');
        if (pos == cmd.npos)
        {
            cout << "命令错误: 输入 'help' 以获取帮助" << endl;
            continue;
        }

        para = cmd.substr(pos + 1); 
        cmd = cmd.substr(0, pos - 1);

        // expr 命令
        if (cmd == "expr")
        {
            if (ExprTree::isValid(para))
            {
                tree = para;
            }
            else
            {
                cout << "需要是合法中缀表达式且只含 '0-9', '+-*/' 和 '()'" << endl;
            }
            continue;
        }

        // show 命令
        if (cmd == "show")
        {
            if (para == "tree")
            {
                tree.display();
                continue;
            }
            if (para == "infix")
            {
                cout << tree.toInfixExpression() << endl;
                continue;
            }
            if (para == "postfix")
            {
                cout << tree.toPostfixExpression() << endl;
                continue;
            }
        }

        cout << "命令错误: 输入 'help' 以获取帮助" << endl;
    }
}