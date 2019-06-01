#ifndef __MENU_H
#define __MENU_H

#include "common.h"
#include "include.h"

#define BACK            12           //按键值定义，按键读取值和按键号对应
#define SET             10
#define OK              11
#define UP              2
#define DOWN            8
#define LEFT            4
#define RIGHT           6
#define DOT             10          //小数点
#define ZERO            11          //零

#define CURSOR_DIS      110         //光标横向坐标
#define SHAPE           "<--"         //光标形状


typedef struct
{
    uint16     menu_level;          //菜单层级
    uint8      *str;                //存储字符串
    void       (*fuc)(void);        //该级功能
}submenu;

typedef struct
{
    uint8               max_level;          //当前级最大界面数量
    uint8               max_deep;           //最大深度
    uint8               menu_nums;          //菜单最大数
    int8                now_deep;           //当前深度
    uint8               exe_flag;           //执行函数标志位
    uint16              current_location;   //当前位置
    const submenu*      current_menu;      //当前菜单指针
}menu_operate;

void Menu_Init(void);
void Change_Level(void);

#endif
