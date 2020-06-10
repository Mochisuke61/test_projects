#pragma once

class KdVec2;
class KdVec3;
class KdVec4;
class KdQuaternion;
class KdMatrix;

//=========================================
//
// 2D�x�N�g��
//
//=========================================
class KdVec2 : public DirectX::XMFLOAT2
{
public:
	// �R���X�g���N�^��0����
	KdVec2()
	{
		x = 0;
		y = 0;
	}
	// ���W�w��t���R���X�g���N�^
	KdVec2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	// XMVECTOR���������Ă�����
	KdVec2(const DirectX::XMVECTOR& V)
	{
		// �ϊ����đ��
		DirectX::XMStoreFloat2(this, V);
		// ���L�Ɠ��ӂ����A��L��SIMD���߂��g�p�����ق�������
//		x = V.m128_f32[0];
//		y = V.m128_f32[1];
	}
	// XMFLOAT2���������Ă�����
	KdVec2(const DirectX::XMFLOAT2& V)
	{
		x = V.x;
		y = V.y;
	}

	// XMVECTOR�֕ϊ�
	operator DirectX::XMVECTOR() const { return DirectX::XMLoadFloat2(this); }
	// Math::Vector2�ƌ݊����������߂̊֐�
	operator Math::Vector2& () { return *(Math::Vector2*)this; }

	// ���Z�q
	KdVec2& operator+= (const KdVec2& v)
	{
		*this = DirectX::XMVectorAdd(*this, v);
		return *this;
	}

	KdVec2& operator-= (const KdVec2& v)
	{
		*this = DirectX::XMVectorSubtract(*this, v);
		return *this;
	}

	KdVec2& operator*= (const KdVec2& v)
	{
		*this = DirectX::XMVectorMultiply(*this, v);
		return *this;
	}

	KdVec2& operator*= (float s)
	{
		*this = DirectX::XMVectorScale(*this, s);
		return *this;
	}

	KdVec2& operator/= (float s)
	{
		assert(s != 0.0f);
		*this = DirectX::XMVectorScale(*this, 1.f / s);
		return *this;
	}

	// �Z�b�g
	void Set(float fx, float fy)
	{
		x = fx;
		y = fy;
	}

	// ����
	float Length() const
	{
		return DirectX::XMVector2Length(*this).m128_f32[0];
	}
	// �����̂Q��(�����Ȃ̂Ŕ���p�Ɏg�p���邱�Ƃ�����)
	float LengthSquared() const
	{
		return DirectX::XMVector2LengthSq(*this).m128_f32[0];
	}

	// ����
	float Dot(const KdVec2& v) const
	{
		return DirectX::XMVector2Dot(*this, v).m128_f32[0];
	}
	// ����
	static float sDot(const KdVec2& v1, const KdVec2& v2)
	{
		return DirectX::XMVector2Dot(v1, v2).m128_f32[0];
	}

	// �O��
	KdVec2 Cross(const KdVec2& v)
	{
		return DirectX::XMVector2Cross(*this, v);
	}

	// �O��
	static KdVec2 sCross(const KdVec2& v1, KdVec2& v2)
	{
		return DirectX::XMVector2Cross(v1, v2);
	}

	// �����𐳋K��
	KdVec2& Normalize()
	{
		*this = DirectX::XMVector2Normalize(*this);
		return *this;
	}

	// �N�����v
	KdVec2& Clamp(const KdVec2& vmin, const KdVec2& vmax)
	{
		*this = DirectX::XMVectorClamp(*this, vmin, vmax);
		return *this;
	}

	// ���`���
	KdVec2& Lerp(const KdVec2& v1, const KdVec2& v2, float t)
	{
		*this = DirectX::XMVectorLerp(v1, v2, t);
		return *this;
	}

