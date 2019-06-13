/*
 * math function for dx12
 */
#if __DIRECTX_12__
#pragma once

#include <DirectXMath.h>

#define _MTRX_4X4_ADD_MTRX_4X4_(MTRX1,MTRX2)			MTRX1 + MTRX2
#define _MTRX_4X4_SUB_MTRX_4X4_(MTRX1,MTRX2)			MTRX1 - MTRX2
#define _MTRX_4X4_MUL_MTRX_4X4_(MTRX1,MTRX2)			MTRX1 * MTRX2
#define _MTRX_4X4_MUL_FLOAT_(MTRX,FLOAT)				MTRX * FLOAT
#define _MTRX_4X4_DIV_FLOAT_(MTRX,FLOAT)				MTRX / FLOAT
#define _MTRX_4X4_MUL_V4(MATRX_4X4,VECTOR4)				DirectX::XMVector4Transform(VECTOR4, MATRX_4X4)

/*
* for VECTOR4
*/
#define _VECTOR4_NORMALIZE_(VECTOR4)					DirectX::XMVector4Normalized(VECTOR4)
#define _VECTOR4_LENGTH_(VECTOR4)						DirectX::XMVector4Length(VECTOR4)
#define _VECTOR4_DOT_(VECTOR4_1, VECTOR4_2)				DirectX::XMVector4Dot(VECTOR4_1, VECTOR4_2)
#define _VECTOR4_CROSS_(VECTOR4_1, VECTOR4_2)			DirectX::XMVector4Cross(VECTOR4_1, VECTOR4_2)

/*
* for VECTOR3
*/
#define _VECTOR3_NORMALIZE_(VECTOR3)					DirectX::XMVector3Normalized(VECTOR3)
#define _VECTOR3_LENTH_(VECTOR3)						DirectX::XMVector3Length(VECTOR3)
#define _VECTOR3_DOT_(VECTOR3_1, VECTOR3_2)				DirectX::XMVector3Dot(VECTOR3_1,VECTOR3_2 )
#define _VECTOR3_CROSS_(VECTOR3_1, VECTOR3_2)			DirectX::XMVector3Cross(VECTOR3_1, VECTOR3_2)
#endif
