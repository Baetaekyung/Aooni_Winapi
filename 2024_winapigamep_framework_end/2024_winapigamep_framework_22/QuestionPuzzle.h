#pragma once
#include "Object.h"
class Player;
class QuestionPuzzle
	: public Object
{
public:
	QuestionPuzzle();
	~QuestionPuzzle();
public:
	void Update() override;
	void Render(HDC hdc) override;
public:
	virtual void EnterCollision(Collider* other);
	virtual void ExitCollision(Collider* other);
public:
	void SetPuzzleQuestion(wstring question);
	void SetPuzzleAnswer(wstring answer);
	void SetErrorMessage(wstring errorMsg);
private:
	bool isTriggered;
	bool isDrawed;
	bool isAnswerCheck;
private:
	wstring question;
	wstring answer;
	wstring errorMessage;
	Player* player;
	wchar_t playerAnswer[30];
	int currentLen;
	int currentChecked;
};