	// �X���[�Y�X�e�b�v���
	KdVec2& SmoothStep(const KdVec2& v1, const KdVec2& v2, float t)
	{
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);  // �l��0�`1�ɃN�����v
		t = t * t * (3.f - 2.f * t);
		*this = DirectX::XMVectorLerp(v1, v2, t);
		return *this;
	}

	// Catmull-Rom�X�v���C�����
	KdVec2& CatmullRom(const KdVec2& v1, const KdVec2& v2, const KdVec2& v3, const KdVec2& v4, float t)
	{
		*this = DirectX::XMVectorCatmullRom(v1, v2, v3, v4, t);
		return *this;
	}

	// �G���~�[�g�X�v���C�����
	KdVec2& Hermite(const KdVec2& v1, const KdVec2& t1, const KdVec2& v2, const KdVec2& t2, float t)
	{
		*this = DirectX::XMVectorHermite(v1, t1, v2, t2, t);
		return *this;
	}

	// �s��ŕϊ����Aw=1�ɓ��e����B
	KdVec2& TransformCoord(const DirectX::XMMATRIX& m)
	{
		*this = XMVector2TransformCoord(*this, m);
		return *this;
	}

	// (x,y,0,0)�ŕϊ�
	KdVec2& TransformNormal(const DirectX::XMMATRIX& m)
	{
		*this = XMVector2TransformNormal(*this, m);
		return *this;
	}

	// �z��
	std::vector<float> ToArray() const
	{
		return { x, y};
	}

	// float�z��̐擪�A�h���X�Ƃ��ĕԂ�
	operator const float* () const
	{
		return &x;
	}
	operator float* ()
	{
		return &x;
	}
};

//=========================================
//
// 3D�x�N�g��
//
//=========================================
class KdVec3 : public DirectX::XMFLOAT3
{
public:
	// �R���X�g���N�^��0����
	KdVec3()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	// ���W�w��t���R���X�g���N�^
	KdVec3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	// XMVECTOR���������Ă�����
	KdVec3(const DirectX::XMVECTOR& V)
	{
		// �ϊ����đ��
		DirectX::XMStoreFloat3(this, V);
		// ���L�Ɠ��ӂ����A��L��SIMD���߂��g�p�����ق�������
//		x = V.m128_f32[0];
//		y = V.m128_f32[1];
//		z = V.m128_f32[2];
	}
	// XMFLOAT3���������Ă�����
	KdVec3(const DirectX::XMFLOAT3& V)
	{
		x = V.x;
		y = V.y;
		z = V.z;
	}

	// XMVECTOR�֕ϊ�
	operator DirectX::XMVECTOR() const { return DirectX::XMLoadFloat3(this); }
	// Math::Vector3�ƌ݊����������߂̊֐�
	operator Math::Vector3&() { return *(Math::Vector3*)this; }

	// ���Z�q
	KdVec3& operator+= (const KdVec3& v)
	{
		*this = DirectX::XMVectorAdd(*this, v);
		return *this;
	}

	KdVec3& operator-= (const KdVec3& v)
	{
		*this = DirectX::XMVectorSubtract(*this, v);
		return *this;
	}

	KdVec3& operator*= (const KdVec3& v)
	{
		*this = DirectX::XMVectorMultiply(*this, v);
		return *this;
	}

	KdVec3& operator*= (float s)
	{
		*this = DirectX::XMVectorScale(*this, s);
		return *this;
	}

	KdVec3& operator/= (float s)
	{
		assert(s != 0.0f);
		*this = DirectX::XMVectorScale(*this, 1.f / s);
		return *this;
	}

	// �Z�b�g
	KdVec3& Set(float fx, float fy, float fz)
	{
		x = fx;
		y = fy;
		z = fz;
		return *this;
	}

	// �w������ɁAangle����������
	KdVec3& LookTo(const KdVec3& dir, float angle);

	// ����
	float Length() const
	{
		return DirectX::XMVector3Length(*this).m128_f32[0];
	}
	// �����̂Q��(�����Ȃ̂Ŕ���p�Ɏg�p���邱�Ƃ�����)
	float LengthSquared() const
	{
		return DirectX::XMVector3LengthSq(*this).m128_f32[0];
	}

	// ����
	float Dot(const KdVec3& v) const
	{
		return DirectX::XMVector3Dot(*this, v).m128_f32[0];
	}
	// ����
	static float sDot(const KdVec3& v1, const KdVec3& v2)
	{
		return DirectX::XMVector3Dot(v1, v2).m128_f32[0];
	}

	// �O��
	KdVec3 Cross(const KdVec3& v)
	{
		return DirectX::XMVector3Cross(*this, v);
	}

	// �O��
	static KdVec3 sCross(const KdVec3& v1, const KdVec3& v2)
	{
		return DirectX::XMVector3Cross(v1, v2);
	}

	// �����𐳋K��
	KdVec3& Normalize()
	{
		*this = DirectX::XMVector3Normalize(*this);
		return *this;
	}

