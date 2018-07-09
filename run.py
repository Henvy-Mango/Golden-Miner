# -*- coding: utf-8 -*-
import logging
import os
import time
from functions import main
# 屏幕分辨率(根据手机修改)
x,y = 1920, 1080

#使用说明
#刷金币进入冒险模式，选择魔女的回忆，进入有闯关的按钮的界面，运行脚本。

# 各步骤等待间隔
#step_wait[0]为加载时间，不同手机加载速度不同
#step_wait[1]为战斗时间
#step_wait[2]为结算时间
#小米6的适配参数为[10,20,3]
wait_times = [10,20,3]

# 刷金币次数
#刷满4200金币需要222次
#直接回车默认刷满
main(wait_times,x,y)

