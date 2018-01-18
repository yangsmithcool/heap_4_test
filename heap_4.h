/*
 *	ΪFreeRTOS�е�heap_4��ֲ���ͷ�ļ�������һЩ��ֲ���趨�������ѡ��
 */

#ifndef __HEAP_4_H
#define __HEAP_4_H

#include "stdint.h"


#define configTOTAL_HEAP_SIZE                   ( ( size_t ) ( 1*1024*1024 * 1024 ) )  //�ѿռ��С����
#define configAPPLICATION_ALLOCATED_HEAP        0                             //ʹ���û��Զ���ռ���Ϊ�ѷ����ڴ�


#define vTaskSuspendAll()    NULL       //������������
#define xTaskResumeAll()     NULL       //������������

 /* Normal assert() semantics without relying on the provision of an assert.h
 header file. */
#define configASSERT( x ) if( ( x ) == 0 ) {  for( ;; ); }




 //�ֽڶ��룬������ı��������ڴ�
#define portBYTE_ALIGNMENT			8
#if portBYTE_ALIGNMENT == 8
	#define portBYTE_ALIGNMENT_MASK ( 0x0007 )
#endif

#if portBYTE_ALIGNMENT == 4
	#define portBYTE_ALIGNMENT_MASK	( 0x0003 )
#endif

#if portBYTE_ALIGNMENT == 2
	#define portBYTE_ALIGNMENT_MASK	( 0x0001 )
#endif

#if portBYTE_ALIGNMENT == 1
	#define portBYTE_ALIGNMENT_MASK	( 0x0000 )
#endif

#ifndef portBYTE_ALIGNMENT_MASK
	#error "Invalid portBYTE_ALIGNMENT definition"
#endif


//malloc׷��
#ifndef traceMALLOC
	#define traceMALLOC( pvAddress, uiSize )
#endif
//free׷��
#ifndef traceFREE
    #define traceFREE( pvAddress, uiSize )
#endif

#ifndef mtCOVERAGE_TEST_MARKER
	#define mtCOVERAGE_TEST_MARKER()
#endif



/* �������� */
void *pvPortMalloc(size_t xWantedSize);
void vPortFree(void *pv);
size_t xPortGetFreeHeapSize(void);
size_t xPortGetMinimumEverFreeHeapSize(void);

#endif
