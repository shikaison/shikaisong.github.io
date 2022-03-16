# 引用numpy和matplotlib库
import numpy as np
import math
import matplotlib.pyplot as plt
def huaban(ls,scale_,max,min):
    plt.figure(figsize=(10, 10))
    # 建立坐标系
    ax = plt.subplot(1,1,1)
    ax.set(xlim=[-10.0, 10.0], ylim=[0.0, 40.0], title=ls, ylabel='I', xlabel= 's')
    x = np.linspace(max, min, scale_)
    # 创建函数关系
    a = np.cos(x)
    # 绘制图像
    ax.plot(x, a, 'k', color='r')
    # 显示图像
    plt.show()
def main():
    # 确立标题
    head = input(("请输入函数名："))
    min = eval(input("请输入x轴的最小值:"))
    max = eval(input("请输入x轴的最大值:"))
    scale = eval(input("请输入分度值:"))
    scale_ = int((max - min)/scale)
    huaban(head,scale_,max,min)
main()

