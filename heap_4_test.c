#include <stdio.h>
#include "stdlib.h"
#include "stdint.h"
#include "string.h"
#include "stdbool.h"

#include "heap_4.h"  //heap_4��ֲ��Ŀǰ��32λϵͳ�ϲ���

#include "windows.h"

int main(int argc, char *argv[])
{
#define COUNT   (1024)
	char *str[COUNT] = { NULL };
	int count[COUNT] = { 0 }, i = 0;
	int64_t count_sum = 0;

	for (i = 0; i < COUNT; i++)
	{
		count[i] = (i + 1) * 32;
		//ʵ����ռ���ڴ��С������8�ֽڵ��ڴ�����ṹ���Ұ����õ��ֽڶ���
		int count_real = count[i] + 8;
		/* Ensure that blocks are always aligned to the required number
		of bytes. */
		if ((count_real & portBYTE_ALIGNMENT_MASK) != 0x00)
		{
			/* Byte alignment required. */
			count_real += (portBYTE_ALIGNMENT - (count_real & portBYTE_ALIGNMENT_MASK));
		}
		count_sum += count_real;
	}
	printf("COUNT=%d,count_sum=%lld\n", COUNT, count_sum);

	while (1)
	{
		//����
		for (i = 0; i < COUNT; i++)
		{
			str[i] = pvPortMalloc(count[i]);
			if (str[i])
			{
				snprintf(str[i], count[i], "malloc %d ok!\n", i);
				printf("%s", str[i]);

				//vPortFree(str[i]); str[i] = NULL;
			}
			else
			{
				printf("malloc %d failed!\n", i);
			}
		}
		//�ͷ�
		for (i = 0; i < COUNT; i++)
		{
			if (str[i])
			{
				vPortFree(str[i]); str[i] = NULL;
			}
		}

		printf("FreeHeapSize:%lu\r\n", xPortGetFreeHeapSize());
		printf("MinimumEverFreeHeapSize:%lu\r\n", xPortGetMinimumEverFreeHeapSize());

#ifdef _WIN32
		Sleep(1000);
#endif
	}
	

	system("pause");
	return 0;
}