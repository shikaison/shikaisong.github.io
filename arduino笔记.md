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

可以将代码暂停time的时间。
###3. 项目结构
####代码块
> setup()

只执行一次，适合用于初始化数据。
> loop()

是一个循环函数,会不断地循环函数内的代码 。

###4. 模拟输入输出
在analogWrite() 和analogRead() 函数内部，已经完成了引脚的初始化，因此不用在Setup() 函数中进行初始化操作。
####模拟输入
> analogRead(pin)

将外部输入的模拟信号转换为芯片运算时可以识别的数字信号，从而实现读入模拟值的功能。模拟输入功能有10位精度，即可以将0～5V的电压信号转换为0～1023的整数形式表示。函数返回值为模拟值。

####模拟输出
> analogWrite(pin,value)

参数pin是指定要输出PWM波的引脚；参数value指定是PWM的脉冲宽度，范围为0～255。

###高级输入输出
####调声函数
> tone(pin, frequency) tone(pin, frequency, duration)

主要用于Arduino连接蜂鸣器或扬声器发声。可以让指定引脚产生一个占空比为50%的指定频率的方波。
pin: 需要输出方波的引脚 frequency: 输出的频率，unsigned int型 duration: 方波持续的时间，单位毫秒。如果没有该参数，Arduino将持续发出设定的音调，直到你改变发声频率或者使用noTone() 函数停止发声。

> noTone(pin)

停止发声。

####检测脉冲信号宽度
 > pulseIn(pin, value) pulseIn(pin, value, timeout)

pin：需要读取脉冲的引脚
value：需要读取的脉冲类型，HIGH或LOW
timeout：超时时间，单位微秒，数据类型为无符号长整型。
返回脉冲宽度，单位微秒，数据类型为无符号长整型。如果在指定时间内没有检测到脉冲，则返回0。pulseln() 函数会返回这个脉冲信号持续的时间，即这个脉冲的宽度。
函数还可以设定超时时间。如果超过设定时间，仍未检测到脉冲，则会退出pulseIn()函数并返回0。
当没有设定超时时间时，pulseIn() 会默认1秒钟的超时时间。

####中断函数
> attachInterrupt(pin, ISR, mode)

pin：中断引脚
ISR：中断函数名
mode：中断模式
响应中断的处理程序——中断函数，当中断触发后，Arduino便会运行ISR函数。该函数不能带任何参数，且返回类型为空。

####中断分离函数
> detachInterrupt(pin)

如果你不需要使用外部中断了，你可以用中断分离函数detachInterrupt() 来关闭中断功能。

###时间控制
####时间运行函数
> millis()

获取Arduino通电后（或复位后）到现在的时间,单位毫秒ms。返回系统运行时间，单位毫秒。
> micros()

获取Arduino通电后（或复位后）到现在的时间，单位微秒us。返回系统运行时间，单位微秒。

###延时函数
> delay( )

此函数为毫秒级延时。参数为时长，类型unsigned long.
> delayMicroseconds( )

此函数为微秒级延时。参数为时长,类型unsigned int.

###串口通信
#####串口配置
> 