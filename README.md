# Golden-Miner
王者荣耀自动获取金币

## 使用准备
- [MuMu模拟器](http://mumu.163.com/)（请在设置中选择分辨率`1440x810`，或者稍后去调整程序参数）
- 模拟器设置中的开发者选项需勾选`USB调试模式`
- 运行以下任意版本的脚本（脚本和模拟器均可后台运行）

## 收益说明
- 通关一次可获得19金币。
- 通关222次可获得周上限4200金，大概需要两个半小时

## 注意事项
- 请确保**第一次**战斗进入了自动战斗模式，否则所有操作可能会延后
- 模拟器开启后第一次进入冒险模式会加载比较长的时间，第二次时间会减少
- 建议加载时间使用第二次加载冒险模式的时间
- 脚本未正常工作时，可以看看下面的错误排查
- 请根据自己电脑的性能，建议使用手机秒表功能来计时各阶段，来调整程序参数

## 使用说明
- 模拟器进入冒险模式，选择`魔女的回忆`，进入带有闯关的按钮的界面。
![pic](https://github.com/Henvy-Mango/Golden-Miner/raw/master/pic.png)
- 选择使用三个射手英雄
- 使用脚本前一定要进入上面图片所示的界面
- 运行`run.exe`或者`run.bat`即可。

## C++版参数调整方法
- 使用文本编辑器打开`Settings.txt`
```
	分辨率 = 1440 X 810, 等待时间 = { 14,35 }
```
- 等待时间的数据依次为加载时间、战斗+结算时间
- 建议使用手机计时各阶段来调整程序参数

## Python版参数调整方法 
- 使用文本编辑器打开`run.py`
- 修改`x` `y`调整分辨率
- 修改`wait_times`以调整等待时间
- 脚本重复`加载 -> 战斗 -> 结算`三个流程
- 建议使用手机计时各阶段来调整程序参数
```python
	# 屏幕分辨率
	x,y = 1440, 810

	# 各步骤等待间隔
	#step_wait[0]为加载时间
	#step_wait[1]为战斗时间
	#step_wait[2]为结算时间
	wait_times = [18,22,3]
```
## Python版
- 电脑上需要安装Python3.4以上的版本，并在安装界面勾选Add to PATH。
![Add to PATH](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1546095061&di=cc3e0fa6759cc89f5b96b61d44e8fb8c&imgtype=jpg&er=1&src=http%3A%2F%2Fb.hiphotos.baidu.com%2Fexp%2Fw%3D480%2Fsign%3D94ec2c1128a446237ecaa46aa8237246%2F11385343fbf2b2116addd325c28065380dd78eee.jpg)
## 错误排查
- 脚本在运行，但虚拟机无反应，不能自动点击
- 检查分辨率是否正确
- 开发者选项`USB调试模式`是否打开
