#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include <rocketlink/mavlink.h>

void stateMachine();
void manualAbort();
void manualProceed();
void forceGoto(ENGINE_COMPUTER_STATE new_state);
void gotHeartbeat();

// uint32_t timeIgnitionStart = 0, timeLastHeartbeat = 0;
// bool proceedFlag = false, manualProceedFlag = false, manualAbortFlag = false;
// inline void setAbortFlags();
// inline void handleAborts();

//Rocket rocket = Rocket();
#endif // __STATEMACHINE_H__