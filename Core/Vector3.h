#pragma once
/*
�� Ŭ������ �ſ� ���� ���δ�.
���� �ӵ��� ���� Getter�� Setter�� ������� �ʰ� ���� �����ϰ� �Ѵ�.
��� �Լ����� ������ 2�����̴�.
1. �ν��Ͻ��� ���� �ٲٴ� �Լ���
2. ��û�� ������� ���� ���ο� �ν��Ͻ��� �����ϴ� �Լ�
   �� �Լ����� Static���� �����Ѵ�.
*/

namespace JEngine
{
    struct Vector3
    {
    public://������� ���� ���ο� �ν��Ͻ��� �����Ѵ�.
        Vector3 Add(const Vector3& rhs1, const Vector3& rhs2);      //����
        Vector3 Sub(const Vector3& rhs1, const Vector3& rhs2);      //����
        Vector3 Mul(const Vector3& rhs1, const float& rhs2);      //����
        Vector3 Div(const Vector3& rhs1, const float& rhs2);      //������
        float   Dot(const Vector3& rhs1, const Vector3& rhs2);      //������ �Ǽ��� �����ϱ� ������ �̰����� ���� �ʴ´�.
        Vector3 Cross(const Vector3& rhs1, const Vector3& rhs2);    //����

        //��Ÿ ��ƿ��Ƽ��
        static Vector3 Zero;
        static Vector3 One;
        static Vector3 Left;
        static Vector3 Right;
        static Vector3 Forward;
        static Vector3 Back;
        static Vector3 Up;
        static Vector3 Down;

    public:    //�ν��Ͻ��� ���� ���� �����ϴ� �Լ���
        Vector3();
        Vector3(const float& rhsX, const float& rhsY, const float& rhsZ);

        void Add(const Vector3& rhs);   //����
        void Sub(const Vector3& rhs);   //����
        void Mul(const float& rhs);     //����
        void Div(const float& rhs);     //������
        //������ �Ǽ��� �����ϱ� ������ �̰����� ���� �ʴ´�.
        void Cross(const Vector3& rhs); //����  

        //��Ÿ ��ƿ��Ƽ
        void ToZero();
        void ToOne();
        void Normalize();
        float GetLength();
        float GetSqrLength();

    public://��� ����
        float x = 0.0f;
        float y = 0.0f;
        float z = 0.0f;
        //�������� ����� �ӽú���
        //TODO:�Լ��� �־���°� ������ Ŭ������ �־���°� ������ �����׽�Ʈ �غ���
        float m_tempX = 0.0f;
        float m_tempY = 0.0f;
        float m_tempZ = 0.0f;
    };
}