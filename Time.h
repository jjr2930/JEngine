#pragma once
#include "Pattern/Singleton.h"
#include <ctime>
namespace JEngine
{
    class Time : public Singleton<Time>
    {
    public:
        Time()
            : startTime(clock())
            , deltaTime(0.0f)
            , elapsedTime(0.0f)
            , timeScale(1.0f)
            , unscaledLastFrameTime(startTime)
            , unscaledDeltaTime(0.0f)
            , unscaledElapsedTime(0.0f)
            , unscaledCurrentTime(0.0f)
        {         
        }
        void CalcTimes()
        {
            //unscaled time
            unscaledLastFrameTime = unscaledCurrentTime;
            unscaledCurrentTime = clock();
            unscaledDeltaTime = unscaledCurrentTime - unscaledLastFrameTime;
            unscaledElapsedTime += unscaledDeltaTime;
            //scaled time
            deltaTime = unscaledDeltaTime * timeScale;
            elapsedTime += deltaTime;
        }

        //-------------------------------
        //setter
        //-------------------------------
        void SetTimeScale(const double& value)
        {
            timeScale = value;
        }
        //--------------------------------
        //getter
        //--------------------------------
        double GetDeltaTime()
        {
            return deltaTime;
        }
        double GetElapsedTime()
        {
            return elapsedTime;
        }
        double GetTimeScale()
        {
            return timeScale;
        }
        double GetUnscaledDeltaTime()
        {
            return unscaledDeltaTime;
        }
        double GetUnscaledElapsedTime()
        {
            return unscaledElapsedTime;
        }
        double GetUnscaledCurrentTime()
        {
            return unscaledCurrentTime;
        }


    private :
        double deltaTime = 0.0f;
        double elapsedTime = 0.0f;
        double timeScale = 1.0f;
        double startTime = 0.0;
        double unscaledLastFrameTime = 0.0f;
        double unscaledDeltaTime = 0.0f;
        double unscaledElapsedTime = 0.0f;
        double unscaledCurrentTime = 0.0f;
    };
}

DEFINE_SINGLETON(JEngine::Time)