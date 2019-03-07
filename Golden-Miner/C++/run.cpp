#include "run.hpp"
int main()
{
	//屏幕分辨率
	int device_x = 1440, device_y = 810;

	//端口号
	int port = 7555;

	// 各步骤等待间隔
	//step_wait[0]为加载时间，不同手机加载速度不同
	//step_wait[1]为战斗+结算时间
	//step_wait[2]为重开等待时间
	int wait[3] = { 12,35,3 };

	FILE *fp = fopen("Settings.txt", "r+");
	if (fp == NULL)
	{
		printf("未检测到设置文件!正在生成...\n");

		fp = fopen("Settings.txt", "w+");
		fprintf(fp, "分辨率 = %d X %d, 等待时间 = { %d,%d }, 端口号 = %d", device_x, device_y, wait[0], wait[1], port);
		fclose(fp);

		printf("生成完毕!程序退出!\n");
		system("pause");
		return 1;
	}
	else
	{
		//读取文件
		int temp = fscanf(fp, "分辨率 = %d X %d, 等待时间 = { %d,%d }, 端口号 = %d", &device_x, &device_y, &wait[0], &wait[1], &port);
		//检查读取的变量个数
		if (temp != 5)
		{
			printf("文件格式错误!程序退出!\n");

			fclose(fp);

			system("pause");
			return -1;
		}
	}
	fclose(fp);

	cout << "当前分辨率为 " << device_x << " X " << device_y << endl;
	cout << "等待时间为 " << wait[0] << "," << wait[1] << endl;
	cout << endl << "注意!第一次使用请确保进入了自动战斗模式!" << endl;
	system("pause");

	//主程序 
	cout << "还有222次完成" << endl;
	cout << "三秒后开始" << endl;
	cout << "3" << endl;
	Sleep(1000);
	cout << "2" << endl;
	Sleep(1000);
	cout << "1" << endl;
	Sleep(1000);

	//虚拟机adb初始化
	adb_init(port);

	//循环模块 
	for (int i = 1; i < 223; i++)
	{
		cout << "Time #" << i << endl;
		cout << "#1 Staring..." << endl;
		tap_screen(real(1430, 880, device_x, device_y));
		Sleep(wait[0] * 1000);

		cout << "#2 Waiting..." << endl;
		for (int j = 0; j < wait[1]; j++)
		{
			DWORD start = GetTickCount(); //开始计时
			{
				tap_screen(real(1720, 80, device_x, device_y));
				tap_screen(real(1720, 80, device_x, device_y));
			}
			DWORD end = GetTickCount(); //结束计时
			int time = 1000 - (end - start);
			if (time > 0)
				Sleep(time);
		}

		cout << "#3 Repeating..." << endl;
		tap_screen(real(1620, 1000, device_x, device_y));
		Sleep(wait[2] * 1000);
	}

	system("pause");
	return 0;
}
