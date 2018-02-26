# -*- coding: utf-8 -*-
import logging
import os
import time

# 屏幕分辨率
device_x, device_y = 1920, 1080

#使用说明
#刷金币进入冒险模式，选择魔女的回忆，进入有闯关的按钮的界面，运行脚本。

# 各步骤等待间隔
#step_wait[0]为加载时间，不同手机加载速度不同
#step_wait[1]为战斗时间
#step_wait[2]为结算时间
#小米6的适配参数为[12,25,2]
step_wait = [12,25,2]

# 刷金币次数
#刷满4200金币需要222次
repeat_times = 222 

# 日志输出
logging.basicConfig(format='%(asctime)s %(message)s',datefmt='%m/%d/%Y %I:%M:%S %p',level=logging.DEBUG)

def tap_screen(x, y):
    base_x, base_y = 1920, 1080
    real_x = int(x / base_x * device_x)
    real_y = int(y / base_y * device_y)
    os.system('adb shell input tap {} {}'.format(real_x, real_y))

def do_money_work():
    logging.debug('#1 ready, go!!!')
    tap_screen(1450, 910)
    time.sleep(step_wait[0])

    logging.debug('#2 auto power on!')
    tap_screen(1780, 40)

    for i in range(step_wait[1]):
        tap_screen(1720, 80)
        time.sleep(1)

    logging.debug('#3 do it again...\n')
    tap_screen(1600, 980)
    time.sleep(step_wait[2])


if __name__ == '__main__':
    gain_money = input('需要获得的金币数：\n')
    gain_money = int(gain_money)

    if gain_money >= 0 and gain_money < 4200:
        repeat_times = 1 + int(gain_money / 19)
        
        print('还有' + str(repeat_times) + '次完成')
        
        for i in range(repeat_times):
            logging.info('round #{}'.format(i + 1))
            do_money_work()
    else:
        print('Error!')
    
