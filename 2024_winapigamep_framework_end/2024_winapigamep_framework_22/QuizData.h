#pragma once

enum class QuizEnum
{
	MOTIVE,
	MATH,
	NONSENSE
};

struct QuizDataSet
{
	wstring question;
	wstring answer;
	wstring errorMessage;
};

class QuizData
{
	std::unordered_map<QuizEnum, QuizDataSet> quizs = 
	{ 
		{QuizEnum::MOTIVE, quiz1}, 
		{QuizEnum::MATH, quiz2},
		{QuizEnum::NONSENSE, quiz3},

	};

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
};

