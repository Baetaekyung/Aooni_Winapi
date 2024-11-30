#include "pch.h"
#include "Object.h"
#include "InputManager.h"
#include "QuestionPuzzle.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Collider.h"
#include "Key.h"
#include "Player.h"
#include "EventManager.h"

QuestionPuzzle::QuestionPuzzle()
	: question(L"")
	, isTriggered(false)
	, answer(L"")
	, isDrawed(false)
	, playerAnswer()
	, currentLen(0)
	, player(nullptr)
	, currentChecked(3)
	, isAnswerCheck(false)
{
	SetSize({ 50, 50 });
	this->AddComponent<Collider>();
	GetComponent<Collider>()->SetSize(GetSize());
}

QuestionPuzzle::~QuestionPuzzle()
{
}

void QuestionPuzzle::Update()
{

	//Input check
	if (isTriggered)
	{
		if (GetAsyncKeyState(VK_BACK))
		{
			playerAnswer[0] = NULL;
			currentLen = 0;
		}
		if (GET_KEYDOWN(KEY_TYPE::Q))
		{
			playerAnswer[currentLen++] = 'q';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::W))
		{
			playerAnswer[currentLen++] = 'w';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::E))
		{
			playerAnswer[currentLen++] = 'e';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::R))
		{
			playerAnswer[currentLen++] = 'r';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::T))
		{
			playerAnswer[currentLen++] = 't';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::Y))
		{
			playerAnswer[currentLen++] = 'y';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::U))
		{
			playerAnswer[currentLen++] = 'u';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::I))
		{
			playerAnswer[currentLen++] = 'i';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::O))
		{
			playerAnswer[currentLen++] = 'o';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::P))
		{
			playerAnswer[currentLen++] = 'p';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::A))
		{
			playerAnswer[currentLen++] = 'a';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::S))
		{
			playerAnswer[currentLen++] = 's';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::D))
		{
			playerAnswer[currentLen++] = 'd';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::F))
		{
			playerAnswer[currentLen++] = 'f';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::G))
		{
			playerAnswer[currentLen++] = 'g';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::H))
		{
			playerAnswer[currentLen++] = 'h';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::J))
		{
			playerAnswer[currentLen++] = 'j';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::K))
		{
			playerAnswer[currentLen++] = 'k';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::L))
		{
			playerAnswer[currentLen++] = 'l';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::Z))
		{
			playerAnswer[currentLen++] = 'z';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::X))
		{
			playerAnswer[currentLen++] = 'x';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::C))
		{
			playerAnswer[currentLen++] = 'c';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::V))
		{
			playerAnswer[currentLen++] = 'v';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::B))
		{
			playerAnswer[currentLen++] = 'b';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::N))
		{
			playerAnswer[currentLen++] = 'n';
			playerAnswer[currentLen] = NULL;
		}
		if (GET_KEYDOWN(KEY_TYPE::M))
		{
			playerAnswer[currentLen++] = 'm';
			playerAnswer[currentLen] = NULL;
		}
	}

	if (isAnswerCheck)
	{
		if (GET_KEYDOWN(KEY_TYPE::ENTER))
		{
			question = answer + L" " + errorMessage;
		}
	}
	if (GET_KEYDOWN(KEY_TYPE::ENTER))
	{
		if (isTriggered) 
		{
			if (playerAnswer == answer)
			{
				cout << "answer!";
				if (player != nullptr)
				{
					player->SetMove(true);
					Vec2 playerNextPos{ player->GetPos().x,
						player->GetPos().y + GetSize().y };
					player->SetPos(playerNextPos);
					GET_SINGLE(EventManager)->DeleteObject(this);
				}
				Key* key = new Key;
				key->SetPos(GetPos());
				key->SetName(L"Key");
				GET_SINGLE(SceneManager)->GetCurrentScene()->AddObject(key, LAYER::INTERACTABLE);
			}
			else
			{
				if (player != nullptr)
				{
					player->SetMove(true);
					Vec2 playerNextPos{ player->GetPos().x,
						player->GetPos().y + GetSize().y };
					player->SetPos(playerNextPos);
					currentChecked--;
				}
			}

			playerAnswer[0] = NULL;
			currentLen = 0;
		}
		isDrawed = false;
		isTriggered = false;
	}
}

void QuestionPuzzle::Render(HDC hdc)
{
	RECT drawRect;
	RECT errorRect;
	RECT answerTextRect;
	SetRect(&drawRect, 0, 0, 300, 100);
	SetRect(&answerTextRect, 0, 300, 100, 400);
	if(isTriggered)
	{
		DrawText(hdc, question.c_str(),
			-1, &drawRect, DT_WORDBREAK);
		DrawText(hdc, playerAnswer, -1,
			&answerTextRect, DT_CENTER);
		isDrawed = true;
	}
	ComponentRender(hdc);
}

void QuestionPuzzle::EnterCollision(Collider* other)
{
	if (isDrawed) return;

	if (other->GetOwner()->GetName() == L"Player")
	{
		if (currentChecked == 0)
		{
			isAnswerCheck = true;
			question = L"Enter to check answer!";
		}

		cout << "trigger!";
		player = dynamic_cast<Player*>(other->GetOwner());
		player->SetMove(false);
		
		isTriggered = true;
	}
}

void QuestionPuzzle::ExitCollision(Collider* other)
{
	if (other->GetOwner()->GetName() == L"Player")
	{
		playerAnswer[0] = NULL;
		
		isDrawed = false;
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

void QuestionPuzzle::SetErrorMessage(wstring errorMsg)
{
	this->errorMessage = errorMsg;
}
