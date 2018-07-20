#include <iostream>
#include <windows.h>
using namespace std;
string to_string(int n) //int转string 
{
	const int max = 100;
    int m = n;
    char s[max];
    char ss[max];
    int i=0,j=0;
    if (n < 0)
    {
        m = 0 - m;
        j = 1;
        ss[0] = '-';
    }    
    while (m>0)
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
string real(int x,int y,int device_x,int device_y) //计算物理机真实位置 
{
	int base_x = 1920;
	int base_y = 1080;
	int real_x,real_y;
	real_x = x * (base_x / device_x);
	real_y = y * (base_y / device_y);
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
