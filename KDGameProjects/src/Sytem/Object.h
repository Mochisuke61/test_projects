#pragma once

class Object : public std::enable_shared_from_this<Object>
{
public:
	virtual ~Object() {}
private:
	//�X�V����
	virtual void Update() {}
	//�`��O����
	virtual void Draw() {}
public:
	//�X�V����
	virtual void UpdateObject();
	//�`�揈��
	virtual void DrawObject();
};
