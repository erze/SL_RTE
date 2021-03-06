#ifndef __RTE_ROUNDROBIN_H
#define __RTE_ROUNDROBIN_H
#ifdef __cplusplus
extern "C" {
#endif
#include "RTE_Include.h"
typedef struct
{
	uint8_t AREN:1;  /*!< Auto-reload enabled */
	uint8_t CNTEN:1; /*!< Count enabled */
	const char *TimerName;
	uint32_t ARR;                                        /*!< Auto reload value */
	volatile uint32_t CNT;                                        /*!< Counter value, counter counts down */
	void (*Callback)(void *);	                           /*!< Callback which will be called when timer reaches zero */
	void* UserParameters;                                /*!< Pointer to user parameters used for callback function */
}RTE_SoftTimer_t;
typedef struct
{
	uint8_t SoftTimerCnt;
	volatile uint32_t RoundRobinRunTick;
	RTE_SoftTimer_t *SoftTimerTable;
}RTE_RoundRobin_t;
extern void RTE_RoundRobin_TickHandler(void);
#if RTE_USE_OS == 0
extern void RTE_RoundRobin_Run(void);
#endif
extern uint8_t RTE_RoundRobin_CreateTimer(const char *Name,
	uint32_t ReloadValue, 
	uint8_t ReloadEnable, 
	uint8_t RunEnable, 
	void (*TimerCallback)(void *), 
	void* UserParameters);
extern uint8_t RTE_RoundRobin_RemoveTimer(const char *Name);
extern uint8_t RTE_RoundRobin_PauseTimer(const char *Name);
extern uint8_t RTE_RoundRobin_ResumeTimer(const char *Name);
	extern uint8_t RTE_RoundRobin_ResetTimer(const char *Name);
	extern uint8_t RTE_RoundRobin_GetTimerState(const char *Name);
	void RTE_RoundRobin_DelayMS(uint32_t Delay);
extern uint32_t RTE_RoundRobin_GetTick(void);
#ifdef __cplusplus
}
#endif
#endif
