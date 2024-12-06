#pragma once

enum class QuizEnum
{
	MOTIVE,
	MATH,
	NONSENSE,
	NONSENSE2,
	NONSENSE3
};

struct QuizDataSet
{
	wstring question;
	wstring answer;
	wstring errorMessage;
};

class QuizData
{
public:
	QuizData();
	~QuizData();
public:
	std::unordered_map<QuizEnum, QuizDataSet> quizs;
private:
	QuizDataSet quiz1 = {
		L"우리가 모티브 한 게임은? (영어로 답하시오)",
		L"aooni", 
		L"답은 aooni입니다.." 
	};
	QuizDataSet quiz2 = {
		L"극한의 기호를 작성하시오..",
		L"lim",
		L"정답은 lim입니당 ㅎㅎ"
	};
	QuizDataSet quiz3 = {
		L"세상에서 가장 쉬운 숫자는?",
		L"190000",
		L"쉽구만.."
	};
	QuizDataSet quiz4 = {
		L"말고기를 먹으면 입이 시원해지는 이유는? (조유성 제공)",
		L"horse",
		L"Halls(입이 시원해지는 사탕)이기 때문..(조유성 피셜)"
	};
	QuizDataSet quiz5 = {
		L"아몬드가 죽으면?!?!?",
		L"diamond",
		L"다이아몬드 입니다 ㅎㅎ"
	};
};