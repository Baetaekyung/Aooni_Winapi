#pragma once
#include "Object.h"
class QuestionPuzzle
	: Object
{
private:
	QuestionPuzzle();
	~QuestionPuzzle();
public:
	void Update() override;
	void Render(HDC hdc) override;
public:
	virtual void EnterCollision(Collider* other);
	virtual void StayCollision(Collider* other);
	virtual void ExitCollision(Collider* other);
public:
	void SetPuzzleQuestion(wstring question);
	void SetPuzzleAnswer(wstring answer);
private:
	bool isTriggered;
private:
	wstring question;
	wstring answer;
};

