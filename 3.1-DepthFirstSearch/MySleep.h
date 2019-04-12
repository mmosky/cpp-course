/**
 * Copyright (c) 2019 MMMMMMoSky All rights reserved.
 * 
 * 一个跨平台的 Sleep
 * 参考 https://www.cnblogs.com/foohack/p/5013272.html
 * 目前在以下系统可以正常使用:
 *  Mac OS 9                macintosh Macintosh
 *  Mac OS X (macOS)        __APPLE__ __MACH__
 *  Linux kernel            __linux__
 *  Windows                 _WIN32 _WIN64
 */

class MySleep
{
  public:
    // 单位: 毫秒
    static void mSleep(unsigned int ms);
};