	// �N�����v
	KdVec3& Clamp(const KdVec3& vmin, const KdVec3& vmax)
	{
		*this = DirectX::XMVectorClamp(*this, vmin, vmax);
		return *this;
	}

	// ���`���
	KdVec3& Lerp(const KdVec3& v1, const KdVec3& v2, float t)
	{
		*this = DirectX::XMVectorLerp(v1, v2, t);
		return *this;
	}

	// �X���[�Y�X�e�b�v���
	KdVec3& SmoothStep(const KdVec3& v1, const KdVec3& v2, float t)
	{
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);  // �l��0�`1�ɃN�����v
		t = t * t * (3.f - 2.f * t);
		*this = DirectX::XMVectorLerp(v1, v2, t);
		return *this;
	}

	// Catmull-Rom�X�v���C�����
	KdVec3& CatmullRom(const KdVec3& v1, const KdVec3& v2, const KdVec3& v3, const KdVec3& v4, float t)
	{
		*this = DirectX::XMVectorCatmullRom(v1, v2, v3, v4, t);
		return *this;
	}

	// �G���~�l�[�g�X�v���C�����
	KdVec3& Hermite(const KdVec3& v1, const KdVec3& t1, const KdVec3& v2, const KdVec3& t2, float t)
	{
		*this = DirectX::XMVectorHermite(v1, t1, v2, t2, t);
		return *this;
	}

	// �N�H�[�^�j�I���ŕϊ�
	KdVec3& Transform(const KdQuaternion& quat);

	// �s��ŕϊ����Aw=1�ɓ��e����B
	KdVec3& TransformCoord(const DirectX::XMMATRIX& m)
	{
		*this = DirectX::XMVector3TransformCoord(*this, m);
		return *this;
	}

	// (x,y,z,0)�ŕϊ�
	KdVec3& TransformNormal(const DirectX::XMMATRIX& m)
	{
		*this = DirectX::XMVector3TransformNormal(*this, m);
		return *this;
	}

	// �z��
	std::vector<float> ToArray() const
	{
		return { x, y, z };
	}
	// Vector4��
	KdVec4 ToVec4(float w);

	// float�z��̐擪�A�h���X�Ƃ��ĕԂ�
	operator const float* () const
	{
		return &x;
	}
	operator float* ()
	{
		return &x;
	}
};

