# 引用numpy和matplotlib库
import numpy as np
import math
import matplotlib.pyplot as plt


def huaban(ls):
    plt.figure(figsize=(10, 10))
    # 确立子图对应
    ax1 = plt.subplot(3, 2, 1)
    ax2 = plt.subplot(3, 2, 2)
    ax3 = plt.subplot(3, 2, 3)
    ax4 = plt.subplot(3, 2, 4)
    ax5 = plt.subplot(3, 2, 5)
    ax6 = plt.subplot(3, 2, 6)

    plt.subplots_adjust(wspace=0.9, hspace=0.9)  # 调整子图间距
    # 建立坐标系
    ax1.set(xlim=[0.0, 1.0], ylim=[0.0, 40.0], title=ls[0], ylabel='I', xlabel='COS^')
    ax2.set(xlim=[-1.0, 1.0], ylim=[-1.0, 1.0], title=ls[1], ylabel='Y', xlabel='X')
    ax3.set(xlim=[-10.0, 10.0], ylim=[-10.0, 10.0], title=ls[2], ylabel='Y', xlabel='X')
    ax4.set(xlim=[-10.0, 10.0], ylim=[-10.0, 10.0], title=ls[3], ylabel='Y', xlabel='X')
    ax5.set(xlim=[-10.0, 10.0], ylim=[-10.0, 10.0], title=ls[4], ylabel='Y', xlabel='X')
    ax6.set(xlim=[-10.0, 10.0], ylim=[-10.0, 10.0], title=ls[5], ylabel='Y', xlabel='X')

    x = np.linspace(-10.0, 10.0, 1000)
    # 创建函数关系
    a = np.cos(x)
    b = np.cos(x ** 2)
    c = np.cos(x)
    d = np.log(x)
    e = np.log10(x)
    f = np.log2(x)

    # 绘制图像
    ax1.plot(x, a, 'k', color='r')
    ax2.plot(x, b, 'k', color='r')
    ax3.plot(x, c, 'k', color='r')
    ax4.plot(x, d, 'k', color='r')
    ax5.plot(x, e, 'k', color='r')
    ax6.plot(x, f, 'k', color='r')
    # 显示图像
    plt.show()


def main():
    # 确立标题
    head = ("cos", "cosx**2", "tan", "log", "log10", "log2")
    huaban(head)


main()

