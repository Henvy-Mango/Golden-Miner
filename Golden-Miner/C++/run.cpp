#include "run.hpp"
int main()
{
	//��Ļ�ֱ���
	int device_x = 1440, device_y = 810;

	//�˿ں�
	int port = 7555;

	// ������ȴ����
	//step_wait[0]Ϊ����ʱ�䣬��ͬ�ֻ������ٶȲ�ͬ
	//step_wait[1]Ϊս��+����ʱ��
	//step_wait[2]Ϊ�ؿ��ȴ�ʱ��
	int wait[3] = { 12,35,3 };

	FILE *fp = fopen("Settings.txt", "r+");
	if (fp == NULL)
	{
		printf("δ��⵽�����ļ�!��������...\n");

		fp = fopen("Settings.txt", "w+");
		fprintf(fp, "�ֱ��� = %d X %d, �ȴ�ʱ�� = { %d,%d }, �˿ں� = %d", device_x, device_y, wait[0], wait[1], port);
		fclose(fp);

		printf("�������!�����˳�!\n");
		system("pause");
		return 1;
	}
	else
	{
		//��ȡ�ļ�
		int temp = fscanf(fp, "�ֱ��� = %d X %d, �ȴ�ʱ�� = { %d,%d }, �˿ں� = %d", &device_x, &device_y, &wait[0], &wait[1], &port);
		//����ȡ�ı�������
		if (temp != 5)
		{
			printf("�ļ���ʽ����!�����˳�!\n");

			fclose(fp);

			system("pause");
			return -1;
		}
	}
	fclose(fp);

	cout << "��ǰ�ֱ���Ϊ " << device_x << " X " << device_y << endl;
	cout << "�ȴ�ʱ��Ϊ " << wait[0] << "," << wait[1] << endl;
	cout << endl << "ע��!��һ��ʹ����ȷ���������Զ�ս��ģʽ!" << endl;
	system("pause");

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
	adb_init(port);

	//ѭ��ģ�� 
	for (int i = 1; i < 223; i++)
	{
		cout << "Time #" << i << endl;
		cout << "#1 Staring..." << endl;
		tap_screen(real(1430, 880, device_x, device_y));
		Sleep(wait[0] * 1000);

		cout << "#2 Waiting..." << endl;
		for (int j = 0; j < wait[1]; j++)
		{
			DWORD start = GetTickCount(); //��ʼ��ʱ
			{
				tap_screen(real(1720, 80, device_x, device_y));
				tap_screen(real(1720, 80, device_x, device_y));
			}
			DWORD end = GetTickCount(); //������ʱ
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