//=========================================
//
// 4D�x�N�g��
//
//=========================================
class KdVec4 : public DirectX::XMFLOAT4
{
public:
	// �R���X�g���N�^��0����
	KdVec4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}
	// ���W�w��t���R���X�g���N�^
	KdVec4(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	// XMVECTOR���������Ă�����
	KdVec4(const DirectX::XMVECTOR& V)
	{
		// �ϊ����đ��
		DirectX::XMStoreFloat4(this, V);
		// ���L�Ɠ��ӂ����A��L��SIMD���߂��g�p�����ق�������
//		x = V.m128_f32[0];
//		y = V.m128_f32[1];
//		z = V.m128_f32[2];
//		w = V.m128_f32[3];
	}
	// XMFLOAT4���������Ă�����
	KdVec4(const DirectX::XMFLOAT4& V)
	{
		x = V.x;
		y = V.y;
		z = V.z;
		w = V.w;
	}

	// XMVECTOR�֕ϊ�
	operator DirectX::XMVECTOR() const { return DirectX::XMLoadFloat4(this); }
	// Math::Vector3�ƌ݊����������߂̊֐�
	operator Math::Vector4& () { return *(Math::Vector4*)this; }

	// ���Z�q
	KdVec4& operator+= (const KdVec4& v)
	{
		*this = DirectX::XMVectorAdd(*this, v);
		return *this;
	}

	KdVec4& operator-= (const KdVec4& v)
	{
		*this = DirectX::XMVectorSubtract(*this, v);
		return *this;
	}

	KdVec4& operator*= (const KdVec4& v)
	{
		*this = DirectX::XMVectorMultiply(*this, v);
		return *this;
	}

	KdVec4& operator*= (float s)
	{
		*this = DirectX::XMVectorScale(*this, s);
		return *this;
	}

	KdVec4& operator/= (float s)
	{
		assert(s != 0.0f);
		*this = DirectX::XMVectorScale(*this, 1.f / s);
	}

	// �Z�b�g
	void Set(float fx, float fy, float fz, float fw)
	{
		x = fx;
		y = fy;
		z = fz;
		w = fw;
	}

	void Set(const KdVec3& v3, float fw)
	{
		x = v3.x;
		y = v3.y;
		z = v3.z;
		w = fw;
	}

	// ����
	float Length() const
	{
		return DirectX::XMVector3Length(*this).m128_f32[0];
	}
	// �����̂Q��(�����Ȃ̂Ŕ���p�Ɏg�p���邱�Ƃ�����)
	float LengthSquared() const
	{
		return DirectX::XMVector3LengthSq(*this).m128_f32[0];
	}

	// ����
	float Dot(const KdVec4& V) const
	{
		return DirectX::XMVector4Dot(*this, V).m128_f32[0];
	}
	// ����
	static float Dot(const KdVec4& v1, const KdVec4& v2)
	{
		return DirectX::XMVector4Dot(v1, v2).m128_f32[0];
	}

	// �O��
	KdVec4 Cross(const KdVec4& v1, KdVec4& v2)
	{
		return DirectX::XMVector4Cross(*this, v1, v2);
	}

	// �O��
	static KdVec4 Cross(const KdVec4& v1, KdVec4& v2, const KdVec4& v3)
	{
		return DirectX::XMVector4Cross(v1, v2, v3);
	}

	// �����𐳋K��
	KdVec4& Normalize()
	{
		*this = DirectX::XMVector3Normalize(*this);
		return *this;
	}

	// �N�����v
	KdVec4& Clamp(const KdVec4& vmin, const KdVec4& vmax)
	{
		*this = DirectX::XMVectorClamp(*this, vmin, vmax);
		return *this;
	}

	// ���`���
	KdVec4& Lerp(const KdVec4& v1, const KdVec4& v2, float t)
	{
		*this = DirectX::XMVectorLerp(v1, v2, t);
		return *this;
	}

	// �X���[�Y�X�e�b�v���
	KdVec4& SmoothStep(const KdVec4& v1, const KdVec4& v2, float t)
	{
		t = (t > 1.0f) ? 1.0f : ((t < 0.0f) ? 0.0f : t);  // �l��0�`1�ɃN�����v
		t = t * t * (3.f - 2.f * t);
		*this = DirectX::XMVectorLerp(v1, v2, t);
		return *this;
	}

	// Catmull-Rom�X�v���C�����
	KdVec4& CatmullRom(const KdVec4& v1, const KdVec4& v2, const KdVec4& v3, const KdVec4& v4, float t)
	{
		*this = DirectX::XMVectorCatmullRom(v1, v2, v3, v4, t);
		return *this;
	}

	// �G���~�l�[�g�X�v���C�����
	KdVec4& Hermite(const KdVec4& v1, const KdVec4& t1, const KdVec4& v2, const KdVec4& t2, float t)
	{
		*this = DirectX::XMVectorHermite(v1, t1, v2, t2, t);
		return *this;
	}

	// �ϊ�
	KdVec4& Transform(const DirectX::XMMATRIX& m)
	{
		*this = DirectX::XMVector4Transform(*this, m);
		return *this;
	}

	// �z��
	std::vector<float> ToArray() const
	{
		return { x, y, z, w };
	}

	// float�z��̐擪�A�h���X�Ƃ��ĕԂ�
	operator const float* () const
	{
		return &x;
	}
	operator float* ()
	{
		return &x;
	}
};

//=========================================
//
// �N�H�[�^�j�I��
//
//=========================================
class KdQuaternion : public DirectX::XMFLOAT4
{
public:

