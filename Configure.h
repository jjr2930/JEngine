#pragma once
#include "Pattern/Singleton.h"
#include <string>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <direct.h>

#define PARSE_VALUE(BUFFER,FIND_VALUE_NAME,SAVE_VALUE)\
sscanf(line.data(), "%s %f", &BUFFER, &fValue);\
if (0 < line.find(FIND_VALUE_NAME)) { SAVE_VALUE = fValue; }\

namespace JEngine
{
    const char FILE_NAME[] = "\\Configure.txt";
    const char FPS_NAME[] = "FPS";
    class Configure : public JEngine::Singleton<Configure>
    {
    public:
        int     GetFPS()
        {
            return __FPS__;
        }

        float   FPT()
        {
            return __TPF__;
        }
        bool    GetLoadSuccess()
        {
            return m_bLoadSuccess;
        }

    private:
        int     __FPS__  = 0;    //초당 몇 프레임인가.
        float   __TPF__  = 0.0f; //프레임당 몇초인가.     

        bool    m_bLoadSuccess = false;
    
    public:
        Configure()
        {                        
            std::string dir = _getcwd(nullptr, 0);
            //load file
            dir.append(FILE_NAME);
            std::ifstream openFile( dir.data(),std::ios::in);
            if (!openFile.is_open())
            {
                return;
            }

            std::string line;
            char buffer[100];
            while(!openFile.eof() )
            {
                std::getline(openFile, line);
                float fValue = 0.0f;
                PARSE_VALUE(buffer, FPS_NAME, __FPS__);
            }            
            openFile.close();

            OnAfterReadConfigure();

            m_bLoadSuccess = true;
        }            

        void OnAfterReadConfigure()
        {
            __TPF__ = 1.0f / (float)__FPS__;
        }
    };
}

DEFINE_SINGLETON(JEngine::Configure)