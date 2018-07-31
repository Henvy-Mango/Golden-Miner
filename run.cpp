#include "function.hpp"
int main()
{
	//屏幕分辨率(根据手机修改)
	int device_x = 1920,device_y = 1080;
	
	int wait[] = {10,22,3}; 
	// 各步骤等待间隔
	//step_wait[0]为加载时间，不同手机加载速度不同
	//step_wait[1]为战斗时间
	//step_wait[2]为结算时间

	//主程序 
	cout<<"还有222次完成"<<endl;
	cout<<"三秒后开始"<<endl;
	cout<<"3"<<endl;
	Sleep(1000);
	cout<<"2"<<endl;
	Sleep(1000);
	cout<<"1"<<endl;
	Sleep(1000);
	
	//虚拟机adb初始化
	//adb_init();
	
	//循环模块 
	for(int i=1;i<223;i++)
	{	
		cout<<"Time #"<<i<<endl;
		cout<<"#1 Staring..."<<endl;
		tap_screen(real(1450,910,device_x,device_y));
		Sleep(wait[0]*1000);
		
		cout<<"#2 Waiting..."<<endl;
		for(int j=0;j<wait[1];j++)
		{
			tap_screen(real(1720,80,device_x,device_y));
			Sleep(1000);
		}
		
		cout<<"#3 Repeating..."<<endl;
		tap_screen(real(1600,980,device_x,device_y));
		Sleep(wait[2]*1000);
	}
	system("pause");
	return 0;
}