	// �R���X�g���N�^��0����
	KdQuaternion()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 1;
	}
	// ���W�w��t���R���X�g���N�^
	KdQuaternion(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	// XMVECTOR���������Ă�����
	KdQuaternion(const DirectX::XMVECTOR& V)
	{
		// �ϊ����đ��
		DirectX::XMStoreFloat4(this, V);
	}
	// XMFLOAT3���������Ă�����
	KdQuaternion(const DirectX::XMFLOAT4& V)
	{
		x = V.x;
		y = V.y;
		z = V.z;
		w = V.w;
	}

	// XMVECTOR�֕ϊ�
	operator DirectX::XMVECTOR() const { return DirectX::XMLoadFloat4(this); }
	// Math::Quaternion�ƌ݊����������߂̊֐�
	operator Math::Quaternion& () { return *(Math::Quaternion*)this; }

	// ���Z�q
	KdQuaternion& operator*= (const KdQuaternion& q)
	{
		*this = DirectX::XMQuaternionMultiply(*this, q);
		return *this;
	}
	KdQuaternion& operator/= (const KdQuaternion& q)
	{
		*this = DirectX::XMQuaternionMultiply(*this, DirectX::XMQuaternionInverse(q));
		return *this;
	}

	//=================================
	//
	// �쐬
	//
	//=================================

	// �w�莲��]�N�H�[�^�j�I���쐬
	KdQuaternion& CreateRotationAxis(const KdVec3& axis, float angle)
	{
		*this = DirectX::XMQuaternionRotationAxis(axis, angle);
		return *this;
	}

	// x,y,z��]�p�x����N�H�[�^�j�I���쐬
	KdQuaternion& CreateRotationFromAngles(float angleX, float angleY, float angleZ)
	{
		*this = DirectX::XMQuaternionRotationRollPitchYaw(angleX, angleY, angleZ);
		return *this;
	}

	// �s�񂩂�쐬
	KdQuaternion& CreateFromMatrix(const Math::Matrix& m);

	//=================================
	//
	// ����
	//
	//=================================

	// ������
	// (���l�^)�N�H�[�^�j�I���̒������P�̏ꍇ�́A�t�N�H�[�^�j�I���Ɠ������Ȃ�
	KdQuaternion& Conjugate()
	{
		*this = DirectX::XMQuaternionConjugate(*this);
		return *this;
	}

	// �t�N�H�[�^�j�I����
	KdQuaternion& Inverse()
	{
		*this = DirectX::XMQuaternionInverse(*this);
		return *this;
	}

	// ���K��
	KdQuaternion& Normalize()
	{
		*this = DirectX::XMQuaternionNormalize(*this);
		return *this;
	}

	// ���ʐ��`���
	KdQuaternion& Slerp(const KdQuaternion& q1, const KdQuaternion& q2, float t)
	{
		*this = XMQuaternionSlerp(q1, q2, t);
		return *this;
	}

	// Z�����w������Ɍ�����
	KdQuaternion& LookTo(const KdVec3& dir, const KdVec3& up);

	//=================================
	//
	// �v���p�e�B
	//
	//=================================

	// �N�H�[�^�j�I���̑傫��
	float Length() const
	{
		return DirectX::XMQuaternionLength(*this).m128_f32[0];
	}


	// �z��
	std::vector<float> ToArray() const
	{
		return { x, y, z, w };
	}

	// X���擾
	KdVec3 Right()
	{
		return {
			1 - 2 * y * y - 2 * z * z,
			2 * x * y + 2 * w * z,
			2 * x * z - 2 * w * y
		};
	}

	// Y���擾
	KdVec3 Up()
	{
		return {
			2 * x * y - 2 * w * z,
			1 - 2 * x * x - 2 * z * z,
			2 * y * z + 2 * w * x
		};
	}

	// Z���擾
	KdVec3 Forward()
	{
		return {
			2 * x * z + 2 * w * y,
			2 * y * z - 2 * w * x,
			1 - 2 * x * x - 2 * y * y
		};
	}

	// float�z��̐擪�A�h���X�Ƃ��ĕԂ�
	operator const float* () const
	{
		return &x;
	}
	operator float* ()
	{
		return &x;
	}
};

//=========================================
//
// 4x4 �s��
//
//=========================================
class KdMatrix : public DirectX::XMFLOAT4X4
{
public:
	// �f�t�H���g�R���X�g���N�^�͒P�ʍs��
	KdMatrix()
	{
		*this = DirectX::XMMatrixIdentity();
	}

	// XMMATRIX���������Ă���
	KdMatrix(const DirectX::XMMATRIX& M)
	{
		DirectX::XMStoreFloat4x4(this, M);
	}

	// XMFLOAT4X4���������Ă���
	KdMatrix(const DirectX::XMFLOAT4X4& M)
	{
		memcpy_s(this, sizeof(float) * 16, &M, sizeof(XMFLOAT4X4));
	}

	// XMMATRIX�֕ϊ�
	operator DirectX::XMMATRIX() const
	{
		return DirectX::XMLoadFloat4x4(this);
	}
	// Math::Matrix�ƌ݊����������߂̊֐�
	operator Math::Matrix& () { return *(Math::Matrix*)this; }

