#include "Vector3.h"
#include "Log.h"
#include <cmath>
JEngine::Vector3 JEngine::Vector3::Add(const Vector3 & rhs1, const Vector3 & rhs2)
{
    return Vector3(rhs1.x + rhs2.x, rhs1.y + rhs2.y, rhs1.z + rhs2.z);
}

JEngine::Vector3 JEngine::Vector3::Sub(const Vector3 & rhs1, const Vector3 & rhs2)
{
    return Vector3(rhs1.x - rhs2.x, rhs1.y - rhs2.y, rhs1.z - rhs2.z);
}

JEngine::Vector3 JEngine::Vector3::Mul(const Vector3 & rhs1, const float & rhs2)
{
    return Vector3(rhs1.x * rhs2, rhs1.y * rhs2, rhs1.z * rhs2);
}

JEngine::Vector3 JEngine::Vector3::Div(const Vector3 & rhs1, const float & rhs2)
{
    if (0.0f == rhs2)
    {
        LOG(L"Can not divided by zero");
        return Vector3(0.0f, 0.0f, 0.0f);
    }
    return Vector3(rhs1.x / rhs2, rhs1.y / rhs2, rhs1.z / rhs2);
}

float JEngine::Vector3::Dot(const Vector3 & rhs1, const Vector3 & rhs2)
{
    return (rhs1.x * rhs2.x + rhs1.y * rhs2.y + rhs1.z * rhs2.z);
}

JEngine::Vector3 JEngine::Vector3::Cross(const Vector3 & rhs1, const Vector3 & rhs2)
{
    return Vector3( rhs1.y * rhs2.z - rhs1.z * rhs2.y,
                    rhs1.z * rhs2.x - rhs1.x * rhs2.z,
                    rhs1.x * rhs2.y - rhs1.y * rhs2.x);
}


JEngine::Vector3::Vector3()
{
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
}

JEngine::Vector3::Vector3(const float & rhsX, const float & rhsY, const float & rhsZ)
    :x(rhsX),y(rhsY),z(rhsZ)
{
}

void JEngine::Vector3::Add(const Vector3 & rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
}

void JEngine::Vector3::Sub(const Vector3 & rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
}

void JEngine::Vector3::Mul(const float & rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
}

void JEngine::Vector3::Div(const float & rhs)
{
    if (0.0f == rhs)
    {
        LOG(L"Can not divided by zero");
        return;
    }

    x /= rhs;
    y /= rhs;
    z /= rhs;
}

void JEngine::Vector3::Cross(const Vector3 & rhs)
{
    m_tempX = x;
    m_tempY = y;
    m_tempZ = z;
    x = m_tempY * rhs.z - m_tempZ * rhs.y;
    y = m_tempZ * rhs.x - m_tempX * rhs.z;
    z = m_tempX * rhs.y - m_tempY * rhs.x;
}

void JEngine::Vector3::ToZero()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

void JEngine::Vector3::ToOne()
{
    x = 1.0f;
    y = 1.0f;
    z = 1.0f;
}

void JEngine::Vector3::Normalize()
{
    float fLength = GetLength();
    x /= fLength;
    y /= fLength;
    z /= fLength;
}

float JEngine::Vector3::GetLength()
{
    //최대한의 고속 연산을 위해 GetSqrLength함수를 호출하지 않는다.
    return sqrt(x * x + y * y + z * z);
}

float JEngine::Vector3::GetSqrLength()
{
    return x * x + y * y + z * z;
}

JEngine::Vector3 JEngine::Vector3::Zero     = { 0.0f, 0.0f, 0.0f };
JEngine::Vector3 JEngine::Vector3::One      = { 1.0f, 1.0f, 1.0f };
JEngine::Vector3 JEngine::Vector3::Left     = { -1.0f, 0.0f, 0.0f };
JEngine::Vector3 JEngine::Vector3::Right    = { 1.0f, 0.0f, 0.0f };
JEngine::Vector3 JEngine::Vector3::Forward  = { 0.0f, 0.0f, 1.0f };
JEngine::Vector3 JEngine::Vector3::Back     = { 0.0f, 0.0f, -1.0f };
JEngine::Vector3 JEngine::Vector3::Up       = { 0.0f, 1.0f, 0.0f };
JEngine::Vector3 JEngine::Vector3::Down     = { 0.0f, -1.0f, 0.0f };