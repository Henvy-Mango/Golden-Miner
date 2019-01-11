# -*- coding: utf-8 -*-
import functions
# 屏幕分辨率
x,y = 1440,810 

#使用说明
#刷金币进入冒险模式，选择魔女的回忆，进入有闯关的按钮的界面，运行脚本。

# 各步骤等待间隔
#step_wait[0]为加载时间，不同手机加载速度不同
#step_wait[1]为战斗时间
#step_wait[2]为结算时间
wait_times = [18,22,3]

print("当前分辨率为 {} X {}\n".format(x,y))
print("等待时间为 {0[0]} {0[1]} {0[2]}".format(wait_times))

# 刷金币次数
#刷满4200金币需要222次
#直接回车默认刷满
#虚拟机adb初始化
#functions.VT_init()

#functions.main(wait_times,x,y)