	// ������Z�q
	KdMatrix& operator*= (const KdMatrix& M)
	{
		*this = DirectX::XMMatrixMultiply(*this, M);
		return *this;
	}

	//=================================
	//
	// �쐬
	//
	//=================================

	// �P�ʍs��ɂ���
	KdMatrix& CreateIdentity()
	{
		*this = DirectX::XMMatrixIdentity();
		return *this;
	}

	// �ړ��s��쐬
	KdMatrix& CreateTranslation(float x, float y, float z)
	{
		*this = DirectX::XMMatrixTranslation(x, y, z);
		return *this;
	}
	// �ړ��s��쐬
	KdMatrix& CreateTranslation(const KdVec3& pos)
	{
		*this = DirectX::XMMatrixTranslation(pos.x, pos.y, pos.z);
		return *this;
	}
	// X��]�s��쐬
	KdMatrix& CreateRotationX(float angle)
	{
		*this = DirectX::XMMatrixRotationX(angle);
		return *this;
	}
	// Y��]�s��쐬
	KdMatrix& CreateRotationY(float angle)
	{
		*this = DirectX::XMMatrixRotationY(angle);
		return *this;
	}
	// Z��]�s��쐬
	KdMatrix& CreateRotationZ(float angle)
	{
		*this = DirectX::XMMatrixRotationZ(angle);
		return *this;
	}
	// �w�莲��]�s��쐬
	KdMatrix& CreateRotationAxis(const KdVec3& axis, float angle)
	{
		*this = DirectX::XMMatrixRotationAxis(axis, angle);
		return *this;
	}
	// �N�H�[�^�j�I�������]�s��쐬
	KdMatrix& CreateFromQuaternion(const Math::Quaternion& quat)
	{
		*this = DirectX::XMMatrixRotationQuaternion(quat);
		return *this;
	}

	// �g��A��]�A���W����A�s����쐬����
	KdMatrix& CreateFromSRT(const KdVec3& scale, const KdQuaternion& rotation, const KdVec3& translation)
	{
		*this = DirectX::XMMatrixScalingFromVector(scale) * DirectX::XMMatrixRotationQuaternion(rotation) * DirectX::XMMatrixTranslationFromVector(translation);
		return *this;
	}

	// �g�k�s��쐬
	KdMatrix& CreateScaling(float x, float y, float z)
	{
		*this = DirectX::XMMatrixScaling(x, y, z);
		return *this;
	}
	KdMatrix& CreateScaling(const KdVec3& scale)
	{
		*this = DirectX::XMMatrixScaling(scale.x, scale.y, scale.z);
		return *this;
	}

	// �����e�s��쐬
	KdMatrix& CreateProjection_PerspectiveFov(float fovAngleY, float aspectRatio, float nearZ, float farZ)
	{
		*this = DirectX::XMMatrixPerspectiveFovLH(fovAngleY, aspectRatio, nearZ, farZ);
		return *this;
	}

	// ���ˉe�s��쐬
	KdMatrix& CreateProjection_Orthographic(float viewWidth, float viewHeight, float nearZ, float farZ)
	{
		*this = DirectX::XMMatrixOrthographicLH(viewWidth, viewHeight, nearZ, farZ);
		return *this;
	}


	//=================================
	//
	// ����
	//
	//=================================

	// �t�s��ɂ���
	void Inverse()
	{
		*this = DirectX::XMMatrixInverse(nullptr, *this);
	}

	// �ړ�
	KdMatrix& Move(float x, float y, float z)
	{
		_41 += x;
		_42 += y;
		_43 += z;
		return *this;
	}
	KdMatrix& Move(const KdVec3& v)
	{
		_41 += v.x;
		_42 += v.y;
		_43 += v.z;
		return *this;
	}

	// X��]
	KdMatrix& RotateX(float angle)
	{
		*this *= DirectX::XMMatrixRotationX(angle);
		return *this;
	}
	// Y��]
	KdMatrix& RotateY(float angle)
	{
		*this *= DirectX::XMMatrixRotationY(angle);
		return *this;
	}
	// Z��]
	KdMatrix& RotateZ(float angle)
	{
		*this *= DirectX::XMMatrixRotationZ(angle);
		return *this;
	}
	// �w�莲��]
	KdMatrix& RotateAxis(const KdVec3& axis, float angle)
	{
		*this *= DirectX::XMMatrixRotationAxis(axis, angle);
		return *this;
	}

