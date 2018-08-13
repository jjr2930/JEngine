#pragma once
#include <d3dcompiler.h>
#include <xnamath.h>
#include "Component.h"

using Quaternion = XMVECTOR;
namespace JEngine
{
    class Transform : public Component
    {
    public:
        XMMATRIX    matrix;
        XMFLOAT3    position;
        Quaternion  rotation;
    };
}