#include "display.h"
#include "lcd.h"
#include "font.h"


#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif
	
//GUI_CONST_STORAGE GUI_FONT GUI_FontArial24;
GUI_CONTEXT gContext;
//GUI_FONT gFont;
	
void LCD_Color_DrawPoint(uint16_t x,uint16_t y,uint16_t color);	//ÑÕÉ«»­µã

void Font_Init(void)
{
	gContext.pAFont = &GUI_FontArial24;
//	gFont 
}	

void SetFont(GUI_CONST_STORAGE GUI_FONT *guiFont)
{
	gContext.pAFont = &GUI_FontArial24;
}

void GUIPROP_EXT_DispChar(uint16_t c)
{
	int16_t xpos, ypos;
	int16_t color;
	int16_t bakColor;
	GUI_CONST_STORAGE GUI_FONT *guiFont;
	GUI_CONST_STORAGE GUI_FONT_PROP_EXT	*gui_font_prop_ext;
	GUI_CONST_STORAGE GUI_CHARINFO_EXT *gui_charInfo_ext;
	
	xpos = gContext.DispPosX;
	ypos = gContext.DispPosY;
	
	color = gContext.Color;
	bakColor = gContext.BkColor;
	
	gui_font_prop_ext = guiFont->pProp;
	
	while(gui_font_prop_ext->pNext != (GUI_CONST_STORAGE GUI_FONT_PROP_EXT *)0)
	{
		if(c >= gui_font_prop_ext->First && c <= gui_font_prop_ext->Last)
		{
			break;
		}
		else
		{
			gui_font_prop_ext = gui_font_prop_ext->pNext;
		}
	}
	
	gui_charInfo_ext = gui_charInfo_ext + sizeof(GUI_CONST_STORAGE GUI_CHARINFO_EXT) * (c - gui_font_prop_ext->First);
	
	xpos += gui_charInfo_ext->XPos;
	ypos += gui_charInfo_ext->XPos;
	
	
	
}

const uint8_t FontMap[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01,};

void DisplayFont(int16_t x, int16_t y, GUI_CONST_STORAGE GUI_CHARINFO_EXT *charInfo)
{
	int16_t xpos, ypos;
	GUI_CONST_STORAGE unsigned char *fontData;
	uint8_t temp;
	uint16_t color;
	uint8_t bytePerLine;
	
	xpos = x + charInfo->XPos;
	ypos = y + charInfo->YPos;
	
	fontData = charInfo->pData;
	bytePerLine = (charInfo->XDist + 8) / 8;
	
	for(int16_t i = 0; i < charInfo->YSize; i++)
	{
		for(int16_t j = 0; j < charInfo->XSize; j++)
		{
			temp = fontData[i * bytePerLine + j/8];
			if((temp & FontMap[j%8]) != 0)
			{
				color = RED;
				LCD_Color_DrawPoint(xpos+j, ypos+i, color);
			}
			else
			{
				color = BLUE;
				LCD_Color_DrawPoint(xpos+j, ypos+i, color);				
			}
			
		}
	}
}

int GUIPROP_EXT_GetCharDistX(uint16_t c)
{

}	

void GUIPROP_EXT_GetFontInfo(const GUI_FONT GUI_UNI_PTR * pFont, GUI_FONTINFO* pfi)
{

}
	
char GUIPROP_EXT_IsInFont(const GUI_FONT GUI_UNI_PTR * pFont, uint16_t c)
{

}

void DisplayTest(void)
{
	
}

