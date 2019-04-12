/**
 * RangeIO 类, 封装了包含特定范围的输入输出
 * readInt(): 读入一个合法的整数
 * readInt(maxVal): 读入一个整数, 处于[0, maxVal]范围内
 * readInt(minVal, maxVal): 读入一个整数, 处于[minVal, maxVal]范围内
 * readIntFromLine(): 读入一行, 与上面相同
 */

#include <iostream>

class RangeIO
{
  public:
    /* 从给定的流读入一个int, 直到符合范围为止 */
    static int readInt(std::istream &in);
    static int readInt(std::istream &in, int maxVal);
    static int readInt(std::istream &in, int minVal, int maxVal);

    static int readIntFromLine(std::istream &in);
    static int readIntFromLine(std::istream &in, int maxVal);
    static int readIntFromLine(std::istream &in, int minVal, int maxVal);
};