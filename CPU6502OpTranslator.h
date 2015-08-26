/* 
 * File:   CPU6502OpTranslator.h
 * Author: Kai_Jiang
 *
 * Created on July 23, 2015, 11:31 AM
 */

#ifndef CPU6502OPTRANSLATOR_H
#define	CPU6502OPTRANSLATOR_H
#include "./dynasm/dasm_proto.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdint.h>

#define MAX_CYCLES 1000
#define COUNT_MAX 2000
#define STACK_POSITION 0x0100
	
	
using namespace std;


typedef uint16_t (*functionBlock)();
class CPU6502OpTranslator {
public:
    CPU6502OpTranslator();
    CPU6502OpTranslator(const CPU6502OpTranslator& orig);
    virtual ~CPU6502OpTranslator();
	void* getBlock();
	void* translate(uint16_t pc,uint8_t *codeMemory);
	void setUp();
    void clear();
	void checkInterrupt(uint16_t pc,uint8_t* codeMemory);
	static void doInterrupt();
	static void outPutAddress();
	

	
	uint8_t A_backup;
	uint8_t X_backup;
	uint8_t Y_backup;
	uint8_t S_backup;
	uint8_t Carry_flag;
	uint8_t Zero_flag;
	uint8_t Interrupt_flag;
	uint8_t Decimal_flag;
	uint8_t Break_flag;
	uint8_t Overflow_flag;
	uint8_t Sign_flag;
	uint8_t SR_backup;
	uint8_t* stackBase;
	
private:
    dasm_State* d;
    uint32_t npc;
	uint16_t pageBoundary;
    uint32_t nextpc;
    uint32_t cycles;
	uint32_t interruptCount;
    dasm_State** Dst;
};

#endif	/* CPU6502OPTRANSLATOR_H */


