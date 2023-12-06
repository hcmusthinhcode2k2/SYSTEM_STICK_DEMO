/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/mcc.h"
#include "systick/SystemTick.h"

static void TMR1_CallBack(void)
{
    LED1_Toggle();
    LED2_Toggle();
}
/*
                         Main application
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    TMR1_SetInterruptHandler(TMR1_CallBack);
    SystemTick_Init();
    tick_timer_t Tick1;
    // tick_timer_t Tick2;
    Tick_Timer_Reset(Tick1);
    // Tick_Timer_Reset(Tick2);
    LED1_SetHigh();
    LED2_SetLow();
    while (1)
    {
        // Add your application code
        if (!S1_GetValue()){
           if (Tick_Timer_Is_Over_Ms(Tick1, 1000))
           {
            RGB_RED_SetHigh();
           }
        } else {
            if (Tick_Timer_Is_Over_Ms(Tick1, 1000))
            {
               RGB_RED_SetLow();
            }
        }
        
        if (!S2_GetValue())
        {
            if (Tick_Timer_Is_Over_Ms(Tick1, 1000))
            {
              RGB_GREEN_SetHigh();
            }
        } else {
            if (Tick_Timer_Is_Over_Ms(Tick1, 1000))
            RGB_GREEN_SetLow();
        }
        
        if (!S3_GetValue())
        {
             if (Tick_Timer_Is_Over_Ms(Tick1, 1000))
             {
                   RGB_BLUE_SetHigh();
             }
           
        } else {
             if (Tick_Timer_Is_Over_Ms(Tick1, 1000))
             {
                RGB_BLUE_SetLow();
             }
        }
    }
    return 1; 
}
/**
 End of File
*/

