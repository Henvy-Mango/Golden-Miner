#include "run.hpp"
int main()
{
	//��Ļ�ֱ���
	int device_x = 1440, device_y = 810;

	int wait[] = { 10,24,3 };
	// ������ȴ����
	//step_wait[0]Ϊ����ʱ�䣬��ͬ�ֻ������ٶȲ�ͬ
	//step_wait[1]Ϊս��ʱ��
	//step_wait[2]Ϊ����ʱ��

	//������ 
	cout << "����222�����" << endl;
	cout << "�����ʼ" << endl;
	cout << "3" << endl;
	Sleep(1000);
	cout << "2" << endl;
	Sleep(1000);
	cout << "1" << endl;
	Sleep(1000);

	//�����adb��ʼ��
	adb_init();

	//ѭ��ģ�� 
	for (int i = 1; i < 223; i++)
	{
		cout << "Time #" << i << endl;
		cout << "#1 Staring..." << endl;
		tap_screen(real(1450, 910, device_x, device_y));
		Sleep(wait[0] * 1000);

		cout << "#2 Waiting..." << endl;
		for (int j = 0; j < wait[1]; j++)
		{
			tap_screen(real(1720, 80, device_x, device_y));
			Sleep(1000);
		}

		cout << "#3 Repeating..." << endl;
		tap_screen(real(1600, 980, device_x, device_y));
		Sleep(wait[2] * 1000);
	}
	system("pause");
	return 0;
}