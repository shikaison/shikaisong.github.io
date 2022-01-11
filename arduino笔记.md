##arduino笔记
####arduino语法
arduino完全采用C/C++的语法规则，可直接使用C/C++的语法来编写代码。
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
####代码块
> setup()函数

只执行一次，适合用于初始化数据。
> loop()函数

是一个循环函数,会不断地循环函数内的代码 。

