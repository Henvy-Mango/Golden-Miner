#include <iostream>
#include <windows.h>
using namespace std;
string to_string(int n) //int转string 
{
	const int max = 100;
	int m = n;
	char s[max];
	char ss[max];
	int i = 0, j = 0;
	if (n < 0)
	{
		m = 0 - m;
		j = 1;
		ss[0] = '-';
	}
	while (m > 0)
	{
		s[i++] = m % 10 + '0';
		m /= 10;
	}
	s[i] = '\0';
	i = i - 1;
	while (i >= 0)
	{
		ss[j++] = s[i--];
	}
	ss[j] = '\0';
	return ss;
}
string real(int tap_x, int tap_y, int device_x, int device_y) //计算物理机的真实位置 
{
	int base_x = 1920;
	int base_y = 1080;
	int real_x, real_y;
	real_x = tap_x * device_x / base_x;
	real_y = tap_y * device_y / base_y;
	string space = " ";
	string real = to_string(real_x) + space + to_string(real_y);
	return real;
}
void tap_screen(string ever) //点击屏幕 
{
	string cmd = "adb shell input tap ";
	string last = cmd + ever;
	system(last.data());
}
void adb_init() //虚拟机adb初始化连接
{
	string order = "adb connect 127.0.0.1:7555 ";
	system(order.data());
}