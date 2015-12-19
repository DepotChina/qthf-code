/************************************************************************************************
*   This file is part of the ZhenHai project						                         
*   Copyright (C) 2010 by ZhenHai                                                        
*                                                                                                             
*   This library is free software; you can redistribute it and/or modify      
*   it under the terms of the GNU Lesser General Public License as          
*   published by the Free Software Foundation; either version 2.1 of       
*   the License, or (at your option) any later version.                                 
*                                                                                                            
*   This library is distributed in the hope that it will be useful,                   
*   but WITHOUT ANY WARRANTY; without even the implied warranty of      
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     
*   Lesser General Public License for more details.                      
*                                                                        
*   You should have received a copy of the GNU Le Seer General Public  
*   License along with this library; if not, write to                    
*   the Free Software Foundation, Inc.,                                 
*   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA       

*   filename : main.cpp                                               
*   the role of document : main                                          
*   author : ZhangNeng                                                    
*   creation time : 2011.02.23                                          
*   modification time : 2011.03.09                                    
***************************************************************************************************/
#include "qa_coordinates.h"


char (*p_answer)[1024] = NULL;
char (*p_qustion)[1024] = NULL;
char (*p_g_keyword)[3][1024] = NULL;

char g_answer[10][1024] = {"这个答案很正确啊！"};
char g_qustion[10][1024] = {"今天东海的温度是几度？！"};
char g_keyword[10][3][1024] = {"今天", "温度", "几度"};

int g_coordinates[10][2] = {{50, 50}, {70, 70}, {90, 90}, {100, 100}, {120, 120}, {130, 130}, {700, 150}};

