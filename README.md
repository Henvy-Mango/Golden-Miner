# Golden-Miner
王者荣耀刷金币

## 使用说明
- 需要安卓手机
- 手机需开启USB调试模式，允许电脑调试，允许模拟点击。
- !!!重点!!!电脑安装好手机`驱动`
- 手机使用数据线接入电脑
- 电脑上需要安装[Python3](https://www.python.org/downloads/)，并在安装界面勾选Add to PATH。
![Add to PATH](https://imgsa.baidu.com/exp/w=480/sign=b0e60784a1d3fd1f3609a332004f25ce/80cb39dbb6fd5266e27ba8bea218972bd50736c3.jpg)
- 刷金币进入冒险模式，选择`魔女的回忆`，进入有闯关的按钮的界面，运行`run.bat`。
![pic](https://github.com/Henvy-Mango/Golden-Miner/raw/master/pic.png)
- 根据脚本提示输入数字后回车(直接回车默认刷4200金币)
- 重复`加载 -> 战斗 -> 结算`流程。
- 通关一次可获得19金币。
- 通关222次可获得周上限4200金币

## 注意事项
- 请根据自己手机性能和分辨率调整参数
- 脚本未正常工作时，请务必关闭脚本重新启动
- 一般修改加载时间即可达到想要的效果

## 调整方法 
- 使用文本编辑器打开`run.py`
- 修改`step_wait`以调整等待时间
```python
# 各步骤等待间隔
#step_wait[0]为加载时间，不同手机加载速度不同
#step_wait[1]为战斗时间
#step_wait[2]为结算时间
#小米6的适配参数为[12,25,3]
step_wait = [12,25,3]
```

