##arduino笔记

###1. arduino语法
arduino完全采用C/C++的语法规则，可直接使用C/C++的语法来编写代码。
###2. 数字信号输入输出
####设置引脚模式
> pinMode(pin，mode)   

其中mode有OUTPUT(输出模式)和INPUT（输入模式）。

####改变引脚电位
> digitalWrite（pin，value）

其中value有高电平（HIGH或1）、低电平（LOW或0）和输入上拉模式（INPUT_PULLUP ）。

####读取引脚状态
 > digitalRead(pin)函数

 读取pin引脚的信号状态并且返回。
####等待
 > delay(time)函数

可以将代码暂停time的时间。
###3. 项目结构
####代码块
> setup()函数

只执行一次，适合用于初始化数据。
> loop()函数

是一个循环函数,会不断地循环函数内的代码 。

###4. 模拟输入输出
在analogWrite() 和analogRead() 函数内部，已经完成了引脚的初始化，因此不用在Setup() 函数中进行初始化操作。
####模拟输入
> analogRead(pin)函数

将外部输入的模拟信号转换为芯片运算时可以识别的数字信号，从而实现读入模拟值的功能。模拟输入功能有10位精度，即可以将0～5V的电压信号转换为0～1023的整数形式表示。函数返回值为模拟值。

####模拟输出
> analogWrite(pin,value)函数

参数pin是指定要输出PWM波的引脚；参数value指定是PWM的脉冲宽度，范围为0～255。
