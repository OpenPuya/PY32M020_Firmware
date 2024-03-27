================================================================================
                                样例使用说明
                             Sample Description
================================================================================
功能描述：
此样例演示了LPTIM中断唤醒stop模式，每次唤醒后再次进入stop模式，每200ms唤醒一次。

Function descriptions:
This sample demonstrates the LPTIM interrupt wake-up from stop mode. It enters stop mode
after each wake-up and wakes up every 200ms.
================================================================================
测试环境：
测试用板：PY32M020_STK
MDK版本： 5.28
IAR版本： 9.20
GCC版本： GNU Arm Embedded Toolchain 10.3-2021.10

Test environment:
Test board: PY32M020_STK
MDK Version: 5.28
IAR Version: 9.20
GCC Version: GNU Arm Embedded Toolchain 10.3-2021.10
================================================================================
使用步骤：
1. 编译下载程序到MCU；
2. 断开swd连接线并重新上电;
3. 按下按键进入stop模式；
4. 200ms后唤醒stop模式并循环进入stop模式再唤醒；
5. LED保持2.5Hz频率闪烁；

Example execution steps:
1.Compile and download the program to the MCU.
2.Disconnect the SWD connection wire and power on again.
3.Press the button to enter stop mode.
4.Wake up from stop mode after 200ms and repeatedly enter stop mode 
and wake up.
5.The LED will blink at a frequency of 2.5Hz.
================================================================================
注意事项：
每次唤醒后再次进入Stop模式前,必须增加延时,用于LSI和APB时钟同步。

Notes:
Before re-entering stop mode after each wake-up, a delay must be added to 
synchronize the LSI and APB clocks.
================================================================================