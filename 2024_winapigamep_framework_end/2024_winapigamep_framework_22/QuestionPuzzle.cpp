#include "pch.h"
#include "InputManager.h"
#include "QuestionPuzzle.h"
#include "Collider.h"

QuestionPuzzle::QuestionPuzzle()
	: question(L"")
	, isTriggered(false)
	, answer(L"")
{
}

QuestionPuzzle::~QuestionPuzzle()
{
}

void QuestionPuzzle::Update()
{
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
	{
		isTriggered = false;
	}
}

void QuestionPuzzle::Render(HDC hdc)
{
	if (isTriggered)
	{
		//TextOutW(hdc, 0, 0, L"It is Test string", 100);
	}
}

void QuestionPuzzle::EnterCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Player")
	{
		isTriggered = true;
	}
}

void QuestionPuzzle::StayCollision(Collider* other)
{
}

void QuestionPuzzle::ExitCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Player")
	{
		isTriggered = false;
	}
}

void QuestionPuzzle::SetPuzzleQuestion(wstring question)
{
	this->question = question;
}

void QuestionPuzzle::SetPuzzleAnswer(wstring answer)
{
	this->answer = answer;
}
