#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include "font.h"
#include "stm32f4xx_hal.h" 


void GUIPROP_EXT_DispChar(uint16_t c);
int GUIPROP_EXT_GetCharDistX(uint16_t c);	
void GUIPROP_EXT_GetFontInfo(const GUI_FONT GUI_UNI_PTR * pFont, GUI_FONTINFO* pfi);
char GUIPROP_EXT_IsInFont(const GUI_FONT GUI_UNI_PTR * pFont, uint16_t c);
void DisplayFont(int16_t x, int16_t y, GUI_CONST_STORAGE GUI_CHARINFO_EXT *charInfo);

#endif



