import logging
import os
import time

def tap_screen(x, y,device_x,device_y):
    #模拟点击
    base_x, base_y = 1920, 1080
    real_x = int(x / base_x * device_x)
    real_y = int(y / base_y * device_y)
    os.system('adb shell input tap {} {}'.format(real_x, real_y))

def first_working(wait,device_x,device_y):
    logging.debug('#1 First time...')
    tap_screen(1450, 910,device_x,device_y)
    time.sleep(wait[0])

    logging.debug('#2 Auto mode active...')
    tap_screen(1780, 40,device_x,device_y)        
    for i in range(wait[1]):
        tap_screen(1720, 80,device_x,device_y)
        time.sleep(1)

    logging.debug('#3 Repeating...\n')
    tap_screen(1600, 980,device_x,device_y)
    time.sleep(wait[2])

def working(wait,device_x,device_y):
    logging.debug('#1 Starting...')
    tap_screen(1450, 910,device_x,device_y)
    time.sleep(wait[0])

    logging.debug('#2 Waiting...')

    for i in range(wait[1]):
        tap_screen(1720, 80,device_x,device_y)
        time.sleep(1)

    logging.debug('#3 Repeating...\n')
    tap_screen(1600, 980,device_x,device_y)
    time.sleep(wait[2])

def main(wait,device_x,device_y):
    #输出日志
    logging.basicConfig(format='%(asctime)s %(message)s',
        datefmt='%Y/%m/%d %I:%M:%S %p',level=logging.DEBUG)    
    
    #询问需求
    gain_money = input('需要获得的金币数(回车默认刷满):')
    if gain_money == '':
        gain_money = 4200
    else:
        gain_money = int(gain_money)
    
    #判断模块
    if gain_money >= 0 and gain_money <= 4200:
        repeat = 1 + int(gain_money / 19)
        print('还有' + str(repeat) + '次完成\n')
        
        print('三秒后开始')
        print('3')
        time.sleep(1)
        print('2')
        time.sleep(1)        
        print('1\n')
        time.sleep(1)

        #初始化
        first_working(wait,device_x,device_y)

        #循环模块 
        for i in range(repeat):
            logging.info('Time #{}'.format(i + 2))
            working(wait,device_x,device_y)
    else:
        print('Error!')
