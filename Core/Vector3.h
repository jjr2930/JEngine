#pragma once
/*
이 클래스는 매우 자주 쓰인다.
따라서 속도를 위해 Getter와 Setter를 사용하지 않고 직접 접근하게 한다.
멤버 함수들의 컨셉은 2가지이다.
1. 인스턴스의 값을 바꾸는 함수들
2. 요청한 결과값을 갖는 새로운 인스턴스를 리턴하는 함수
   이 함수들은 Static으로 선언한다.
*/

namespace JEngine
{
    struct Vector3
    {
    public://결과값을 갖는 새로운 인스턴스를 리턴한다.
        Vector3 Add(const Vector3& rhs1, const Vector3& rhs2);      //덧셈
        Vector3 Sub(const Vector3& rhs1, const Vector3& rhs2);      //뺄셈
        Vector3 Mul(const Vector3& rhs1, const float& rhs2);      //곱셈
        Vector3 Div(const Vector3& rhs1, const float& rhs2);      //나눗셈
        float   Dot(const Vector3& rhs1, const Vector3& rhs2);      //내적은 실수를 리턴하기 때문에 이곳에서 하지 않는다.
        Vector3 Cross(const Vector3& rhs1, const Vector3& rhs2);    //외적

        //기타 유틸리티들
        static Vector3 Zero;
        static Vector3 One;
        static Vector3 Left;
        static Vector3 Right;
        static Vector3 Forward;
        static Vector3 Back;
        static Vector3 Up;
        static Vector3 Down;

    public:    //인스턴스의 값을 직접 변경하는 함수들
        Vector3();
        Vector3(const float& rhsX, const float& rhsY, const float& rhsZ);

        void Add(const Vector3& rhs);   //덧셈
        void Sub(const Vector3& rhs);   //뺄셈
        void Mul(const float& rhs);     //곱셈
        void Div(const float& rhs);     //나눗셈
        //내적은 실수를 리턴하기 때문에 이곳에서 하지 않는다.
        void Cross(const Vector3& rhs); //외적  

        //기타 유틸리티
        void ToZero();
        void ToOne();
        void Normalize();
        float GetLength();
        float GetSqrLength();

    public://멤버 변수
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        //외적에서 사용할 임시변수
        //TODO:함수에 넣어놓는게 빠른지 클래스에 넣어놓는게 빠른지 성능테스트 해볼것
        float m_tempX = 0.0f;
        float m_tempY = 0.0f;
        float m_tempZ = 0.0f;
    };
}