	// �g�k
	KdMatrix& Scale(float x, float y, float z)
	{
		*this = DirectX::XMMatrixScaling(x, y, z);
		return *this;
	}
	KdMatrix& Scale(const KdVec3& v)
	{
		*this = DirectX::XMMatrixScaling(v.x, v.y, v.z);
		return *this;
	}

	// ����
	KdMatrix& Multiply(const KdMatrix& m)
	{
		*this *= m;
		return *this;
	}

	// Z�����w������Ɍ�����
	KdMatrix& LookTo(const KdVec3& dir, const KdVec3& up = { 0, 1, 0 })
	{
		KdVec3 vZ = dir;
		vZ.Normalize();
		KdVec3 vX = KdVec3::sCross(up, vZ).Normalize();
		KdVec3 vY = KdVec3::sCross(vZ, vX).Normalize();

		float scaleX = Right().Length();
		float scaleY = Up().Length();
		float scaleZ = Forward().Length();

		Right(vX * scaleX);
		Up(vY * scaleY);
		Forward(vZ * scaleZ);

		return *this;
	}

	// �g��𐳋K��
	KdMatrix& NormalizeScale()
	{
		KdVec3 v;
		v = Right();
		Right(v.Normalize());
		v = Up();
		Up(v.Normalize());
		v = Forward();
		Forward(v.Normalize());

		return *this;
	}


	//=================================
	//
	// �v���p�e�B
	//
	//=================================

	// X���擾
	KdVec3 Right() const { return { _11, _12, _13 }; }
	// X���Z�b�g
	void Right(const KdVec3& v)
	{
		_11 = v.x;
		_12 = v.y;
		_13 = v.z;
	}
	// Y���擾
	KdVec3 Up() const { return { _21, _22, _23 }; }
	// Y���Z�b�g
	void Up(const KdVec3& v)
	{
		_21 = v.x;
		_22 = v.y;
		_23 = v.z;
	}
	// Z���擾
	KdVec3 Forward() const { return { _31, _32, _33 }; }
	// Z���Z�b�g
	void Forward(const KdVec3& v)
	{
		_31 = v.x;
		_32 = v.y;
		_33 = v.z;
	}

	// ���W�擾
	KdVec3 Translation() const { return { _41, _42, _43 }; }
	// ���W�Z�b�g
	void Translation(const KdVec3& v)
	{
		_41 = v.x;
		_42 = v.y;
		_43 = v.z;
	}

	// �X�P�[���擾
	KdVec3 GetScale() const
	{
		return {
			Right().Length(),
			Up().Length(),
			Forward().Length()
		};
	}

	// �X�P�[�X�Z�b�g
	void SetScale(const KdVec3& v)
	{
		NormalizeScale();
		Right(Right() * v.x);
		Up(Up() * v.y);
		Forward(Forward() * v.z);
	}

	// XYZ�̏��Ԃō��������Ƃ��́A��]�p�x���Z�o����
	KdVec3 ComputeAngles() const
	{
		KdMatrix mat = *this;
		mat.NormalizeScale();

		KdVec3 angles;
		angles.x = atan2f(mat.m[1][2], mat.m[2][2]);
		angles.y = atan2f(-mat.m[0][2], sqrtf(mat.m[1][2] * mat.m[1][2] + mat.m[2][2] * mat.m[2][2]));
		angles.z = atan2f(mat.m[0][1], mat.m[0][0]);
		return angles;
	}

	// �s����A�g��A��]�A���W�֕�������
	bool Decompose(KdVec3& scale, KdQuaternion& rotation, KdVec3& translation) const
	{
		DirectX::XMVECTOR s, r, t;

		if (!DirectX::XMMatrixDecompose(&s, &r, &t, *this))
		{
			return false;
		}

		scale = s;
		rotation = r;
		translation = t;
		return true;
	}

	// �z��
	std::vector<float> ToArray() const
	{
		return {	_11, _12, _13, _14,
					_21, _22, _23, _24,
					_31, _32, _33, _34,
					_41, _42, _43, _44
				};
	}

	// float�z��̐擪�A�h���X�Ƃ��ĕԂ�
	operator const float* () const
	{
		return &_11;
	}
	operator float* ()
	{
		return &_11;
	}
};

#include "KdMath.inl"
