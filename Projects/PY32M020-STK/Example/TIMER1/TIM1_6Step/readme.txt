================================================================================
                                样例使用说明
                             Sample Description
================================================================================
功能描述：
此样例是对高级定时器功能“六步PWM的产生”的演示，通过systick中断作为COM commutation
事件的触发源，实现（无刷电机的）换向。

Function descriptions:
This sample demonstrates the "Six-step PWM Generation" feature of the advanced 
timer. It uses the systick interrupt as the trigger source for the COM 
commutation event to achieve commutation of a brushless motor. 
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
1. 编译并下载程序；
2. 刹车输入（PA06）接低电平；
3. 用示波器或逻辑分析仪接CH1(PA08)、CH1N(PA07)、CH2(PA09)、CH2N(PB00)、CH3(PA10)、
CH3N(PB01)，可监测到注意事项中的PWM波形；
4. 刹车输入（PA06）接高电平，触发刹车，可观测到6个通道波形都没有了，并输出空闲电平
（空闲电平有寄存器配置决定）。

Example execution steps:
1.Compile and download the program.
2.Connect the brake input (PA06) to a low level.
3. Use an oscilloscope or logic analyzer to connect CH1 (PA08), CH1N (PA07), 
CH2 (PA09), CH2N (PB00), CH3 (PA10), CH3N (PB01), and can monitor the PWM 
waveform in the notes;
4. Brake input (PA06) is connected to high level to trigger the brake, which 
can be observed that all 6 channel waveforms are gone and output idle level 
(idle level is determined by register configuration).
================================================================================
注意事项：
下表是换向步骤，比如第一步中的CH1和CH2N为1，即设置打开这两个通道的PWM输出。
PWM时序如下：
        第一步      第二步      第三步      第四步      第五步     第六步     
CH1      1           0           0           0           0          1          
CH1N     0           0           1           1           0          0          
CH2      0           0           0           1           1          0          
CH2N     1           1           0           0           0          0          
CH3      0           1           1           0           0          0          
CH3N     0           0           0           0           1          1          

CH1  (PA08)   |||||||_________________________________||||||||||||||_________________________________|||||||
CH1N (PA07)   _______________||||||||||||||||_______________________________||||||||||||||||________________
                                  
CH2  (PA09)   _______________________||||||||||||||||_______________________________||||||||||||||||________
CH2N (PB00)   |||||||||||||||________________________________|||||||||||||||________________________________
                                  
CH3  (PA10)   _______||||||||||||||||_______________________________||||||||||||||||________________________
CH3N (PB01)   ________________________________|||||||||||||||________________________________|||||||||||||||

Notes:
The table below 
shows the PWM sequence for each step, where CH1 and CH2N are set to 1 in the 
first step, indicating the activation of these two channels for PWM output.
The PWM sequence is as follows:
        Step 1      Step 2      Step 3      Step 4      Step 5     Step 6     
CH1      1           0           0           0           0          1          
CH1N     0           0           1           1           0          0          
CH2      0           0           0           1           1          0          
CH2N     1           1           0           0           0          0          
CH3      0           1           1           0           0          0          
CH3N     0           0           0           0           1          1          

CH1  (PA08)   |||||||_________________________________||||||||||||||_________________________________|||||||
CH1N (PA07)   _______________||||||||||||||||_______________________________||||||||||||||||________________
                                  
CH2  (PA09)   _______________________||||||||||||||||_______________________________||||||||||||||||________
CH2N (PB00)   |||||||||||||||________________________________|||||||||||||||________________________________
                                  
CH3  (PA10)   _______||||||||||||||||_______________________________||||||||||||||||________________________
CH3N (PB01)   ________________________________|||||||||||||||________________________________|||||||||||||||
================================================================================